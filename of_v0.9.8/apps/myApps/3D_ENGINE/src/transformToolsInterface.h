/*
 * transformToolBar.h
 *
 *  Created on: Mar 9, 2017
 *      Author: ada
 */
#include "ofxGui.h"
#include "renderer.h"

#ifndef SRC_TRANSFORMTOOLBAR_H_
#define SRC_TRANSFORMTOOLBAR_H_

class TransformationToolBar{

public:
	TransformationToolBar();

	void draw();
	void setup();
	void transform();

private:
	ofxPanel m_transformPanel;

	//rotation control
	ofxFloatSlider m_rotateXSlider;
	ofxFloatSlider m_rotateYSlider;
	ofxFloatSlider m_rotateZSlider;

	//translate control
	ofxFloatSlider m_translateXSlider;
	ofxFloatSlider m_translateYSlider;
	ofxFloatSlider m_translateZSlider;

	//scale control
	ofxFloatSlider m_scaleSlider;

	//group
	ofxGuiGroup transformGroup;

	//transform command
	ofxButton pageUp;
	ofxButton pageDown;
	ofxButton item_1;
	ofxButton item_2;
	ofxButton item_3;
	ofxButton item_4;
	ofxButton item_5;

	ofxButton transformButton;

	//renderer
	Renderer* m_renderer;

	//update toggle names
	void updateNames();
	void applyTransform();
	void actionItem1();
	void actionItem2();
	void actionItem3();
	void actionItem4();
	void actionItem5();

};




#endif /* SRC_TRANSFORMTOOLBAR_H_ */
