#pragma once

#include "ofMain.h"
#include "geometryObject.h"
#include "ofxAssimpModelLoader.h"

class ImportModel : public GeometryObject
{

public:

	ofxAssimpModelLoader model;
	std::string modelPath;

	void setup();
	void draw();

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
};
