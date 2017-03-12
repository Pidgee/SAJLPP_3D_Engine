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
	void drawLine(float startX, float startY, float endX, float endY);
	void drawTriangle(float point1X, float point1Y, float point2X, float point2Y, float point3X, float point3Y);
	void drawCircle(float centerX, float centerY, float radiusX, float radiusY);

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