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
	position = ofVec3f(0, 0, 0);
	primitive.setPosition(position);
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
	position = primitive.getPosition();
	primitive.rotateAround(ofQuaternion(x, ofVec3f(1,0,0)), position);
	position = primitive.getPosition();
}

void GeometryPrimitive::rotateY(float y) {
	position = primitive.getPosition();
	primitive.rotateAround(ofQuaternion(y, ofVec3f(0, 1, 0)), position);
	position = primitive.getPosition();
}

void GeometryPrimitive::rotateZ(float z) {
	position = primitive.getPosition();
	primitive.rotateAround(ofQuaternion(z, ofVec3f(0, 0, 1)), position);
	position = primitive.getPosition();
}

void GeometryPrimitive::translateX(float x) {
	position = primitive.getPosition();
	primitive.setPosition(position[0] + x, position[1], position[2]);
	position = primitive.getPosition();
}

void GeometryPrimitive::translateY(float y) {
	position = primitive.getPosition();
	primitive.setPosition(position[0], position[1] + y, position[2]);
	position = primitive.getPosition();
}

void GeometryPrimitive::translateZ(float z) {
	position = primitive.getPosition();
	primitive.setPosition(position[0], position[1], position[2] + z);
	position = primitive.getPosition();
}

void GeometryPrimitive::scale(float scale) {
	primitive.setScale(scale);
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