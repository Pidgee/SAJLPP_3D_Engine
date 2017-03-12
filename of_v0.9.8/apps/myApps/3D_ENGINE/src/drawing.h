/*
 * drawing.h
 *
 *  Created on: Mar 9, 2017
 *      Author: Phil Giroux
 */

#pragma once

#include "ofMain.h"
#include "geometryObject.h"
#include "ofxAssimpModelLoader.h"

class Drawing : public GeometryObject
{

public:

	Drawing();

	ofFbo canvas;

	void setup();
	void draw();

	//cursor
	void drawLineCursor(int x, int y);
	void drawTriangleCursor(int x, int y);
	void drawCircleCursor(int x, int y);

	//draw forms
	void drawLine(int startX, int startY, int endX, int endY);
	void drawTriangle(int point1X, int point1Y, int point2X, int point2Y, int point3X, int point3Y);
	void drawCircle(int centerX, int centerY, int radiusX, int radiusY);

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

	ofMesh mesh;

	~Drawing();
};