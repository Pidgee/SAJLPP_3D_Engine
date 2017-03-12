#include "geometryPrimitive.h"

GeometryPrimitive::GeometryPrimitive(std::string p_type) : m_type(p_type), select(false)
{
	
}

void GeometryPrimitive::setup()
{
	if (m_type == "sphere") {
		setupSphere(100);
	}
	else if (m_type == "cube") {
		setupCube(150);
	}
	else if (m_type == "cylinder") {
		setupCylinder(100, 200);
	}
	else if (m_type == "cone") {
		setupCone(100, 200);
	}
	else {
		
	}
	ofColor color = (255, 0, 255, 0.4);
}

void GeometryPrimitive::draw()
{
	//primitive.setColor(0, 0, 0, 0.4);
	primitive.setPosition(0, 0, 0);
	ofFill();
	mesh = primitive.getMesh();
	mesh.enableColors();
	vector<ofIndexType> indices = mesh.getIndices();
	/*vector<ofIndexType>::iterator iter;
	for (iter = indices.begin(); iter != indices.end(); iter++)
	{
		mesh.addColor(ofColor(0, 0, 0, 0.4));
	*/
	mesh.setColorForIndices(0, indices.size() - 1, ofColor(0, 0, 0, 0.4));
	mesh.drawFaces();
}

void GeometryPrimitive::setupCube(float width)
{
	//Position, rayon et couleur initiaux du cube
	cube.set(width);
	primitive = cube;
	
}

void GeometryPrimitive::setupSphere(float radius)
{
	//Initialisation de la sphère
	sphere.setRadius(radius);
	ofSetSphereResolution(24);
	primitive = sphere;
}

void GeometryPrimitive::setupCylinder(float radius, float height)
{
	//Initialisation du cylindre
	cylinder.set(radius, height);
	primitive = cylinder;
}

void GeometryPrimitive::setupCone(float radius, float height)
{
	//Initialisation du cone
	cone.set(radius, height);
	primitive = cone;
}


void GeometryPrimitive::rotateX(float x) {
}

void GeometryPrimitive::rotateY(float y) {
}

void GeometryPrimitive::rotateZ(float z) {
}

void GeometryPrimitive::translateX(float x) {
}

void GeometryPrimitive::translateY(float y) {
}

void GeometryPrimitive::translateZ(float z) {
}

void GeometryPrimitive::scale(float scale) {
}

bool GeometryPrimitive::getSelected() {
	return select;
}

void GeometryPrimitive::setSelected(bool val) {
	select = val;
}

std::string GeometryPrimitive::id() {
	return "Foo";
}