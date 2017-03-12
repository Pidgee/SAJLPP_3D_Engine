#pragma once

#include "ofMain.h"
#include "geometryObject.h"
#include "ofxAssimpModelLoader.h"

class ImportModel : public GeometryObject
{

public:

	ImportModel(std::string p_path);

	ofxAssimpModelLoader model;
	ofPoint position;

	void setup();
	void draw();

	bool getSelected();
	void setSelected(bool val);

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

private:
	std::string m_path;
	bool select;
};
