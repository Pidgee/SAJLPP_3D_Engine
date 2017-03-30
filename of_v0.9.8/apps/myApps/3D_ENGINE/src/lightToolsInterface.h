/*
* lightToolsInterface.h
*
*  Created on: Mar 8, 2017
*      Author: ada
*/
#include "ofxGui.h"
#include "renderer.h"


#ifndef SRC_LIGHTTOOLSINTERFACE_H_
#define SRC_LIGHTTOOLSINTERFACE_H_
class LightToolBar
{
public:

	LightToolBar(Renderer* p_renderer);

	void setup();
	void draw();
	void show();
	void hide();
	void ambient();
	void directionel();
	void point();
	void spot();
	void fermerBoiteAmbient();
	void fermerBoiteDirection();
	void fermerBoiteSpot();
	void demanderInfo();


private:
	ofxPanel m_lightPanel;
	ofxPanel m_boiteInfo;
	ofxButton m_ambientButton;
	ofxButton m_directionnelButton;
	ofxButton m_pointButton;
	ofxButton m_spotButton;
	Renderer* m_renderer;

	int type;

	ofxFloatSlider m_RSlider;
	ofxFloatSlider m_GSlider;
	ofxFloatSlider m_BSlider;
	ofxFloatSlider m_XSlider;
	ofxFloatSlider m_YSlider;
	ofxFloatSlider m_ZSlider;
	ofxFloatSlider m_OXSlider;
	ofxFloatSlider m_OYSlider;
	ofxFloatSlider m_OZSlider;
	ofxButton m_confirm;

	bool visible;
	bool ouvert_boite;

};




#endif /* SRC_LIGHTTOOLSINTERFACE_H_ */
