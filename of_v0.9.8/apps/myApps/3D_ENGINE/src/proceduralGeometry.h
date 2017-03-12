#pragma once
#include "geometryObject.h"
#include "ofMain.h"

class ProceduralGeometry : public GeometryObject
{
public:

	ProceduralGeometry(string p_path);

	ofMesh mesh;
	ofImage img;
	
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
	string m_path;
	bool select;
};

