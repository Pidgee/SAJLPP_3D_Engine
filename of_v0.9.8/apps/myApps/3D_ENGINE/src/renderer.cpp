#include "renderer.h"
#include <string>


Renderer::Renderer(): drawingToolActivated(false), lineCursorActivated(false), triangleCursorActivated(false), circleCursorActivated(false),
materialsEnabled(true), colorShaderEnabled(false), displacementShaderEnabled(false) {
}



void Renderer::setup()
{

#ifdef TARGET_OPENGLES
	simpleColorShader.load("shaders/shadersesl/sinShader");
	displacementShader.load("shaders/shadersesl/disShader");

#else
	if(ofIsGLProgrammableRenderer()){
		simpleColorShader.load("shaders/shaders150/sinShader");
		displacementShader.load("shaders/shaders150/disShader");
	}else{
		simpleColorShader.load("shaders/shaders120/sinShader");
		displacementShader.load("shaders/shaders120/disShader");
		blurShader_1.load("shaders/shaders120/blurShader_1");
		blurShader_2.load("shaders/shaders120/blurShader_2");


	}
#endif


	fbo.allocate(1200, 720);
	fbo.begin();
	
	for (unsigned int i = 0; i<geometryObjectContainer.size(); i++) {
		geometryObjectContainer[i]->setup();
	}
	ofClear(255, 255, 255);
	ofEnableLighting();
	ofSetGlobalAmbientColor(ofColor(255,255,255));
	ofSetSmoothLighting(true);
	ofBackgroundGradient(ofColor(119, 136, 153), ofColor(105, 105, 105));
	fbo.end();
	secondaryFbo.allocate(1200, 720);
}




void Renderer::update(){
}

void Renderer::ajouterLumiere(ofColor couleur) {
	ofLight lumiere;
	lumiere.setAmbientColor(couleur);
	lumiereContainer.push_back(lumiere);
}

void Renderer::ajouterLumiere(int type, ofVec3f vecteur, ofColor couleur) {
	ofLight lumiere;
	if (type == 0) {
		lumiere.setPointLight();
		lumiere.setPosition(vecteur);
		lumiere.setDiffuseColor(couleur);
		lumiere.setAttenuation(1.0, 0.002, 0.000003);
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
	lumiere.setAttenuation(1.0, 0.002, 0.000003);
	lumiere.setSpotlightCutOff(30);
	lumiereContainer.push_back(lumiere);
}

void Renderer::setMaterial(ofMaterial material) {

	mate = material;
	materialsEnabled=true;
	colorShaderEnabled = false;


}


void Renderer::draw()
{
	if (!drawingToolActivated) {

		fbo.begin();
		ofEnableDepthTest();
		ofClear(255, 255, 255);
		ofBackgroundGradient(ofColor(119, 136, 153), ofColor(105, 105, 105));
		cam.begin();
		for (int i = 0; i<lumiereContainer.size(); i++) {
			lumiereContainer[i].enable();
		}
		if (colorShaderEnabled)
			simpleColorShader.begin();
		else if(displacementShaderEnabled)
			displacementShader.begin();
		else
			mate.begin();
		for (int i = 0; i<geometryObjectContainer.size(); i++) {
			geometryObjectContainer[i]->draw();

		}
		if (colorShaderEnabled)
			simpleColorShader.end();
		else if(displacementShaderEnabled)
			displacementShader.end();
		else
			mate.end();

		for (int i = 0; i<lumiereContainer.size(); i++) {
			lumiereContainer[i].disable();
		}
		cam.end();
		ofDisableDepthTest();
		fbo.end();
		fbo.draw(160, 90);
		if(blurShaderEnabled)
			drawBlur();
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

void Renderer::raytracing() {
	drawing->executeRaytracing();
}

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

//Parametric Curves
void Renderer::renderBezierCubic()
{
	ParametricCurve* bezierCubic = new ParametricCurve("bezier_cubic");
	bezierCubic->setup();
	geometryObjectContainer.push_back(bezierCubic);
}
void Renderer::renderBezierQuad()
{
	ParametricCurve* bezierQuad = new ParametricCurve("bezier_quad");
	bezierQuad->setup();
	geometryObjectContainer.push_back(bezierQuad);
}
void Renderer::renderBezierSix()
{
	ParametricCurve* bezierSix = new ParametricCurve("bezier_six");
	bezierSix->setup();
	geometryObjectContainer.push_back(bezierSix);
}
void Renderer::renderHermiteCurve()
{
	ParametricCurve* hermiteCurve = new ParametricCurve("hermite");
	hermiteCurve->setup();
	geometryObjectContainer.push_back(hermiteCurve);
}

void Renderer::renderParametricMesh()
{
	ParametricMesh* paraMesh = new ParametricMesh();
	paraMesh->setup();
	geometryObjectContainer.push_back(paraMesh);
}


std::vector<GeometryObject*>* Renderer::getObjects() {
	return &geometryObjectContainer;
}

int Renderer::getNumberOfObjects() {
	return geometryObjectContainer.size();
}

void Renderer::enableMaterials() {
	displacementShaderEnabled = false;
	blurShaderEnabled=false;
	colorShaderEnabled = false;
	materialsEnabled = true;
}

void Renderer::enableColorShader() {
	displacementShaderEnabled = false;
	materialsEnabled = false;
	blurShaderEnabled=false;
	colorShaderEnabled = true;
}

void Renderer::enableDisplacementShader() {
	materialsEnabled = false;
	colorShaderEnabled = false;
	blurShaderEnabled=false;
	displacementShaderEnabled = true;
}

void Renderer::disableShaders() {
	materialsEnabled = false;
	colorShaderEnabled = false;
	displacementShaderEnabled = false;
	blurShaderEnabled=false;

}
void Renderer::enableBlurShader() {
	materialsEnabled = false;
	colorShaderEnabled = false;
	displacementShaderEnabled = false;
	blurShaderEnabled=true;

}

void Renderer::drawBlur() {
    //----------------------------------------------------------
    secondaryFbo.begin();
    cam.begin();
    blurShader_1.begin();
    blurShader_1.setUniform1f("blurAmnt", 10);

	for (int i = 0; i<geometryObjectContainer.size(); i++) {
		geometryObjectContainer[i]->draw();

	}
	blurShader_1.end();
	cam.end();
    secondaryFbo.end();

    fbo.begin();

    blurShader_2.begin();
    blurShader_2.setUniform1f("blurAmnt", 10);

    secondaryFbo.draw(0, 0);

    blurShader_2.end();

    blurShader_2.end();

    //----------------------------------------------------------
    ofSetColor(ofColor::white);
    fbo.draw(0, 0);



}

Renderer::~Renderer(){
}


