#include "particleCloud.h"

ParticleCloud::ParticleCloud() {}

void ParticleCloud::setup()
{
	ofSetVerticalSync(true);
	cloudRadius = 200;
	particleCount = 1000;
	origin[0] = 0;
	origin[1] = 0;
	origin[2] = 0;

	particleBufferSize = particleCount;

	drawCloud(particleCount, cloudRadius, origin);

}


void ParticleCloud::draw()
{
	mesh.draw();
}

void ParticleCloud::drawCloud(int count, float radius, float origin[3])
{
	// validations
	if (count <= 0 || radius <= 0 || count > particleBufferSize)
		return;	

	particleBufferHead = count;

	float x;
	float y;
	float z;
	int r;
	int g;
	int b;
	int a;

	mesh.setMode(OF_PRIMITIVE_POINTS);
	for (int i = 0; i < particleBufferHead; i++)
	{

		x = origin[0] + ofRandom(-radius, radius);
		y = origin[1] + ofRandom(-radius, radius);
		z = origin[2] + ofRandom(-radius, radius);

		r = ofRandom(0, 255);
		g = ofRandom(0, 255);
		b = ofRandom(0, 255);
		a = 255;

		ofColor color(r, g, b, a);
		mesh.addColor(color);
		ofVec3f position(x, y, z);
		mesh.addVertex(position);
	}
	glEnable(GL_POINT_SMOOTH);
	glPointSize(3);
}


std::string ParticleCloud::id() {
	return "Particle Cloud";
}

void ParticleCloud::rotateX(float x) {
}

void ParticleCloud::rotateY(float y) {
}

void ParticleCloud::ParticleCloud::rotateZ(float z) {
}

void ParticleCloud::ParticleCloud::translateX(float x) {
}

void ParticleCloud::ParticleCloud::translateY(float y) {
}

void ParticleCloud::ParticleCloud::translateZ(float z) {
}

void ParticleCloud::ParticleCloud::scale(float scale) {
}

ParticleCloud::~ParticleCloud()
{

}
