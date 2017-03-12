/*
 * transformToolBar.cpp
 *
 *  Created on: Mar 9, 2017
 *      Author: ada
 */
#include "transformToolsInterface.h"

//contructor class for transform toolbar

TransformationToolBar::TransformationToolBar(Renderer* p_renderer): currentPage(0), m_renderer(p_renderer), numberOfObjects(0), lastPage(0), wait(false){
	pageUpButton.addListener(this,  &TransformationToolBar::pageUp);
	pageDownButton.addListener(this,  &TransformationToolBar::pageDown);
	transformButton.addListener(this,  &TransformationToolBar::applyTransform);

}

//public setup method for transform tools
void TransformationToolBar::setup() {
	m_transformPanel.setup();
	m_transformPanel.setName("Transformation");
	m_transformPanel.setPosition(1445,90);

	//add group for transformation widgets
	m_transformPanel.add(transformGroup.setup());

	//add transformation widgets to group
	transformGroup.add(m_rotateXSlider.setup("Rotate X", 0, -180, 180));
	transformGroup.add(m_rotateYSlider.setup("Rotate Y", 0, -180, 180));
	transformGroup.add(m_rotateZSlider.setup("Rotate Z", 0, -180, 180));
	transformGroup.add(m_translateXSlider.setup("Move X", 0, -800, 800));
	transformGroup.add(m_translateYSlider.setup("Move Y", 0, -800, 800));
	transformGroup.add(m_translateZSlider.setup("Move Z", 0, -800, 800));
	transformGroup.add(m_scaleSlider.setup("Scale %", 100, 10, 800));

	m_transformPanel.add(transformButton.setup("APPLY TRANSFORM"));


	//set position of toolbar
	transformGroup.setPosition(1445,90);

	//set size of all toolbar widgets
	m_transformPanel.setSize(150,200);
	transformGroup.setSize(150,200);
	m_rotateXSlider.setSize(150,20);
	m_rotateYSlider.setSize(150,20);
	m_rotateZSlider.setSize(150,20);
	m_translateXSlider.setSize(150,20);
	m_translateYSlider.setSize(150,20);
	m_translateZSlider.setSize(150,20);
	m_scaleSlider.setSize(150,20);




}

//public draw method for transform tools
void TransformationToolBar::draw() {
	m_transformPanel.draw();
}

//private listener method for transform button
void TransformationToolBar::transform() {
}

//action listener for pageUp button
void TransformationToolBar::pageUp() {
	if(!wait){
	std::cout<<"Hello"<<std::endl;
	int pagesAvailable = 1+((m_renderer->getNumberOfObjects())-1)/5;
	if(pagesAvailable !=0)
		currentPage = (currentPage+1)%pagesAvailable;
	updateNames();
	}
}

//action listener for pageDwon button
void TransformationToolBar::pageDown() {

	if(!wait){
	int pagesAvailable = (m_renderer->getNumberOfObjects())/5;
	if(pagesAvailable !=0)
		currentPage = abs(currentPage-1)%pagesAvailable;
	updateNames();
	}
}


void TransformationToolBar::updateNames() {
	int startIndice = currentPage*5;
	bool selected =false;
	std::vector<GeometryObject*>* objectContainer = m_renderer->getObjects();
	std::string name = "nul";
	for(int i=0; i<5; i++){
		if(startIndice+i < objectContainer->size()){
			name = (((*objectContainer)[startIndice+i])->id());
			selected = (((*objectContainer)[startIndice+i])->selected());
		}
		else{
			name="nul";
			selected=false;
		}
		items[i].operator =(selected);
		items[i].setName(name);
		items[i].getName();
	}

}


void TransformationToolBar::applyTransform() {
	float rotx = 0;
	float roty = 0;
	float rotz = 0;
	float transx = 0;
	float transy = 0;
	float transz = 0;
	float scale = 0;
	m_renderer->renderTransformation(rotx, roty, rotz, transx, transz, transy, scale);
}

void TransformationToolBar::actionItem1() {
}

void TransformationToolBar::actionItem2() {
}

void TransformationToolBar::actionItem3() {
}

void TransformationToolBar::actionItem4() {
}

void TransformationToolBar::actionItem5() {
}
