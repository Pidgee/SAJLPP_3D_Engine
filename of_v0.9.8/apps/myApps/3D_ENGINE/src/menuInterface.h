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
#include "shaderToolsInterface.h"

#ifndef SRC_MENUINTERFACE_H_
#define SRC_MENUINTERFACE_H_

class MenuBar
{
public:

	MenuBar(GeometryToolBar* p_geoToolBar, ImageToolBar* p_imgToolBar, DrawToolBar* p_drwToolBar, ShaderToolBar* p_shaderToolBar);

	void setup();
	void draw();
	void geoToolsClicked();
	void imgToolsClicked();
	void drwToolsClicked();
	void camToolsClicked();


private:
	ofxPanel m_menuPanel;
	ofxButton m_geometryTools;
	ofxButton m_drawTools;
	ofxButton m_imageTools;
	ofxButton m_shaderTools;
	GeometryToolBar* m_geoToolBar;
	ImageToolBar* m_imgToolBar;
	DrawToolBar* m_drwToolBar;
	ShaderToolBar* m_shaderToolBar;


};


#endif /* SRC_MENUINTERFACE_H_ */
