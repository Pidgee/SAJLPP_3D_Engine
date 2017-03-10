/*
 * transformToolBar.cpp
 *
 *  Created on: Mar 9, 2017
 *      Author: ada
 */
#include "transformToolsInterface.h"

//contructor class for transform toolbar
TransformationToolBar::TransformationToolBar(ofxPanel* p_transformPanel, ofxFloatSlider* p_rotateXSlider,
		ofxFloatSlider* p_rotateYSlider, ofxFloatSlider* p_rotateZSlider,
		ofxFloatSlider* p_translateXSlider, ofxFloatSlider* p_translateYSlider,
		ofxFloatSlider* p_translateZSlider, ofxFloatSlider* p_scaleSlider,
		ofxButton* p_transformButton, Renderer* p_renderer): m_transformPanel(p_transformPanel),
		m_rotateXSlider(p_rotateXSlider), m_rotateYSlider(p_rotateYSlider), m_rotateZSlider(p_rotateZSlider),
		m_translateXSlider(p_translateXSlider), m_translateYSlider(p_translateYSlider), m_translateZSlider(p_translateZSlider),
		transformGroup(ofxGuiGroup()){

}

//public setup method for transform tools
void TransformationToolBar::setup() {
	m_transformPanel->setup();
	m_transformPanel->setName("Transformation");
	m_transformPanel->setPosition(1445,90);

	//create group for transformation widgets
	m_transformPanel->add(transformGroup.setup());
	//add transformation widgets to group
	transformGroup.add(m_rotateXSlider->setup("Rotate X", 0, -180, 180));
	transformGroup.add(m_rotateYSlider->setup("Rotate Y", 0, -180, 180));
	transformGroup.add(m_rotateZSlider->setup("Rotate Z", 0, -180, 180));
	transformGroup.add(m_translateXSlider->setup("Move X", 0, -800, 800));
	transformGroup.add(m_translateYSlider->setup("Move Y", 0, -800, 800));
	transformGroup.add(m_translateZSlider->setup("Move Z", 0, -800, 800));


	transformGroup.setPosition(1445,90);

	m_transformPanel->setSize(150,200);
	transformGroup.setSize(150,200);
	m_rotateXSlider->setSize(150,20);
	m_rotateYSlider->setSize(150,20);
	m_rotateZSlider->setSize(150,20);
	m_translateXSlider->setSize(150,20);
	m_translateYSlider->setSize(150,20);
	m_translateZSlider->setSize(150,20);




}

//public draw method for transform tools
void TransformationToolBar::draw() {
	m_transformPanel->draw();
}

//private listener method for transform button
void TransformationToolBar::transform() {
}
