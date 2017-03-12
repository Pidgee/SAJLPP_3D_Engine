/*
 * drawToolsInterface.h
 *
 *  Created on: Mar 9, 2017
 *      Author: ada
 */
#include "ofxGui.h"
#include "renderer.h"

#ifndef SRC_DRAWTOOLSINTERFACE_H_
#define SRC_DRAWTOOLSINTERFACE_H_



class DrawToolBar
{
public:

	DrawToolBar(Renderer* p_renderer);

	void setup();
	void draw();
	void show();
	void hide();


private:
	ofxPanel m_drawPanel;
	ofxButton m_lineButton;
	ofxButton m_triangleButton;
	ofxButton m_circleButton;
	Renderer* m_renderer;
	bool visible;

};



#endif /* SRC_DRAWTOOLSINTERFACE_H_ */
