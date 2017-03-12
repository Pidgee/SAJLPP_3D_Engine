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
	TransformationToolBar(Renderer* p_renderer);

	void draw();
	void setup();
	void update();
	void transform();
	void pageUp();
	void pageDown();

private:

	int currentPage;
	int numberOfObjects;
	int lastPage;
	bool wait;

	//renderer
	Renderer* m_renderer;

	//widgets
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
	ofxGuiGroup selectGroup;

	//transform command
	ofxButton pageUpButton;
	ofxButton pageDownButton;
	ofxToggle item_1;
	ofxToggle item_2;
	ofxToggle item_3;
	ofxToggle item_4;
	ofxToggle item_5;

	ofxToggle items[5]={item_1, item_2, item_3, item_4, item_5};

	ofxButton transformButton;

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
