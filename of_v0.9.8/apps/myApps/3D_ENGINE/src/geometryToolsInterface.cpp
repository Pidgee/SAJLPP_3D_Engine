/*
 * geometryToolsInterface.cpp
 *
 *  Created on: Mar 7, 2017
 *      Author: ada
 */
#include "geometryToolsInterface.h"
#include <stdio.h>


GeometryToolBar::GeometryToolBar(Renderer* p_renderer): m_geometryPanel(ofxPanel()),
		m_particleCloudButton(ofxButton()), m_sphereButton(ofxButton()), m_cubeButton(ofxButton()), m_cylinderButton(ofxButton()), 
	m_coneButton(ofxButton()), m_proceduralButton(ofxButton()), m_loadModelButton(ofxButton()), m_renderer(p_renderer), visible(false)
{
	m_particleCloudButton.addListener(this,  &GeometryToolBar::renderParticleCloud);
	m_sphereButton.addListener(this, &GeometryToolBar::renderSphere);
	m_cubeButton.addListener(this, &GeometryToolBar::renderCube);
	m_cylinderButton.addListener(this, &GeometryToolBar::renderCylinder);
	m_coneButton.addListener(this, &GeometryToolBar::renderCone);
	m_proceduralButton.addListener(this, &GeometryToolBar::renderProcedural);
	m_loadModelButton.addListener(this, &GeometryToolBar::renderModel);
	m_clearAllButton.addListener(this, &GeometryToolBar::clearAll);
}

void GeometryToolBar::setup() {
	m_geometryPanel.setup();
	m_geometryPanel.setName("Geometry Tools");
	m_geometryPanel.setPosition(5,90);
	m_geometryPanel.add(m_clearAllButton.setup("Clear all"));
	m_geometryPanel.add(m_particleCloudButton.setup("Particle Cloud"));
	m_geometryPanel.add(m_sphereButton.setup("Sphere"));
	m_geometryPanel.add(m_cubeButton.setup("Cube"));
	m_geometryPanel.add(m_cylinderButton.setup("Cylinder"));
	m_geometryPanel.add(m_coneButton.setup("Cone"));
	m_geometryPanel.add(m_proceduralButton.setup("Procedural"));
	m_geometryPanel.add(m_loadModelButton.setup("Load Model"));

	m_geometryPanel.setSize(150,200);
	m_particleCloudButton.setSize(150,15);
	m_sphereButton.setSize(150, 15);
}



void GeometryToolBar::draw() {
	if(visible)
		m_geometryPanel.draw();
}

void GeometryToolBar::show(){
	visible=true;
}

void GeometryToolBar::hide() {
	visible=false;
}

void GeometryToolBar::renderParticleCloud() {
	m_renderer->renderParticleCloud();
}

void GeometryToolBar::renderSphere(){
	m_renderer->renderSphere();
}

void GeometryToolBar::renderCube(){
	m_renderer->renderCube();
}

void GeometryToolBar::renderCylinder() {
	m_renderer->renderCylinder();
}

void GeometryToolBar::renderCone() {
	m_renderer->renderCone();
}

void GeometryToolBar::renderProcedural() {

	ofFileDialogResult result = ofSystemLoadDialog("Import texture");

	if (result.bSuccess) {

		string path = result.filePath;
		string name = result.fileName;

		m_renderer->renderProcedural(path, name);

	}

}

void GeometryToolBar::renderModel() {

	ofFileDialogResult result = ofSystemLoadDialog("Import model");

	if (result.bSuccess) {

		string path = result.filePath;
		string name = result.fileName;

		m_renderer->renderModel(path, name);

	}

}

void GeometryToolBar::clearAll() {

	std::cout << "Bonjour" << std::endl;
	vector<GeometryObject*>* objectContainer = m_renderer->getObjects();
	int numberObjects = m_renderer->getNumberOfObjects();
	objectContainer->clear();
}

