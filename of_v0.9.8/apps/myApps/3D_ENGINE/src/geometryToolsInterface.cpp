/*
 * geometryToolsInterface.cpp
 *
 *  Created on: Mar 7, 2017
 *      Author: ada
 */
#include "geometryToolsInterface.h"


GeometryToolBar::GeometryToolBar(ofxPanel* p_geometryPanel,
		ofxButton* p_particleCloudButton): m_geometryPanel(p_geometryPanel),
		m_particleCloudButton(p_particleCloudButton), visible(false) {
}

void GeometryToolBar::setup() {
	m_geometryPanel->setup();
	m_geometryPanel->setName("Geometry Tools");
	m_geometryPanel->setPosition(5,90);
	m_geometryPanel->add(m_particleCloudButton->setup("Particle Cloud"));

	m_geometryPanel->setSize(150,200);
	m_particleCloudButton->setSize(150,15);
}



void GeometryToolBar::draw() {
	if(visible)
		m_geometryPanel->draw();
}

void GeometryToolBar::show(){
	visible=true;
}

void GeometryToolBar::hide() {
	visible=false;
}
