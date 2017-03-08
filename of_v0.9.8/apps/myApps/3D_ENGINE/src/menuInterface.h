/*
 * menuInterface.h
 *
 *  Created on: Mar 7, 2017
 *      Author: ada
 */

#include "ofxGui.h"
#include "geometryToolsInterface.h"

#ifndef SRC_MENUINTERFACE_H_
#define SRC_MENUINTERFACE_H_

class MenuBar
{
public:

	MenuBar(ofxPanel* p_menuPanel, ofxButton* p_geometryTools, ofxButton* p_drawTools,
			ofxButton* p_imageTools, ofxButton* p_cameraTools, GeometryToolBar* p_geoToolBar);

	void setup();
	void draw();
	void geoToolsClicked();
	void imgToolsClicked();


private:
	ofxPanel* m_menuPanel;
	ofxButton* m_geometryTools;
	ofxButton* m_drawTools;
	ofxButton* m_imageTools;
	ofxButton* m_cameraTools;
	GeometryToolBar* m_geoToolBar;


};


#endif /* SRC_MENUINTERFACE_H_ */
