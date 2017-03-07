#pragma once

#include "ofMain.h"
#include "ofxAssimpModelLoader.h"

class ParticleCloud
{

public:

	ParticleCloud();

	float cloudRadius;
	int particleCount;
	float origin[3];

	int particleBufferSize;
	int particleBufferHead;

	void setup();
	void update();
	void draw();

	void drawCloud(int count, float radius, float origin[3]);

	ofMesh mesh;

	~ParticleCloud();
};