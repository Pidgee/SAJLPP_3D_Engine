/*
 * geometryToolsInterface.h
 *
 *  Created on: Mar 7, 2017
 *      Author: ada
 */
#include "ofxGui.h"
#include "renderer.h"


#ifndef SRC_GEOMETRYTOOLSINTERFACE_H_
#define SRC_GEOMETRYTOOLSINTERFACE_H_


class GeometryToolBar
{
public:

	GeometryToolBar(Renderer* p_renderer);

	void setup();
	void draw();
	void show();
	void hide();
	void renderParticleCloud();

private:
	ofxPanel m_geometryPanel;
	ofxButton m_particleCloudButton;
	Renderer* m_renderer;
	bool visible;

};




#endif /* SRC_GEOMETRYTOOLSINTERFACE_H_ */
