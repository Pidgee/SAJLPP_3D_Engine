#pragma once
#include "geometryObject.h"
#include "ofMain.h"

class ProceduralGeometry : public GeometryObject
{
public:

	ProceduralGeometry(std::string p_path);

	ofMesh mesh;
	ofImage img;
	
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

private:
	std::string m_path;
};

