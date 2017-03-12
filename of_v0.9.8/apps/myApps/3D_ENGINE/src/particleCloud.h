#pragma once

#include "ofMain.h"
#include "geometryObject.h"

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


	bool selected();

	void rotateX(float x);
	void rotateY(float y);
	void rotateZ(float z);
	void translateX(float x);
	void translateY(float y);
	void translateZ(float z);
	void scale(float scale);

	//instance name
	std::string id();

	void drawCloud(int count, float radius, float origin[3]);

	ofMesh mesh;

private:
	bool select;

	~ParticleCloud();
};
