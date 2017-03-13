/*
 * drawing.h
 *
 *  Created on: Mar 9, 2017
 *      Author: ada
 */

#ifndef SRC_DRAWING_H_
#define SRC_DRAWING_H_

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
	bool getSelected();
	void setSelected(bool val);

	//cursor
	void drawLineCursor(int x, int y);
	void drawTriangleCursor(int x, int y);
	void drawCircleCursor(int x, int y);

	//draw forms
	void drawLine(float startX, float startY, float endX, float endY);
	void drawTriangle(float point1X, float point1Y, float point2X, float point2Y, float point3X, float point3Y);
	void drawCircle(float centerX, float centerY, float radiusX, float radiusY);

	//rotation transformations
	void rotateX(float x);
	void rotateY(float y);
	void rotateZ(float z);

	//translation transformations
	void translateX(float x);
	void translateY(float y);
	void translateZ(float z);

	//scale transformation
	void scale(float scale);

	//instance name
	std::string id();

	ofMesh mesh;
private:
	bool select;

	~Drawing();
};

#endif /* SRC_DRAWING_H_ */
