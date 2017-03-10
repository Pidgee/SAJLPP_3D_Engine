#include "renderer.h"

Renderer::Renderer() {}

void Renderer::setup()
{
	fbo.allocate(1280, 720);
	fbo.begin();
	for(int i=0; i<geometryObjectContainer.size(); i++){
		geometryObjectContainer[i]->setup();
	}
	ofClear(255, 255, 255);
	ofBackground(255, 255, 255);
	fbo.end();
}

void Renderer::update()
{

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
