/*
 * geometryToolsInterface.h
 *
 *  Created on: Mar 7, 2017
 *      Author: ada
 */
#include "ofxGui.h"


#ifndef SRC_GEOMETRYTOOLSINTERFACE_H_
#define SRC_GEOMETRYTOOLSINTERFACE_H_


class GeometryToolBar
{
public:

	GeometryToolBar(ofxPanel* p_geometryPanel, ofxButton* p_particleCloudButton);

	void setup();
	void draw();


private:
	ofxPanel* m_geometryPanel;
	ofxButton* m_particleCloudButton;

};




#endif /* SRC_GEOMETRYTOOLSINTERFACE_H_ */
