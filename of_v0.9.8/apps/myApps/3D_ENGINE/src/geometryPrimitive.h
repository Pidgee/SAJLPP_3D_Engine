#pragma once

#include "ofMain.h"
#include "geometryObject.h"

class GeometryPrimitive : public GeometryObject
{

public:

	GeometryPrimitive(std::string p_type);

	void setupCube(float width);
	void setupSphere(float radius);
	void setupCylinder(float radius, float height);
	void setupCone(float radius, float height);

	ofBoxPrimitive cube;
	ofSpherePrimitive sphere;
	ofCylinderPrimitive cylinder;
	ofConePrimitive cone;
	ofMesh mesh;
	of3dPrimitive primitive;

	ofVec3f position;

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
	bool select;
	std::string m_type;
};
