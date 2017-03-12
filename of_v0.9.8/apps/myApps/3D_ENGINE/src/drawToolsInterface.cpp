/*
 * drawToolsInterface.cpp
 *
 *  Created on: Mar 9, 2017
 *      Author: ada
 */
#include "drawToolsInterface.h"



DrawToolBar::DrawToolBar(Renderer* p_renderer) :m_renderer(p_renderer),visible(false), lineDrawingActivated(false), triangleDrawingActivated(false) , circleDrawingActivated(false) {
		m_newDrawingButton.addListener(this, &DrawToolBar::renderDrawing);
		m_lineButton.addListener(this, &DrawToolBar::lineDrawing);
		m_triangleButton.addListener(this, &DrawToolBar::triangleDrawing);
		m_circleButton.addListener(this, &DrawToolBar::circleDrawing);
		m_saveDrawingButton.addListener(this, &DrawToolBar::saveDrawing);
	
}

void DrawToolBar::setup(){
	m_drawPanel.setup();
	m_drawPanel.setName("Draw Tools");
	m_drawPanel.setPosition(5,90);
	m_drawPanel.add(m_newDrawingButton.setup("New Drawing"));
	m_drawPanel.add(m_lineButton.setup("Draw Line"));
	m_drawPanel.add(m_triangleButton.setup("Draw Triangle"));
	m_drawPanel.add(m_circleButton.setup("Draw Circle"));
	m_drawPanel.add(m_saveDrawingButton.setup("Save Drawing"));
	

	m_drawPanel.setSize(150,200);
	m_newDrawingButton.setSize(150, 15);
	m_lineButton.setSize(150,15);
	m_triangleButton.setSize(150,15);
	m_circleButton.setSize(150,15);
	m_saveDrawingButton.setSize(150, 15);
	

}

void DrawToolBar::draw() {
	if(visible)
		m_drawPanel.draw();
}



void DrawToolBar::show() {
	visible =true;
}

void DrawToolBar::hide() {
	visible=false;
}

void DrawToolBar::renderDrawing() {
	m_renderer->renderDrawing();
}

void DrawToolBar::lineDrawing() {
	lineDrawingActivated = !lineDrawingActivated;
	triangleDrawingActivated = false;
	circleDrawingActivated = false;
	if (lineDrawingActivated) {

	}
}

void DrawToolBar::triangleDrawing() {
	compteur = 0;
	triangleDrawingActivated = !triangleDrawingActivated;
	circleDrawingActivated = false;
	lineDrawingActivated = false;
}

void DrawToolBar::circleDrawing() {
	circleDrawingActivated = !circleDrawingActivated;
	triangleDrawingActivated = false;
	lineDrawingActivated = false;
}

void DrawToolBar::saveDrawing() {

}

void DrawToolBar::mousePressed(int x, int y, int button) {
	if (lineDrawingActivated || triangleDrawingActivated || circleDrawingActivated) {
		x1 = x;
		y1 = y;
		compteur++;
	}

	if (triangleDrawingActivated && compteur == 1) {
		x2 = x;
		y2 = y;
		compteur++;
	}

	if (triangleDrawingActivated && compteur == 2) {
		x3 = x;
		y3 = y;
		m_renderer->drawTriangle(x1, y1, x2, y2, x3, y3);
		compteur = 0;
	}
}

void DrawToolBar::mouseReleased(int x, int y, int button) {
	if (lineDrawingActivated) {
		m_renderer->drawLine(x1, y1, x, y);
	}
	else if (circleDrawingActivated) {
		m_renderer->drawCircle(x1, y1, x, y);
	}
}
