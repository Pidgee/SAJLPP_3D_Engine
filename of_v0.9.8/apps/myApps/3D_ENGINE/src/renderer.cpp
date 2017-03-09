#include "renderer.h"

Renderer::Renderer() {}

void Renderer::setup()
{
	fbo.allocate(1280, 720);
	fbo.begin();
	particleCloud = new ParticleCloud;
	particleCloud->setup();
	ofClear(255, 255, 255);
	ofBackground(255, 255, 255);
	fbo.end();
}

void Renderer::update()
{

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

void Renderer::importer() {

	ofFileDialogResult resultat = ofSystemLoadDialog("Importation d'image");

	if (resultat.bSuccess) {

		ofImage temp;

		string chemin = resultat.filePath;

		string nom = resultat.fileName;

		string nom_complet = nom;

		temp.load(nom_complet);

		ofTexture texture = temp.getTexture();

		ofPoint point(liste_image.size()*300, liste_image.size() * 300, liste_image.size() * 300);

		pair<ofTexture, ofPoint> position_im(texture, point);

		liste_image.push_back(position_im);

	}
}

void Renderer::draw()
{
	fbo.begin();
	ofClear(255, 255, 255);
	ofBackground(255, 255, 255);
	cam.begin();
	particleCloud->draw();

	if (liste_image.size() != 0) {

		int i;

		for (i = 0; i < liste_image.size(); i++) {

			pair<ofTexture, ofPoint> position_im;

			position_im = liste_image[i];

			ofTexture im = position_im.first;

			ofPoint position = position_im.second;

			im.draw(position.x-(im.getWidth()) / 2, position.y-(im.getHeight()) / 2, position.z, im.getWidth(), im.getHeight());
		}
	}

	cam.end();
	fbo.end();
	fbo.draw(160, 90);
}

Renderer::~Renderer()
{

}