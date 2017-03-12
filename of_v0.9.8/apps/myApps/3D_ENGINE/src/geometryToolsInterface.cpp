/*
 * geometryToolsInterface.cpp
 *
 *  Created on: Mar 7, 2017
 *      Author: ada
 */
#include "geometryToolsInterface.h"
#include <stdio.h>


GeometryToolBar::GeometryToolBar(Renderer* p_renderer): m_geometryPanel(ofxPanel()),
		m_particleCloudButton(ofxButton()), m_renderer(p_renderer), visible(false) {
	m_particleCloudButton.addListener(this,  &GeometryToolBar::renderParticleCloud);
}

void GeometryToolBar::setup() {
	m_geometryPanel.setup();
	m_geometryPanel.setName("Geometry Tools");
	m_geometryPanel.setPosition(5,90);
	m_geometryPanel.add(m_particleCloudButton.setup("Particle Cloud"));

	m_geometryPanel.setSize(150,200);
	m_particleCloudButton.setSize(150,15);
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
