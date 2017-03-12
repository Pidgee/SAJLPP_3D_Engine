/*
 * drawing.cpp
 *
 *  Created on: Mar 9, 2017
 *      Author: Phil Giroux
 */
#include "drawing.h"

Drawing::Drawing() {}

void Drawing::setup()
{
	canvas.allocate(1280, 720);
	canvas.setAnchorPoint(640, 360);
	canvas.begin();
	ofClear(255, 255, 255);
	ofBackground(0, 0, 0);
	canvas.end();
}


void Drawing::draw()
{
	canvas.draw(0, 0);
}


void Drawing::rotateX() {
}

void Drawing::rotateY() {
}

void Drawing::rotateZ() {
}

void Drawing::translateX() {
}

void Drawing::translateY() {
}

void Drawing::translateZ() {
}

void Drawing::scale() {
}

void Drawing::drawLineCursor(int x, int y) {
	ofLine(x - 5, y + 7, x - 3, y + 5);
}

void Drawing::drawTriangleCursor(int x, int y) {
	ofTriangle(x - 5, y + 7, x - 5, y + 4, x - 3, y + 7);
}

void Drawing::drawCircleCursor(int x, int y) {
	ofCircle(x - 5, y + 7, 3);
}

void Drawing::drawLine(float startX, float startY, float endX, float endY) {
	canvas.begin();
	ofSetLineWidth(2);
	ofSetColor(255);
	ofLine(startX, startY, endX, endY);
	canvas.end();
}

void Drawing::drawTriangle(float point1X, float point1Y, float point2X, float point2Y, float point3X, float point3Y) {
	canvas.begin();
	ofSetColor(255);
	ofTriangle(point1X, point1Y, point2X, point2Y, point3X, point3Y);
	canvas.end();
}

void Drawing::drawCircle(float centerX, float centerY, float radiusX, float radiusY) {
	float radius = sqrt(pow((radiusX-centerX), 2) + pow((radiusY - centerY), 2));
	canvas.begin();
	ofSetColor(255);
	ofEnableSmoothing();
	ofSetCircleResolution(60);
	ofCircle(centerX, centerY, radius);
	canvas.end();
}

std::string Drawing::id() {
	return "Foo";
}

Drawing::~Drawing()
{

}