#include "renderer.h"
#include <string>

Renderer::Renderer() {}

void Renderer::setup()
{
	fbo.allocate(1280, 720);
	fbo.begin();
	for(int i=0; i<geometryObjectContainer.size(); i++){
		geometryObjectContainer[i]->setup();
	}
	//particleCloud = new ParticleCloud;
	//particleCloud->setup();
	ofClear(255, 255, 255);
	ofBackground(255, 255, 255);
	fbo.end();
}

void Renderer::update()
{
}

ofVec3f convertionRGB_HSV(ofColor couleur) {

	ofVec3f hsv;

	float val_r = couleur.r/255;
	float val_g = couleur.g/255;
	float val_b = couleur.b/255;

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

void Renderer::draw()
{
	fbo.begin();
	ofEnableDepthTest();
	ofClear(255, 255, 255);
	ofBackground(255, 255, 255);
	cam.begin();
	for(int i=0; i<geometryObjectContainer.size(); i++){
		geometryObjectContainer[i]->draw();
	}
	cam.end();
	ofDisableDepthTest();
	fbo.end();
	fbo.draw(160, 90);
}

void Renderer::renderParticleCloud() {
	ParticleCloud* part = new ParticleCloud;
	part->setup();
	geometryObjectContainer.push_back(part);
}

Renderer::~Renderer()
{

}
