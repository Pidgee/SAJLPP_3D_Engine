#include "importModel.h"

ImportModel::ImportModel(std::string p_path, std::string p_name) : m_path(p_path), m_name(p_name), select(false) {

}

void ImportModel::setup()
{
	glShadeModel(GL_SMOOTH);
	rotationIndice = 0;
	//Load l'image au chemin modelPath
	position = ofPoint(0, 0, 0);
	model.loadModel(m_path);
	
}

void ImportModel::draw()
{
	//Affichage du modèle
	model.setPosition(position[0], position[1], position[2]);
	model.drawFaces();
}

void ImportModel::rotateX(float x) {
	model.setRotation(rotationIndice, x, 1, 0, 0);
	rotationIndice++;
}

void ImportModel::rotateY(float y) {
	model.setRotation(rotationIndice, y, 0, 1, 0);
	rotationIndice++;
}

void ImportModel::rotateZ(float z) {
	model.setRotation(rotationIndice, z, 0, 0, 1);
	rotationIndice++;
}

void ImportModel::translateX(float x) {
	position = model.getPosition();
	model.setPosition(position[0] + x, position[1], position[2]);
	position = model.getPosition();
}

void ImportModel::translateY(float y) {
	position = model.getPosition();
	model.setPosition(position[0], position[1] + y, position[2]);
	position = model.getPosition();
}

void ImportModel::translateZ(float z) {
	position = model.getPosition();
	model.setPosition(position[0], position[1], position[2] + z);
	position = model.getPosition();
}

void ImportModel::scale(float scale) {
	model.setScale(scale, scale, scale);
}

bool ImportModel::getSelected() {
	return select;
}

void ImportModel::setSelected(bool val) {
	select = val;
}

std::string ImportModel::id() {
	return m_name;
}