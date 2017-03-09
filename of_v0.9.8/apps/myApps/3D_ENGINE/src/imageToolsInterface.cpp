/*
 * imageToolsInterface.cpp
 *
 *  Created on: Mar 8, 2017
 *      Author: ada
 */
#include "imageToolsInterface.h"

ImageToolBar::ImageToolBar(ofxPanel* p_imagePanel, ofxButton* p_importButton,
		ofxButton* p_exportButton): m_imagePanel(p_imagePanel), m_importButton(p_importButton),
		m_exportButton(p_exportButton), visible(false){
}

void ImageToolBar::setup() {
	m_imagePanel->setup();
	m_imagePanel->setName("Image Tools");
	m_imagePanel->setPosition(5,90);
	m_imagePanel->add(m_importButton->setup("Import Image"));
	m_imagePanel->add(m_exportButton->setup("Export Image"));


	m_imagePanel->setSize(150,200);
	m_importButton->setSize(150,15);
	m_exportButton->setSize(150,15);


}

void ImageToolBar::draw() {
	if(visible)
		m_imagePanel->draw();
}

void ImageToolBar::show() {
	visible=true;
}

void ImageToolBar::hide() {
	visible=false;
}





