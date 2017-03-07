/*
 * menuInterface.cpp
 *
 *  Created on: Mar 7, 2017
 *      Author: ada
 */
#include "menuInterface.h"

MenuBar::MenuBar(ofxPanel* p_menuBar, ofxButton* p_geometryTools,
		ofxButton* p_drawTools, ofxButton* p_imageTools,
		ofxButton* p_cameraTools): m_menuBar(p_menuBar), m_geometryTools(p_geometryTools),
		m_drawTools(p_drawTools), m_imageTools(p_imageTools), m_cameraTools(p_cameraTools){
}



void MenuBar::setup() {
	m_menuBar->setup();

	m_menuBar->add(m_geometryTools->setup("Geometry Tools"));
	m_menuBar->add(m_drawTools->setup("Draw Tools"));
	m_menuBar->add(m_imageTools->setup("Image Tools"));
	m_menuBar->add(m_cameraTools->setup("Camera Tools"));

	m_menuBar->setSize(800, 0);
	m_menuBar->setPosition(160,50);
	m_menuBar->setName("Tools");
	m_menuBar->setBorderColor(ofColor(0,0,0,0));

	m_geometryTools->setPosition(160,70);
	m_drawTools->setPosition(360,70);
	m_imageTools->setPosition(560,70);
	m_cameraTools->setPosition(760,70);



}


void MenuBar::draw() {
	m_menuBar->draw();
}

