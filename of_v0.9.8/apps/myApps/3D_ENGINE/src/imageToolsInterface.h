/*
 * imageToolsInterface.h
 *
 *  Created on: Mar 8, 2017
 *      Author: ada
 */

#ifndef SRC_IMAGETOOLSINTERFACE_H_
#define SRC_IMAGETOOLSINTERFACE_H_
class ImageToolBar
{
public:

	ImageToolBar(ofxPanel* p_imagePanel, ofxButton* p_importButton, ofxButton* p_exportButton);

	void setup();
	void draw();
	void show();
	void hide();


private:
	ofxPanel* m_geometryPanel;
	ofxButton* m_importButton;
	ofxButton* m_exportButton;

	bool visible;

};




#endif /* SRC_IMAGETOOLSINTERFACE_H_ */
