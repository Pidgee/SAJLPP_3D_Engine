#include "proceduralGeometry.h"

void ProceduralGeometry::setup()
{
	ofSetVerticalSync(true);

	// load an image from disk
	img.load(imgPath);

	// we're going to load a ton of points into an ofMesh
	mesh.setMode(OF_PRIMITIVE_POINTS);

	// Boucle dans l'image pour les coordonn�es x et y
	int skip = 4; // Limite le nombre de pixels analys�s
	for (int y = 0; y < img.getHeight(); y += skip) {
		for (int x = 0; x < img.getWidth(); x += skip) {
			ofColor color = img.getColor(x, y);
			if (color.a > 0) {
				// Modifier l'�tendue de la composante alpha pour un meilleur r�sultat
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

std::string ProceduralGeometry::id() {
	return "Foo";
}
