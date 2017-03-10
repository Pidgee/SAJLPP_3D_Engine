#include "importModel.h"

GLfloat lightOnePosition[] = { 40.0, 40, 100.0, 0.0 };
GLfloat lightOneColor[] = { 0.99, 0.99, 0.99, 1.0 };
GLfloat lightTwoPosition[] = { -40.0, 40, 100.0, 0.0 };
GLfloat lightTwoColor[] = { 0.99, 0.99, 0.99, 1.0 };

ImportModel::ImportModel(std::string p_path) : m_path(p_path) {

}

void ImportModel::setup()
{
	glShadeModel(GL_SMOOTH);
	/* initialize lighting */
	glLightfv(GL_LIGHT0, GL_POSITION, lightOnePosition);
	glLightfv(GL_LIGHT0, GL_DIFFUSE, lightOneColor);
	glEnable(GL_LIGHT0);
	glLightfv(GL_LIGHT1, GL_POSITION, lightTwoPosition);
	glLightfv(GL_LIGHT1, GL_DIFFUSE, lightTwoColor);
	glEnable(GL_LIGHT1);
	glEnable(GL_LIGHTING);
	glColorMaterial(GL_FRONT_AND_BACK, GL_DIFFUSE);
	glEnable(GL_COLOR_MATERIAL);

	//Load l'image au chemin modelPath
	model.loadModel(m_path);
}

void ImportModel::draw()
{
	//Affichage du modèle
	model.drawFaces();
}

void ImportModel::rotateX() {
}

void ImportModel::rotateY() {
}

void ImportModel::rotateZ() {
}

void ImportModel::translateX() {
}

void ImportModel::translateY() {
}

void ImportModel::translateZ() {
}

void ImportModel::scale() {
}

std::string ImportModel::id() {
	return "Foo";
}