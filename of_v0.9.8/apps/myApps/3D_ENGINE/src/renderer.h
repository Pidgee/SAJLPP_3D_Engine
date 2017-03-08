#pragma once

#include "ofMain.h"
#include "particleCloud.h"

class Renderer
{
public:

	ofFbo fbo;

	Renderer();

	ParticleCloud * particleCloud;

	void setup();
	void keyPressed(int key);
	void update();
	void draw();

	ofEasyCam cam;

	~Renderer();
};