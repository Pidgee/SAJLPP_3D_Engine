/*
 * drawToolsInterface.h
 *
 *  Created on: Mar 9, 2017
 *      Author: ada
 */
#include "ofxGui.h"

#ifndef SRC_DRAWTOOLSINTERFACE_H_
#define SRC_DRAWTOOLSINTERFACE_H_



class DrawToolBar
{
public:

	DrawToolBar(ofxPanel* p_drawPanel, ofxButton* p_lineButton,  ofxButton* p_triangleButton,  ofxButton* p_circleButton);

	void setup();
	void draw();
	void show();
	void hide();


private:
	ofxPanel* m_drawPanel;
	ofxButton* m_lineButton;
	ofxButton* m_triangleButton;
	ofxButton* m_circleButton;
	bool visible;

};



#endif /* SRC_DRAWTOOLSINTERFACE_H_ */
