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
	//canvas.begin();
	ofClear(255, 255, 255);
	ofBackground(255, 255, 255);
	//canvas.end();
}


void Drawing::draw()
{
	canvas.begin();
	ofEnableDepthTest();
	ofClear(255, 255, 255);
	ofBackground(255, 255, 255);
	ofDisableDepthTest();
	canvas.end();
	canvas.draw(160, 90);
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

}

void Drawing::drawTriangleCursor(int x, int y) {

}

void Drawing::drawCircleCursor(int x, int y) {

}

void Drawing::drawLine(int startX, int startY, int endX, int endY) {
	canvas.begin();
	ofLine(startX, startY, endX, endY);
	canvas.end();
}

void Drawing::drawTriangle(int point1X, int point1Y, int point2X, int point2Y, int point3X, int point3Y) {
	canvas.begin();
	ofTriangle(point1X, point1Y, point2X, point2Y, point3X, point3Y);
	canvas.end();
}

void Drawing::drawCircle(int centerX, int centerY, int radiusX, int radiusY) {
	float radius = sqrt(pow((radiusX-centerX), 2) + pow((radiusY - centerY), 2));
	canvas.begin();
	ofCircle(centerX, centerY, radius);
	canvas.end();
}

std::string Drawing::id() {
	return "Foo";
}

Drawing::~Drawing()
{

}