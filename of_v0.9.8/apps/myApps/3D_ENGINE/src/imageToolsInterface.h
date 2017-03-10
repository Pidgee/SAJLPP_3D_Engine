/*
 * imageToolsInterface.h
 *
 *  Created on: Mar 8, 2017
 *      Author: ada
 */
#include "ofxGui.h"
#include "renderer.h"


#ifndef SRC_IMAGETOOLSINTERFACE_H_
#define SRC_IMAGETOOLSINTERFACE_H_
class ImageToolBar
{
public:

	ImageToolBar(ofxPanel* p_imagePanel, ofxButton* p_importButton, ofxButton* p_exportButton, ofxButton* m_teinte, ofxButton* m_composition, Renderer* p_renderer);

	void setup();
	void draw();
	void show();
	void hide();
	void importer();
	void exporter();
	void teinte();
	void composition();
	ofVec3f demanderInfo();


private:
	ofxPanel* m_imagePanel;
	ofxButton* m_importButton;
	ofxButton* m_exportButton;
	ofxButton* m_teinte;
	ofxButton* m_composition;
	Renderer* m_renderer;
	
	bool visible;

};




#endif /* SRC_IMAGETOOLSINTERFACE_H_ */
