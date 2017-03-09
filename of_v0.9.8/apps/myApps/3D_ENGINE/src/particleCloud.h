#pragma once

#include "ofMain.h"
#include "geometryObject.h"
#include "ofxAssimpModelLoader.h"

class ParticleCloud : public GeometryObject
{

public:

	ParticleCloud();

	float cloudRadius;
	int particleCount;
	float origin[3];

	int particleBufferSize;
	int particleBufferHead;

	void setup();
	void draw();

	//rotation transformations
	void rotateX();
	void rotateY();
	void rotateZ();

	//translation transformations
	void translateX();
	void translateY();
	void translateZ();

	//scale transformation
	void scale();

	//instance name
	std::string id();

	void drawCloud(int count, float radius, float origin[3]);

	ofMesh mesh;

	~ParticleCloud();
};
