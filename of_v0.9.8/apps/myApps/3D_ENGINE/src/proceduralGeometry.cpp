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
}

void ProceduralGeometry::rotateY(float y) {
}

void ProceduralGeometry::rotateZ(float z) {
}

void ProceduralGeometry::translateX(float x) {
}

void ProceduralGeometry::translateY(float y) {
}

void ProceduralGeometry::translateZ(float z) {
}

void ProceduralGeometry::scale(float scale) {
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
