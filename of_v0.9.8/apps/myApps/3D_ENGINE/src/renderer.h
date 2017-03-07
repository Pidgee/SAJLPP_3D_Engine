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
	void update();
	void draw();

	ofEasyCam cam;

	~Renderer();
};