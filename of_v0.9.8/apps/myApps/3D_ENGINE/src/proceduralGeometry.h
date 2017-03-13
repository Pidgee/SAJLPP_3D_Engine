#pragma once
#include "geometryObject.h"
#include "ofMain.h"

class ProceduralGeometry : public GeometryObject
{
public:

	ProceduralGeometry(string p_path, string p_name);

	ofMesh mesh;
	ofImage img;
	
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
	string m_path;
	string m_name;
	bool select;
};

