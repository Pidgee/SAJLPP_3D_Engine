/*
 * menuInterface.h
 *
 *  Created on: Mar 7, 2017
 *      Author: ada
 */

#include "ofxGui.h"

#ifndef SRC_MENUINTERFACE_H_
#define SRC_MENUINTERFACE_H_

class MenuBar
{
public:

	MenuBar(ofxPanel* p_menuBar, ofxButton* p_geometryTools, ofxButton* p_drawTools, ofxButton* p_imageTools, ofxButton* p_cameraTools);

	void setup();
	void draw();


private:
	ofxPanel* m_menuBar;
	ofxButton* m_geometryTools;
	ofxButton* m_drawTools;
	ofxButton* m_imageTools;
	ofxButton* m_cameraTools;

};


#endif /* SRC_MENUINTERFACE_H_ */
