#include "geometryPrimitive.h"

GeometryPrimitive::GeometryPrimitive(std::string p_type) : m_type(p_type)
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
	material.setShininess(120);
	ofColor color = (255, 0, 255, 0.4);
	material.setColors(color, color, color, color);
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

void GeometryPrimitive::setupTetrahedron(float width)
{
	//Initialisation du tetrahèdre
	width = width / 2;
	mesh.clear();
	ofFill();
	ofSetColor(0, 0, 0, 0.4);
	mesh.addVertex(ofPoint(width, width, width));
	mesh.addVertex(ofPoint(-width, -width, width));
	mesh.addVertex(ofPoint(-width, width, -width));
	mesh.addVertex(ofPoint(width, -width, -width));
}

void GeometryPrimitive::setupOctahedron(float width)
{
	//Initialisation do l'octohèdre
	width = width / 2;
	mesh.clear();
	ofFill();
	ofSetColor(0, 0, 0, 0.4);
	mesh.addVertex(ofPoint(width, 0, 0));
	mesh.addVertex(ofPoint(0, width, 0));
	mesh.addVertex(ofPoint(0, 0, width));
	mesh.addVertex(ofPoint(-width, 0, 0));
	mesh.addVertex(ofPoint(0, -width, 0));
	mesh.addVertex(ofPoint(0, 0, -width));

}

void GeometryPrimitive::setupIcosahedron(float width)
{
	//Initialisation de l'icosahèdre
	width = width / 2;
	float l1 = 1.618033*width;
	float l2 = 0.618033*width;
	mesh.clear();
	ofFill();
	ofSetColor(0, 0, 0, 0.4);
	mesh.addVertex(ofPoint(-l1, 0, l2));
	mesh.addVertex(ofPoint(l1, 0, l2));
	mesh.addVertex(ofPoint(-l1, 0, -l2));
	mesh.addVertex(ofPoint(l1, 0, -l2));
	mesh.addVertex(ofPoint(0, l2, l1));
	mesh.addVertex(ofPoint(0, l2, -l1));
	mesh.addVertex(ofPoint(0, -l2, l1));
	mesh.addVertex(ofPoint(0, -l2, -l1));
	mesh.addVertex(ofPoint(l2, l1, 0));
	mesh.addVertex(ofPoint(-l2, l1, 0));
	mesh.addVertex(ofPoint(l2, -l1, -0));
	mesh.addVertex(ofPoint(-l2, -l1, 0));
}

void GeometryPrimitive::setupDodecahedron(float width)
{
	//Initialisation du dodécahèdre
	width = width / 2;
	float l1 = 0.525731*width;
	float l2 = 0.850650*width;
	mesh.clear();
	ofFill();
	ofSetColor(0, 0, 0, 0.4);
	mesh.addVertex(ofPoint(0, l2, l1));
	mesh.addVertex(ofPoint(0, l2, -l1));
	mesh.addVertex(ofPoint(0, -l2, l1));
	mesh.addVertex(ofPoint(0, -l2, -l1));
	mesh.addVertex(ofPoint(l1, 0, l2));
	mesh.addVertex(ofPoint(l1, 0, -l2));
	mesh.addVertex(ofPoint(-l1, 0, l2));
	mesh.addVertex(ofPoint(-l1, 0, -l2));
	mesh.addVertex(ofPoint(l2, l1, 0));
	mesh.addVertex(ofPoint(l2, -l1, 0));
	mesh.addVertex(ofPoint(-l2, l1, -0));
	mesh.addVertex(ofPoint(-l2, -l1, 0));
	mesh.addVertex(ofPoint(width, width, width));
	mesh.addVertex(ofPoint(width, width, -width));
	mesh.addVertex(ofPoint(width, -width, width));
	mesh.addVertex(ofPoint(width, -width, -width));
	mesh.addVertex(ofPoint(-width, width, width));
	mesh.addVertex(ofPoint(-width, width, -width));
	mesh.addVertex(ofPoint(-width, -width, width));
	mesh.addVertex(ofPoint(-width, -width, -width));
}


void GeometryPrimitive::rotateX() {
}

void GeometryPrimitive::rotateY() {
}

void GeometryPrimitive::rotateZ() {
}

void GeometryPrimitive::translateX() {
}

void GeometryPrimitive::translateY() {
}

void GeometryPrimitive::translateZ() {
}

void GeometryPrimitive::scale() {
}

std::string GeometryPrimitive::id() {
	return "Foo";
}