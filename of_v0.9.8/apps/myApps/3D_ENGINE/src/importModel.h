#pragma once

#include "ofMain.h"
#include "geometryObject.h"
#include "ofxAssimpModelLoader.h"

class ImportModel : public GeometryObject
{

public:

	ImportModel(std::string p_path);

	ofxAssimpModelLoader model;

	void setup();
	void draw();

	bool getSelected();
	void setSelected(bool val);

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

private:
	std::string m_path;
	bool select;
};
