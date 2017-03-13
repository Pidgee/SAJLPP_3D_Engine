#include "cameraToolsInterface.h"
#include <stdio.h>


CameraToolBar::CameraToolBar(Renderer* p_renderer) :
 m_renderer(p_renderer), visible(false){
}

void CameraToolBar::setup() {
	m_cameraPanel.setup();
	m_cameraPanel.setName("Camera Tools");
	CameraObject* cam = m_renderer->getCamera();
	m_cameraPanel.setup(cam->cameraParameters);
	m_cameraPanel.setPosition(5, 760);
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
