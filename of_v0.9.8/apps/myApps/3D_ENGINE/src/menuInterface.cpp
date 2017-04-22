/*
 * menuInterface.cpp
 *
 *  Created on: Mar 7, 2017
 *      Author: ada
 */
#include "menuInterface.h"


MenuBar::MenuBar(GeometryToolBar* p_geoToolBar,
		ImageToolBar* p_imgToolBar, DrawToolBar* p_drwToolBar, CameraToolBar* p_camToolBar, LightToolBar* p_lghToolBar):
		m_geoToolBar(p_geoToolBar), m_imgToolBar(p_imgToolBar), m_drwToolBar(p_drwToolBar), m_camToolBar(p_camToolBar), m_lghToolBar(p_lghToolBar){

	m_geometryTools.addListener(this, &MenuBar::geoToolsClicked);
	m_imageTools.addListener(this, &MenuBar::imgToolsClicked);
	m_drawTools.addListener(this, &MenuBar::drwToolsClicked);
	m_cameraTools.addListener(this, &MenuBar::camToolsClicked);
	m_lightTools.addListener(this, &MenuBar::lghToolsClicked);
}

void MenuBar::setup() {
	m_menuPanel.setup();

	m_menuPanel.add(m_geometryTools.setup("Geometry Tools"));
	m_menuPanel.add(m_drawTools.setup("Draw Tools"));
	m_menuPanel.add(m_imageTools.setup("Image Tools"));
	m_menuPanel.add(m_cameraTools.setup("Camera Tools"));

	m_menuPanel.setSize(800, 0);
	m_menuPanel.setPosition(160,50);
	m_menuPanel.setName("Tools");
	m_menuPanel.setBorderColor(ofColor(0,0,0,0));

	m_geometryTools.setPosition(160,70);
	m_drawTools.setPosition(360,70);
	m_imageTools.setPosition(560,70);
	m_cameraTools.setPosition(760,70);
}


void MenuBar::draw() {
	m_menuPanel.draw();
	m_camToolBar->show();
	m_lghToolBar->show();
}


void MenuBar::geoToolsClicked() {
	m_imgToolBar->hide();
	m_drwToolBar->hide();
	m_geoToolBar->show();
}


void MenuBar::imgToolsClicked() {
	m_geoToolBar->hide();
	m_drwToolBar->hide();
	m_imgToolBar->show();
}

void MenuBar::drwToolsClicked() {
	m_geoToolBar->hide();
	m_imgToolBar->hide();
	m_drwToolBar->show();
}

void MenuBar::camToolsClicked() {
	m_camToolBar->show();
}

void MenuBar::lghToolsClicked() {
	m_lghToolBar->show();
}
