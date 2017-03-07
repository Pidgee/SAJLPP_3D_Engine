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