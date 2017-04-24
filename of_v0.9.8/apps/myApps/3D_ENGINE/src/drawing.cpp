/*
 * drawing.cpp
 *
 *  Created on: Mar 9, 2017
 *      Author: ada
 */
#include "drawing.h"

Drawing::Drawing() : select(false) {}

void Drawing::setup()
{
	ofBoxPrimitive *cube = new ofBoxPrimitive();
	ofSpherePrimitive *sphere = new ofSpherePrimitive;
	ofPlanePrimitive *plane = new ofPlanePrimitive;
	sphere->setRadius(10);
	sphere->setPosition(600, 300, 0);
	cube->setPosition(100, 100, 0);
	//m_primitiveVector.push_back(cube);
	m_primitiveVector.push_back(sphere);
	canvas.allocate(1280, 720);
	canvas.begin();
	ofClear(255, 255, 255);
	ofBackground(0, 0, 0);
	canvas.end();
}


void Drawing::draw()
{
	canvas.draw(160, 90);
	image.draw(160, 90);
}


void Drawing::rotateX(float x) {
}

void Drawing::rotateY(float y) {
}

void Drawing::rotateZ(float z) {
}

void Drawing::translateX(float x) {
}

void Drawing::translateY(float y) {
}

void Drawing::translateZ(float z) {
}

void Drawing::scale(float scale) {
}

void Drawing::drawLineCursor(int x, int y) {
	ofSetColor(255, 0, 0);
	ofLine(x - 12, y + 20, x - 6, y + 10);
	ofSetColor(255);
}

void Drawing::drawTriangleCursor(int x, int y) {
	ofSetColor(255, 0, 0);
	ofTriangle(x - 10, y + 20, x - 10, y + 10, x - 3, y + 20);
	ofSetColor(255);
}

void Drawing::drawCircleCursor(int x, int y) {
	ofSetColor(255, 0, 0);
	ofCircle(x - 7, y + 12, 5);
	ofSetColor(255);
}

void Drawing::drawLine(float startX, float startY, float endX, float endY) {
	canvas.begin();
	ofSetLineWidth(2);
	ofSetColor(255);
	ofLine(startX - 160, startY - 90, endX - 160, endY - 90);
	canvas.end();
}

void Drawing::drawTriangle(float point1X, float point1Y, float point2X, float point2Y, float point3X, float point3Y) {
	canvas.begin();
	ofSetColor(255);
	ofTriangle(point1X - 160, point1Y - 90, point2X - 160, point2Y - 90, point3X - 160, point3Y - 90);
	canvas.end();
}

void Drawing::drawCircle(float centerX, float centerY, float radiusX, float radiusY) {
	float radius = sqrt(pow((radiusX-centerX), 2) + pow((radiusY - centerY), 2));
	canvas.begin();
	ofSetColor(255);
	ofEnableSmoothing();
	ofSetCircleResolution(60);
	ofCircle(centerX - 160, centerY - 90, radius);
	canvas.end();
}

std::string Drawing::id() {
	return "Foo";
}

bool Drawing::getSelected() {
	return select;
}

void Drawing::setSelected(bool val) {
	select = val;
}

void Drawing::executeRaytracing() {
	canvas.begin();
	int imageWidth = 1280;
	int imageHeight = 720;
	image.allocate(imageWidth, imageHeight, OF_IMAGE_COLOR);
	
	for (int j = 0; j < imageHeight; j++) {
		for (int i = 0; i < imageWidth; i++) {
			for (std::vector<of3dPrimitive*>::iterator it = m_primitiveVector.begin(); it != m_primitiveVector.end(); it++) {
				if (getIntersection(it, i, j) > 0) {
					image.setColor(i % imageWidth, j%imageHeight, ofColor(0, 255, 0));
				}
				else if (getPlaneIntersection(i, j , imageWidth)) {
					image.setColor(i % imageWidth, j%imageHeight, ofColor(255, 0, 255));
				}
				else {
					image.setColor(i % imageWidth, j%imageHeight, ofColor(0, 0, 0));
				}
			}
		}
	}
	image.update();
	canvas.end();
}

Drawing::~Drawing()
{
}

int Drawing::getIntersection(vector<of3dPrimitive*>::iterator it, int x, int y) {
	int dx = x -600;
	int dy = y - 300;
	int dz = 0;
	int cx = (*it)->getPosition().x;
	int cy = (*it)->getPosition().y;
	int cz = (*it)->getPosition().z;
	int a = pow(dx, 2) + pow(dy, 2) + pow(dz , 2);
	int b = 2*dx * (-cx) + 2 * dy * (-cy) + 2*dz * (-cz);
	int c = pow(cx, 2) + pow(cy ,2) - pow(((ofSpherePrimitive*)(*it))->getRadius(), 2);

	return (pow(b, 2) - 4 * a*c);
}

bool Drawing::getPlaneIntersection(int x, int y, int width) {
	int dx = (width / 2) - y;
	if (dx == 0) {
		dx += 1;
	}
	if (-100 / dx < 0) {
		return true;
	}
	return false;
}



