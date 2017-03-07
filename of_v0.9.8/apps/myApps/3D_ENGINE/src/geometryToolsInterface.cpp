/*
 * geometryToolsInterface.cpp
 *
 *  Created on: Mar 7, 2017
 *      Author: ada
 */
#include "geometryToolsInterface.h"


GeometryToolBar::GeometryToolBar(ofxPanel* p_geometryPanel,
		ofxButton* p_particleCloudButton): m_geometryPanel(p_geometryPanel), m_particleCloudButton(p_particleCloudButton) {
}

void GeometryToolBar::setup() {
	m_geometryPanel->setup();
	m_geometryPanel->add(m_particleCloudButton->setup("Particle Cloud"));
}

void GeometryToolBar::draw() {
	m_geometryPanel->draw();
}


