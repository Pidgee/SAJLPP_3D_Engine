#include "particleCloud.h"

ParticleCloud::ParticleCloud():select(false) {}

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

void ParticleCloud::rotateX(float x) {
	vector<ofVec3f> vertices = mesh.getVertices();
	mesh.clearVertices();
	x = x * M_TWO_PI / 360;
	for (int i = 0; i < vertices.size(); i++)
	{
		vertices[i][1] = (vertices[i][1] * cos(x)) - (vertices[i][2] * sin(x));
		vertices[i][2] = (vertices[i][1] * sin(x)) + (vertices[i][2] * cos(x));
		mesh.addVertex(vertices[i]);
	}
}

void ParticleCloud::rotateY(float y ) {
	vector<ofVec3f> vertices = mesh.getVertices();
	mesh.clearVertices();
	y = y * M_TWO_PI / 360;
	for (int i = 0; i < vertices.size(); i++)
	{
		vertices[i][0] = vertices[i][0] * cos(y) + vertices[i][2] * sin(y);
		vertices[i][2] = vertices[i][2] * cos(y) - vertices[i][0] * sin(y);
		mesh.addVertex(vertices[i]);
	}
}

void ParticleCloud::rotateZ(float z) {
	vector<ofVec3f> vertices = mesh.getVertices();
	mesh.clearVertices();
	z = z * M_TWO_PI / 360;
	for (int i = 0; i < vertices.size(); i++)
	{
		vertices[i][0] = vertices[i][0] * cos(z) - vertices[i][1] * sin(z);
		vertices[i][1] = vertices[i][0] * sin(z) + vertices[i][1] * cos(z);
		mesh.addVertex(vertices[i]);
	}
}

void ParticleCloud::translateX(float x) {
	vector<ofVec3f> vertices = mesh.getVertices();
	mesh.clearVertices();
	for (int i = 0; i < vertices.size(); i++)
	{
		vertices[i][0] = vertices[i][0] + x;
		mesh.addVertex(vertices[i]);
	}
}

void ParticleCloud::translateY(float y) {
	vector<ofVec3f> vertices = mesh.getVertices();
	mesh.clearVertices();
	for (int i = 0; i < vertices.size(); i++)
	{
		vertices[i][1] = vertices[i][1] + y;
		mesh.addVertex(vertices[i]);
	}
}

void ParticleCloud::translateZ(float z) {
	vector<ofVec3f> vertices = mesh.getVertices();
	mesh.clearVertices();
	for (int i = 0; i < vertices.size(); i++)
	{
		vertices[i][2] = vertices[i][2] + z;
		mesh.addVertex(vertices[i]);
	}
}

void ParticleCloud::scale(float scale) {
	vector<ofVec3f> vertices = mesh.getVertices();
	mesh.clearVertices();
	for (int i = 0; i < vertices.size(); i++)
	{
		vertices[i] = vertices[i] * scale;
		mesh.addVertex(vertices[i]);
	}
}

std::string ParticleCloud::id() {
	return "Particle Cloud";
}

bool ParticleCloud::getSelected() {
	return select;
}

void ParticleCloud::setSelected(bool val) {
	select=val;
}

ParticleCloud::~ParticleCloud()
{

}
