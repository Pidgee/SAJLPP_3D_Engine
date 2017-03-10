#pragma once
#include "geometryObject.h"
#include "ofMain.h"

class ProceduralGeometry : public GeometryObject
{
public:

	ofMesh mesh;
	ofImage img;
	std::string imgPath;
	
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

