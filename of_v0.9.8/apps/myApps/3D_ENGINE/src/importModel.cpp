#include "importModel.h"

ImportModel::ImportModel(std::string p_path) : m_path(p_path), select(false) {

}

void ImportModel::setup()
{
	glShadeModel(GL_SMOOTH);

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

bool ImportModel::getSelected() {
	return select;
}

void ImportModel::setSelected(bool val) {
	select = val;
}

std::string ImportModel::id() {
	return "Foo";
}