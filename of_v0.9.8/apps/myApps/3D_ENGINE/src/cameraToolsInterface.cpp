#include "cameraToolsInterface.h"
#include <stdio.h>


CameraToolBar::CameraToolBar(Renderer* p_renderer) : m_cameraPanel(ofxPanel()),
 m_renderer(p_renderer), visible(false), useEasyCam(true){
}

void CameraToolBar::setup() {
	m_cameraPanel.setup();
	m_cameraPanel.setName("Camera Tools");
	m_cameraPanel.setPosition(5, 90);
	m_cameraPanel.add(m_toggleEasyCam.setup("Utiliser EasyCam", TRUE, 150, 15));

	m_cameraPanel.setSize(150, 200);
}



void CameraToolBar::draw() {
	if (visible)
		m_cameraPanel.draw();
}

void CameraToolBar::show() {
	visible = true;
}

void CameraToolBar::hide() {
	visible = false;
}
