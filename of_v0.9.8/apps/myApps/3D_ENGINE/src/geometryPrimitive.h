#pragma once

#include "ofMain.h"
#include "geometryObject.h"

class GeometryPrimitive : public GeometryObject
{

public:

	GeometryPrimitive(std::string p_type);
	
	void setupTetrahedron(float width);
	void setupCube(float width);
	void setupOctahedron(float width);
	void setupDodecahedron(float width);
	void setupIcosahedron(float width);
	void setupSphere(float radius);
	void setupCylinder(float radius, float height);
	void setupCone(float radius, float height);

	of3dPrimitive tetrahedron;
	ofBoxPrimitive cube;
	of3dPrimitive octahedron;
	of3dPrimitive dodecahedron;
	of3dPrimitive icosahedron;
	ofSpherePrimitive sphere;
	ofCylinderPrimitive cylinder;
	ofConePrimitive cone;
	ofMesh mesh;
	of3dPrimitive primitive;
	ofMaterial material;

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
	bool select;
	std::string m_type;
};
