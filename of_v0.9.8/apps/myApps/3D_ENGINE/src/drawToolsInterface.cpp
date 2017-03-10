/*
 * drawToolsInterface.cpp
 *
 *  Created on: Mar 9, 2017
 *      Author: ada
 */
#include "drawToolsInterface.h"



DrawToolBar::DrawToolBar(ofxPanel* p_drawPanel, ofxButton* p_lineButton,
		ofxButton* p_triangleButton, ofxButton* p_circleButton): m_drawPanel(p_drawPanel),
		m_lineButton(p_lineButton), m_triangleButton(p_triangleButton), m_circleButton(p_circleButton),
		visible(false){
}

void DrawToolBar::setup(){
	m_drawPanel->setup();
	m_drawPanel->setName("Draw Tools");
	m_drawPanel->setPosition(5,90);
	m_drawPanel->add(m_lineButton->setup("Draw Line"));
	m_drawPanel->add(m_triangleButton->setup("Draw Triangle"));
	m_drawPanel->add(m_circleButton->setup("Draw Circle"));


	m_drawPanel->setSize(150,200);
	m_lineButton->setSize(150,15);
	m_triangleButton->setSize(150,15);
	m_circleButton->setSize(150,15);

}

void DrawToolBar::draw() {
	if(visible)
		m_drawPanel->draw();
}



void DrawToolBar::show() {
	visible =true;
}

void DrawToolBar::hide() {
	visible=false;
}




