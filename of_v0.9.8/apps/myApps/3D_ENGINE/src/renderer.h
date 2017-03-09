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
	void exporter();
	void importer();
	void update();
	void draw();

	vector<pair<ofTexture,ofPoint>> liste_image;

	ofEasyCam cam;

	~Renderer();
};