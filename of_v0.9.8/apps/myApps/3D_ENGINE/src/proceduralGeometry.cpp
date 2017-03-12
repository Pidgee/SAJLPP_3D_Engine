#include "proceduralGeometry.h"

ProceduralGeometry::ProceduralGeometry(string p_path) : m_path(p_path), select(false)
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
			if (color.a > 0) {
				// Modifier l'étendue de la composante alpha pour un meilleur résultat
				float z = ofMap(color.a, 0, 255, -300, 300);
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

void ProceduralGeometry::rotateX() {
}

void ProceduralGeometry::rotateY() {
}

void ProceduralGeometry::rotateZ() {
}

void ProceduralGeometry::translateX() {
}

void ProceduralGeometry::translateY() {
}

void ProceduralGeometry::translateZ() {
}

void ProceduralGeometry::scale() {
}

bool ProceduralGeometry::getSelected() {
	return select;
}

void ProceduralGeometry::setSelected(bool val) {
	select = val;
}

std::string ProceduralGeometry::id() {
	return "Foo";
}
