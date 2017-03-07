#pragma once

#include "ofMain.h"

class Renderer
{
public:

	ofFbo fbo;

	Renderer();

	void setup();
	void draw();
	void mouseDragged();

	~Renderer();
};