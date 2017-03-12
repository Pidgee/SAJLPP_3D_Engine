#pragma once

#include <vector>
#include "ofMain.h"
#include "particleCloud.h"
#include "drawing.h"

class Renderer
{
public:

	ofFbo fbo;

	Renderer();

	ParticleCloud * particleCloud;

	void setup();
	void update();
	void draw();

	void appendObject(GeometryObject*);

	//geometryTools
	ParticleCloud* renderParticleCloud();

	//imageTools
	void renderImage();

	ofEasyCam cam;

	~Renderer();

private:
	//geometryObject container
	std::vector<GeometryObject*> geometryObjectContainer;

};
