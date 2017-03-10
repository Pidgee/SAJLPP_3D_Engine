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
	TransformationToolBar(ofxFloatSlider* p_rotateXSlider, ofxFloatSlider* p_rotateYSlider,
			ofxFloatSlider* p_rotateZSlider,ofxFloatSlider* p_translateXSlider, ofxFloatSlider* p_translateYSlider,
			ofxFloatSlider* p_translateZSlider, ofxFloatSlider* p_scaleSlider, ofxButton* p_transformButton,
			Renderer* p_renderer);

	void draw();
	void setup();
	void transform();

private:
	ofxPanel* transformPanel;

	//rotation control
	ofxFloatSlider* m_rotateXSlider;
	ofxFloatSlider* m_rotateYSlider;
	ofxFloatSlider* m_rotateZSlider;

	//translate control
	ofxFloatSlider* m_translateXSlider;
	ofxFloatSlider* m_translateYSlider;
	ofxFloatSlider* m_translateZSlider;

	//scale control
	ofxFloatSlider* m_scaleSlider;

	//transform command
	ofxButton* m_transformButton;

	//renderer
	Renderer* m_renderer;


};




#endif /* SRC_TRANSFORMTOOLBAR_H_ */
