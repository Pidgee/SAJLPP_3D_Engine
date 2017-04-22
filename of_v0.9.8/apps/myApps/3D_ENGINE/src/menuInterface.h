/*
 * menuInterface.h
 *
 *  Created on: Mar 7, 2017
 *      Author: ada
 */

#include "ofxGui.h"
#include "geometryToolsInterface.h"
#include "imageToolsInterface.h"
#include "drawToolsInterface.h"
#include "cameraToolsInterface.h"
#include "lightToolsInterface.h"

#ifndef SRC_MENUINTERFACE_H_
#define SRC_MENUINTERFACE_H_

class MenuBar
{
public:

	MenuBar( GeometryToolBar* p_geoToolBar,
			ImageToolBar* p_imgToolBar, DrawToolBar* p_drwToolBar, CameraToolBar* p_camToolBar, LightToolBar* p_lghToolBar);

	void setup();
	void draw();
	void geoToolsClicked();
	void imgToolsClicked();
	void drwToolsClicked();
	void camToolsClicked();
	void lghToolsClicked();


private:
	ofxPanel m_menuPanel;
	ofxButton m_geometryTools;
	ofxButton m_drawTools;
	ofxButton m_imageTools;
	ofxButton m_cameraTools;
	ofxButton m_lightTools;
	GeometryToolBar* m_geoToolBar;
	ImageToolBar* m_imgToolBar;
	DrawToolBar* m_drwToolBar;
	CameraToolBar* m_camToolBar;
	LightToolBar* m_lghToolBar;


};


#endif /* SRC_MENUINTERFACE_H_ */
