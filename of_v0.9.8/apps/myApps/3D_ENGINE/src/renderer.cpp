#include "renderer.h"
#include <string>

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

void Renderer::keyPressed(int key)
{

	if (key == 112 || key == 80) {

		ofFileDialogResult resultat = ofSystemSaveDialog("image.png", "Save");

		string nom = resultat.fileName;

		if (resultat.bSuccess) {

			ofImage image;

			ofTexture texture = fbo.getTexture();

			image.allocate(1280, 720, OF_IMAGE_COLOR);

			image.grabScreen(160, 90, texture.getWidth(), texture.getHeight());

			image.save(nom + ".png", OF_IMAGE_QUALITY_BEST);

		}

	}
}

void Renderer::draw()
{
	fbo.begin();
	ofClear(255, 255, 255);
	ofBackground(255, 255, 255);
	cam.begin();
	particleCloud->draw();
	cam.end();
	fbo.end();
	fbo.draw(160, 90);
}

Renderer::~Renderer()
{

}
