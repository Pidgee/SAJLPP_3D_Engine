#pragma once

#include "ofMain.h"
#include "geometryObject.h"

class GeometryPrimitive : public GeometryObject
{

public:

	std::string primitiveName;

	void setupTetrahedron(float width);
	void setupHexahedron(float width);
	void setupOctahedron(float width);
	void setupDodecahedron(float width);
	void setupIcosahedron(float width);
	void setupSphere(float radius);
	void setupCylinder(float radius, float height);
	void setupCone(float radius, float height);

	void selectPrimitive(std::string primitiveName);

	of3dPrimitive tetrahedron;
	ofBoxPrimitive hexahedron;
	of3dPrimitive octahedron;
	of3dPrimitive dodecahedron;
	of3dPrimitive icosahedron;
	ofSpherePrimitive sphere;
	ofCylinderPrimitive cylinder;
	ofConePrimitive cone;
	ofMesh mesh;

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
