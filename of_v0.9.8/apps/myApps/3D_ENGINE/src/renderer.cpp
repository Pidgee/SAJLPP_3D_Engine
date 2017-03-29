#include "renderer.h"
#include <string>


Renderer::Renderer():cameraObject(new CameraObject()), drawingToolActivated(false), lineCursorActivated(false), triangleCursorActivated(false), circleCursorActivated(false) {
	cameraObject->setup();
}


void Renderer::setup()
{
	fbo.allocate(1280, 720);
	fbo.begin();
	
	for (unsigned int i = 0; i<geometryObjectContainer.size(); i++) {
		geometryObjectContainer[i]->setup();
	}
	ofClear(255, 255, 255);
	ofBackgroundGradient(ofColor(119, 136, 153), ofColor(105, 105, 105));
	ajouterLumiere(ofColor(100, 100, 100));
	ajouterLumiere(0, ofVec3f(0, 0, 300), ofColor(255, 0, 0)); //point
	ajouterLumiere(1, ofVec3f(45, 45, 0), ofColor(0, 255, 0)); //direction
	ajouterLumiere(ofVec3f(0, 300, 0), ofVec3f(0, 0, 0), ofColor(0, 0, 255)); //spot
	fbo.end();
	
}

void Renderer::update(){
	cameraObject->update();
}

void Renderer::ajouterLumiere(ofColor couleur) {
	ofSetGlobalAmbientColor(couleur);
	ofSetSmoothLighting(true);
}

void Renderer::ajouterLumiere(int type, ofVec3f vecteur, ofColor couleur) {
	ofLight lumiere;
	if (type == 0) {
		lumiere.setPointLight();
		lumiere.setPosition(vecteur);
		lumiere.setDiffuseColor(couleur);
	}
	else if (type == 1) {
		lumiere.setDirectional();
		lumiere.setOrientation(vecteur);
		lumiere.setDiffuseColor(couleur);
	}
	lumiereContainer.push_back(lumiere);
}

void Renderer::ajouterLumiere(ofVec3f position, ofVec3f direction, ofColor couleur) {
	ofLight lumiere;
	lumiere.setSpotlight();
	lumiere.setPosition(position);
	lumiere.lookAt(direction);
	lumiere.setDiffuseColor(couleur);
	lumiereContainer.push_back(lumiere);
}

void Renderer::draw()
{
	if (!drawingToolActivated) {
		/*fbo.begin();
		ofEnableDepthTest();
		ofClear(255, 255, 255);
		ofBackground(255, 255, 255);
		cam.begin();
		for (int i = 0; i<geometryObjectContainer.size(); i++) {
			geometryObjectContainer[i]->draw();
		}
		cam.end();
		ofDisableDepthTest();
		fbo.end();
		fbo.draw(160, 90);
		*/
		fbo.begin();
		ofEnableDepthTest();
		ofClear(255, 255, 255);
		ofBackgroundGradient(ofColor(119, 136, 153), ofColor(105, 105, 105));
		//data.lightType = OF_LIGHT_DIRECTIONAL;
		//data.direction = ofVec3f(0, 1, 0);
		//lumiere.setup();
		//lumiere.setDirectional();
		//ofSetGlobalAmbientColor(ofColor(255, 255, 255));
		//lumiere.setAmbientColor(ofColor(150,100,200));
		//lumiere.setSpotlightCutOff(50);
		//lumiere.setOrientation();
		//lumiere.setAmbientColor(ofColor(150, 100, 200));
		//lumiere.setDiffuseColor(ofColor(200, 200, 150));
		//lumiere.setAreaLight(100,100);
		for (int i = 0; i<lumiereContainer.size(); i++) {
			lumiereContainer[i].enable();
		}
		cameraObject->cam.begin();
		for (int i = 0; i<geometryObjectContainer.size(); i++) {
			geometryObjectContainer[i]->draw();
		}
		cameraObject->cam.end();
		for (int i = 0; i<lumiereContainer.size(); i++) {
			lumiereContainer[i].disable();
		}
		ofDisableDepthTest();
		fbo.end();
		fbo.draw(160, 90);

	}
	else if (drawingToolActivated) {
		drawing->draw();
		if (lineCursorActivated) {
			drawing->drawLineCursor(xMouseCurrent, yMouseCurrent);
		}
		else if (triangleCursorActivated) {
			drawing->drawTriangleCursor(xMouseCurrent, yMouseCurrent);
		}
		else if (circleCursorActivated) {
			drawing->drawCircleCursor(xMouseCurrent, yMouseCurrent);
		}
	}

}

ofVec3f convertionRGB_HSV(ofColor couleur) {

	ofVec3f hsv;

	float val_r = couleur.r / 255;
	float val_g = couleur.g / 255;
	float val_b = couleur.b / 255;

	float maximum1 = max(val_r, val_g);
	float maximum = max(maximum1, val_b);
	float minimum1 = min(val_r, val_g);
	float minimum = min(minimum1, val_b);

	float delta = maximum - minimum;

	//Détermine le hue.
	if (delta == 0) {
		hsv[0] = 0;
	}
	else if (maximum == val_r) {
		float diff = val_g - val_b;
		int div = diff / delta;
		int resultat = div % 6;
		hsv[0] = resultat;
	}
	else if (maximum == val_g) {
		float diff = val_b - val_r;
		float div = diff / delta;
		float resultat = div + 2;
		hsv[0] = resultat;
	}
	else if (maximum == val_b) {
		float diff = val_r - val_g;
		float div = diff / delta;
		float resultat = div + 4;
		hsv[0] = resultat;
	}

	//Détermine la saturation.
	if (maximum == 0) {
		hsv[1] = 0;
	}
	else {
		hsv[1] = delta / maximum;
	}
	//Détermine la value.
	hsv[2] = maximum;
	return hsv;
}

void Renderer::exporter()
{
	ofFileDialogResult resultat = ofSystemSaveDialog("image.png", "Sauvegarde de l'image");
	string nom = resultat.fileName;

	if (resultat.bSuccess) {
		ofImage image;
		ofTexture texture = fbo.getTexture();
		image.allocate(1280, 720, OF_IMAGE_COLOR);
		image.grabScreen(160, 90, texture.getWidth(), texture.getHeight());
		image.save(nom + ".png", OF_IMAGE_QUALITY_BEST);
	}
}

void Renderer::renderImage(ofImage * image, string nom, int x, int y, int z) {

	imageObjet* im = new imageObjet;
	im->setup();

	ofImage temp = *image;
	im->setImage(image);
	im->p1.set(x - (temp.getWidth() / 2), y - (temp.getHeight() / 2), z);
	im->p2.set(x - (temp.getWidth() / 2), y + (temp.getHeight() / 2), z);
	im->p3.set(x + (temp.getWidth() / 2), y - (temp.getHeight() / 2), z);
	im->p4.set(x + (temp.getWidth() / 2), y + (temp.getHeight() / 2), z);
	im->nom = nom;
	geometryObjectContainer.push_back(im);

}

void Renderer::renderImage(ofImage * image, string nom, int x, int y, int z, ofColor couleur) {

	imageObjet* im = new imageObjet;
	imageObjet* image_teinte = new imageObjet;
	im->setImage(image);

	ofImage teinte = im->ajouter_teinte(couleur);
	image_teinte->setup();
	image_teinte->setImage(&teinte);

	ofImage temp = *image;
	image_teinte->p1.set(x - (temp.getWidth() / 2), y - (temp.getHeight() / 2), z);
	image_teinte->p2.set(x - (temp.getWidth() / 2), y + (temp.getHeight() / 2), z);
	image_teinte->p3.set(x + (temp.getWidth() / 2), y - (temp.getHeight() / 2), z);
	image_teinte->p4.set(x + (temp.getWidth() / 2), y + (temp.getHeight() / 2), z);
	image_teinte->nom = nom;
	geometryObjectContainer.push_back(image_teinte);

}

void Renderer::renderImage(ofImage * image, string nom, int x, int y, int z, ofImage *image1) {

	imageObjet* im = new imageObjet;
	imageObjet* image_compose = new imageObjet;
	im->setImage(image);

	ofImage compose = im->ajouter_image(image1);
	image_compose->setup();
	image_compose->setImage(&compose);

	ofImage temp = *image;
	image_compose->p1.set(x - (temp.getWidth() / 2), y - (temp.getHeight() / 2), z);
	image_compose->p2.set(x - (temp.getWidth() / 2), y + (temp.getHeight() / 2), z);
	image_compose->p3.set(x + (temp.getWidth() / 2), y - (temp.getHeight() / 2), z);
	image_compose->p4.set(x + (temp.getWidth() / 2), y + (temp.getHeight() / 2), z);
	image_compose->nom = nom;
	geometryObjectContainer.push_back(image_compose);

}

/*ParticleCloud* Renderer::renderParticleCloud() {
}*/

void Renderer::renderDrawing() {
	drawing = new Drawing();
	drawing->setup();
	drawingToolActivated = true;
}


void Renderer::drawLine(float x1, float y1, float x2, float y2) {
	drawing->drawLine(x1, y1, x2, y2);
}

void Renderer::drawTriangle(float x1, float y1, float x2, float y2, float x3, float y3) {
	drawing->drawTriangle(x1, y1, x2, y2, x3, y3);
}

void Renderer::drawCircle(float x1, float y1, float x2, float y2) {
	drawing->drawCircle(x1, y1, x2, y2);
}

void Renderer::saveDrawing() {
	geometryObjectContainer.push_back(drawing);
	drawingToolActivated = false;
}

//Géométrie
void Renderer::renderParticleCloud() {
	ParticleCloud* part = new ParticleCloud;
	part->setup();
	geometryObjectContainer.push_back(part);
}

void Renderer::renderSphere()
{
	GeometryPrimitive* sphere = new GeometryPrimitive("sphere");
	sphere->setup();
	geometryObjectContainer.push_back(sphere);
}

void Renderer::renderCube()
{
	GeometryPrimitive* cube = new GeometryPrimitive("cube");
	cube->setup();
	geometryObjectContainer.push_back(cube);
}

void Renderer::renderCylinder()
{
	GeometryPrimitive* cylinder = new GeometryPrimitive("cylinder");
	cylinder->setup();
	geometryObjectContainer.push_back(cylinder);
}

void Renderer::renderCone()
{
	GeometryPrimitive* cone = new GeometryPrimitive("cone");
	cone->setup();
	geometryObjectContainer.push_back(cone);
}

void Renderer::renderModel(string path, string name)
{
	ImportModel* model = new ImportModel(path, name);
	model->setup();
	geometryObjectContainer.push_back(model);
}

void Renderer::renderProcedural(string path, string name)
{
	ProceduralGeometry* procedural = new ProceduralGeometry(path, name);
	procedural->setup();
	geometryObjectContainer.push_back(procedural);
}

void Renderer::renderTransformation(float rotX, float rotY, float rotZ, float transX, float transY, float transZ, float scale) {
	for(int i=0; i<geometryObjectContainer.size(); i++){
		if(geometryObjectContainer[i]->getSelected()){
			geometryObjectContainer[i]->rotateX(rotX);
			geometryObjectContainer[i]->rotateY(rotY);
			geometryObjectContainer[i]->rotateZ(rotZ);
			geometryObjectContainer[i]->translateX(transX);
			geometryObjectContainer[i]->translateY(transY);
			geometryObjectContainer[i]->translateZ(transZ);
			geometryObjectContainer[i]->scale(scale/100);
		}
	}
}


std::vector<GeometryObject*>* Renderer::getObjects() {
	return &geometryObjectContainer;
}

int Renderer::getNumberOfObjects() {
	return geometryObjectContainer.size();
}


CameraObject* Renderer::getCamera() {
	return cameraObject;
}

Renderer::~Renderer(){
}
