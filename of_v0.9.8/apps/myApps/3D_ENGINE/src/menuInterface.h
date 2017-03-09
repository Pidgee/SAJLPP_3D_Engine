/*
 * menuInterface.h
 *
 *  Created on: Mar 7, 2017
 *      Author: ada
 */

#include "ofxGui.h"
#include "geometryToolsInterface.h"
#include "imageToolsInterface.h"

#ifndef SRC_MENUINTERFACE_H_
#define SRC_MENUINTERFACE_H_

class MenuBar
{
public:

	MenuBar(ofxPanel* p_menuPanel, ofxButton* p_geometryTools, ofxButton* p_drawTools,
			ofxButton* p_imageTools, ofxButton* p_cameraTools, GeometryToolBar* p_geoToolBar,
			ImageToolBar* p_imgToolBar);

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
	ImageToolBar* m_imgToolBar;


};


#endif /* SRC_MENUINTERFACE_H_ */
