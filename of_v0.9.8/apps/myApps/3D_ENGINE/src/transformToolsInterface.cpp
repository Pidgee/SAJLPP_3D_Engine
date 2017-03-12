/*
 * transformToolBar.cpp
 *
 *  Created on: Mar 9, 2017
 *      Author: ada
 */
#include "transformToolsInterface.h"

//contructor class for transform toolbar
TransformationToolBar::TransformationToolBar(): m_transformPanel(ofxPanel()),
		m_rotateXSlider(ofxFloatSlider()), m_rotateYSlider(ofxFloatSlider()), m_rotateZSlider(ofxFloatSlider()),
		m_translateXSlider(ofxFloatSlider()), m_translateYSlider(ofxFloatSlider()), m_translateZSlider(ofxFloatSlider()),
		m_scaleSlider(ofxFloatSlider()), transformButton(ofxButton()),transformGroup(ofxGuiGroup()), item_1(ofxButton()){

}

//public setup method for transform tools
void TransformationToolBar::setup() {
	m_transformPanel.setup();
	m_transformPanel.setName("Transformation");
	m_transformPanel.setPosition(1445,90);

	//add group for transformation widgets
	m_transformPanel.add(transformGroup.setup());

	//add transformation widgets to group
	transformGroup.add(m_rotateXSlider.setup("Rotate X", 0, -180, 180));
	transformGroup.add(m_rotateYSlider.setup("Rotate Y", 0, -180, 180));
	transformGroup.add(m_rotateZSlider.setup("Rotate Z", 0, -180, 180));
	transformGroup.add(m_translateXSlider.setup("Move X", 0, -800, 800));
	transformGroup.add(m_translateYSlider.setup("Move Y", 0, -800, 800));
	transformGroup.add(m_translateZSlider.setup("Move Z", 0, -800, 800));
	transformGroup.add(m_scaleSlider.setup("Scale %", 100, 10, 800));

	m_transformPanel.add(transformButton.setup("APPLY TRANSFORM"));


	//set position of toolbar
	transformGroup.setPosition(1445,90);

	//set size of all toolbar widgets
	m_transformPanel.setSize(150,200);
	transformGroup.setSize(150,200);
	m_rotateXSlider.setSize(150,20);
	m_rotateYSlider.setSize(150,20);
	m_rotateZSlider.setSize(150,20);
	m_translateXSlider.setSize(150,20);
	m_translateYSlider.setSize(150,20);
	m_translateZSlider.setSize(150,20);
	m_scaleSlider.setSize(150,20);




}

//public draw method for transform tools
void TransformationToolBar::draw() {
	m_transformPanel.draw();
}

//private listener method for transform button
void TransformationToolBar::transform() {
}
