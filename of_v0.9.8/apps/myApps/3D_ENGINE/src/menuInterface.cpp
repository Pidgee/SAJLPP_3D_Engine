/*
 * menuInterface.cpp
 *
 *  Created on: Mar 7, 2017
 *      Author: ada
 */
#include "menuInterface.h"

MenuBar::MenuBar(ofxPanel* p_menuPanel, ofxButton* p_geometryTools,
		ofxButton* p_drawTools, ofxButton* p_imageTools,
		ofxButton* p_cameraTools, GeometryToolBar* p_geoToolBar):
		m_menuPanel(p_menuPanel), m_geometryTools(p_geometryTools), m_drawTools(p_drawTools),
		m_imageTools(p_imageTools), m_cameraTools(p_cameraTools), m_geoToolBar(p_geoToolBar){

	m_geometryTools->addListener(this, &MenuBar::geoToolsClicked);
	m_imageTools->addListener(this, &MenuBar::imgToolsClicked);
}


void MenuBar::setup() {
	m_menuPanel->setup();

	m_menuPanel->add(m_geometryTools->setup("Geometry Tools"));
	m_menuPanel->add(m_drawTools->setup("Draw Tools"));
	m_menuPanel->add(m_imageTools->setup("Image Tools"));
	m_menuPanel->add(m_cameraTools->setup("Camera Tools"));

	m_menuPanel->setSize(800, 0);
	m_menuPanel->setPosition(160,50);
	m_menuPanel->setName("Tools");
	m_menuPanel->setBorderColor(ofColor(0,0,0,0));

	m_geometryTools->setPosition(160,70);
	m_drawTools->setPosition(360,70);
	m_imageTools->setPosition(560,70);
	m_cameraTools->setPosition(760,70);

}


void MenuBar::draw() {
	m_menuPanel->draw();
}


void MenuBar::geoToolsClicked() {
	m_geoToolBar->show();
}


void MenuBar::imgToolsClicked() {
	m_geoToolBar->hide();
}
