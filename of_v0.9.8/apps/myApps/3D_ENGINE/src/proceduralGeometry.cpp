#include "proceduralGeometry.h"

ProceduralGeometry::ProceduralGeometry(string p_path, string p_name) : m_path(p_path), m_name(p_name), select(false)
{

}

void ProceduralGeometry::setup()
{
	ofSetVerticalSync(true);

	// Charger une image
	img.load(m_path);

	mesh.setMode(OF_PRIMITIVE_POINTS);
	// Boucle dans l'image pour les coordonnées x et y
	for (int y = 0; y < img.getHeight(); y ++) {
		for (int x = 0; x < img.getWidth(); x ++) {
			ofColor color = img.getColor(x, y);
			int colorAvg = (color.r + color.g + color.b + color.a) / 4;
			if (color.a > 0 && (color.r+color.g+color.b) > 0) {
				// Modifier l'étendue de la couleur pour un meilleur résultat
				float z = ofMap(colorAvg, 0, 255, -300, 300);
				color.a = 255;
				mesh.addColor(color);
				ofVec3f position(x, y, z);
				mesh.addVertex(position);
			}
		}
	}

	glEnable(GL_POINT_SMOOTH);
	glPointSize(3);
}

void ProceduralGeometry::draw()
{
	mesh.draw();
}

void ProceduralGeometry::rotateX(float x) {
	vector<ofVec3f> vertices = mesh.getVertices();
	mesh.clearVertices();
	x = x * M_TWO_PI / 360;
	for (int i = 0; i < vertices.size(); i++)
	{
		vertices[i][1] = (vertices[i][1] * cos(x)) - (vertices[i][2] * sin(x));
		vertices[i][2] = (vertices[i][1] * sin(x)) + (vertices[i][2] * cos(x));
		mesh.addVertex(vertices[i]);
	}
}

void ProceduralGeometry::rotateY(float y) {
	vector<ofVec3f> vertices = mesh.getVertices();
	mesh.clearVertices();
	y = y * M_TWO_PI / 360;
	for (int i = 0; i < vertices.size(); i++)
	{
		vertices[i][0] = vertices[i][0] * cos(y) + vertices[i][2] * sin(y);
		vertices[i][2] = vertices[i][2] * cos(y) - vertices[i][0] * sin(y);
		mesh.addVertex(vertices[i]);
	}
}

void ProceduralGeometry::rotateZ(float z) {
	vector<ofVec3f> vertices = mesh.getVertices();
	mesh.clearVertices();
	z = z * M_TWO_PI / 360;
	for (int i = 0; i < vertices.size(); i++)
	{
		vertices[i][0] = vertices[i][0] * cos(z) - vertices[i][1] * sin(z);
		vertices[i][1] = vertices[i][0] * sin(z) + vertices[i][1] * cos(z);
		mesh.addVertex(vertices[i]);
	}
}

void ProceduralGeometry::translateX(float x) {
	vector<ofVec3f> vertices = mesh.getVertices();
	mesh.clearVertices();
	for (int i = 0; i < vertices.size(); i++)
	{
		vertices[i][0] = vertices[i][0] + x;
		mesh.addVertex(vertices[i]);
	}
}

void ProceduralGeometry::translateY(float y) {
	vector<ofVec3f> vertices = mesh.getVertices();
	mesh.clearVertices();
	for (int i = 0; i < vertices.size(); i++)
	{
		vertices[i][1] = vertices[i][1] + y;
		mesh.addVertex(vertices[i]);
	}
}

void ProceduralGeometry::translateZ(float z) {
	vector<ofVec3f> vertices = mesh.getVertices();
	mesh.clearVertices();
	for (int i = 0; i < vertices.size(); i++)
	{
		vertices[i][2] = vertices[i][2] + z;
		mesh.addVertex(vertices[i]);
	}
}

void ProceduralGeometry::scale(float scale) {
	vector<ofVec3f> vertices = mesh.getVertices();
	mesh.clearVertices();
	for (int i = 0; i < vertices.size(); i++)
	{
		vertices[i] = vertices[i] * scale;
		mesh.addVertex(vertices[i]);
	}
}

bool ProceduralGeometry::getSelected() {
	return select;
}

void ProceduralGeometry::setSelected(bool val) {
	select = val;
}

std::string ProceduralGeometry::id() {
	return m_name;
}
