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
	canvas.allocate(1280, 720);
	canvas.begin();
	ofClear(255, 255, 255);
	ofBackground(0, 0, 0);
	canvas.end();
}


void Drawing::draw()
{
	canvas.draw(160, 90);
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

Drawing::~Drawing()
{

}

