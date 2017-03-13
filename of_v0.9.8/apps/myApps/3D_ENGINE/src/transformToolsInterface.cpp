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
	item_1.addListener(this,  &TransformationToolBar::actionItem1);
	item_2.addListener(this,  &TransformationToolBar::actionItem2);
	item_3.addListener(this,  &TransformationToolBar::actionItem3);
	item_4.addListener(this,  &TransformationToolBar::actionItem4);
	item_5.addListener(this,  &TransformationToolBar::actionItem5);

}

//public setup method for transform tools
void TransformationToolBar::setup() {
	std::cout << "page: " << currentPage << std::endl;
	m_transformPanel.clear();
	transformGroup.clear();
	m_transformPanel.setup();
	m_transformPanel.setName("Transformation");
	m_transformPanel.setPosition(1445, 90);

	//add group for selection widgets
	m_transformPanel.add(selectGroup.setup());

	//add group for transformation widgets
	m_transformPanel.add(transformGroup.setup());

	//add toggles to select group
	selectGroup.add(pageUpButton.setup("pageUp"));
	selectGroup.add(item_1.setup("nul_1", false));
	selectGroup.add(item_2.setup("nul_2", false));
	selectGroup.add(item_3.setup("nul_3", false));
	selectGroup.add(item_4.setup("nul_4", false));
	selectGroup.add(item_5.setup("nul_5", false));
	selectGroup.add(pageDownButton.setup("pageDown"));

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
	transformGroup.setPosition(1445, 90);

	//set size of all toolbar widgets
	m_transformPanel.setSize(150, 200);
	transformGroup.setSize(150, 200);
	m_rotateXSlider.setSize(150, 20);
	m_rotateYSlider.setSize(150, 20);
	m_rotateZSlider.setSize(150, 20);
	m_translateXSlider.setSize(150, 20);
	m_translateYSlider.setSize(150, 20);
	m_translateZSlider.setSize(150, 20);
	m_scaleSlider.setSize(150, 20);


}



void TransformationToolBar::update() {
	if (numberOfObjects != m_renderer->getNumberOfObjects() || lastPage != currentPage) {
		std::cout << "page: " << currentPage << std::endl;
		numberOfObjects = m_renderer->getNumberOfObjects();
		lastPage = currentPage;
		updateNames();
		wait = true;
		setup();
		wait = false;

	}
}

//public draw method for transform tools
void TransformationToolBar::draw() {
	updateNames();
	m_transformPanel.draw();
}

//private listener method for transform button
void TransformationToolBar::transform() {
}

//action listener for pageUp button
void TransformationToolBar::pageUp() {
	if (!wait) {
		int pagesAvailable = 1 + ((m_renderer->getNumberOfObjects()) - 1) / 5;
		if (pagesAvailable != 0)
			currentPage = (currentPage + 1) % pagesAvailable;
		updateNames();
	}


	int startIndice = currentPage*5;
	bool selected =false;
	std::vector<GeometryObject*>* objectContainer = m_renderer->getObjects();
	std::string name = "nul";
	for(int i=0; i<5; i++){
		if(startIndice+i < objectContainer->size()){
			name = (((*objectContainer)[startIndice+i])->id());
			selected = (((*objectContainer)[startIndice+i])->getSelected());
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

//action listener for pageDwon button
void TransformationToolBar::pageDown() {


	if(!wait){
	int pagesAvailable = (m_renderer->getNumberOfObjects())/5;
	if(pagesAvailable !=0)
		currentPage = abs(currentPage-1)%pagesAvailable;
	}


	int startIndice = currentPage*5;
	bool selected =false;
	std::vector<GeometryObject*>* objectContainer = m_renderer->getObjects();
	std::string name = "nul";
	for(int i=0; i<5; i++){
		if(startIndice+i < objectContainer->size()){
			name = (((*objectContainer)[startIndice+i])->id());
			selected = (((*objectContainer)[startIndice+i])->getSelected());
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


void TransformationToolBar::updateNames() {
	int startIndice = currentPage * 5;
	bool selected = false;
	std::vector<GeometryObject*>* objectContainer = m_renderer->getObjects();
	std::string name = "nul";
	for (int i = 0; i<5; i++) {
		if (startIndice + i < objectContainer->size()) {
			name = (((*objectContainer)[startIndice + i])->id());
			selected = (((*objectContainer)[startIndice + i])->getSelected());
		}
		else {
			name = "nul";
			selected = false;
		}
		items[i].operator =(selected);
		items[i].setName(name);
		items[i].getName();
	}

}


void TransformationToolBar::applyTransform() {
	float rotx = m_rotateXSlider;
	float roty = m_rotateYSlider;
	float rotz = m_rotateZSlider;
	float transx = m_translateXSlider;
	float transy = m_translateYSlider;
	float transz = m_translateZSlider;
	float scale = m_scaleSlider;
	m_renderer->renderTransformation(rotx, roty, rotz, transx, transz, transy, scale);
}

void TransformationToolBar::actionItem1(bool & inval) {
	if(!wait){
	unsigned int startIndice = currentPage*5;
	std::vector<GeometryObject*>* objectContainer = m_renderer->getObjects();
	if(startIndice < objectContainer->size()){
		(((*objectContainer)[startIndice])->setSelected(inval));
		}
	}
}

void TransformationToolBar::actionItem2(bool & inval) {
	if(!wait){
	unsigned int startIndice = currentPage*5;
	std::vector<GeometryObject*>* objectContainer = m_renderer->getObjects();
	if(startIndice+1 < objectContainer->size()){
		(((*objectContainer)[startIndice+1])->setSelected(inval));
		}
	}
}

void TransformationToolBar::actionItem3(bool & inval) {
	if(!wait){
	unsigned int startIndice = currentPage*5;
	std::vector<GeometryObject*>* objectContainer = m_renderer->getObjects();
	if(startIndice+2 < objectContainer->size()){
		(((*objectContainer)[startIndice+2])->setSelected(inval));
		}
	}
}

void TransformationToolBar::actionItem4(bool & inval) {
	if(!wait){
	unsigned int startIndice = currentPage*5;
	std::vector<GeometryObject*>* objectContainer = m_renderer->getObjects();
	if(startIndice+3 < objectContainer->size()){
		(((*objectContainer)[startIndice+3])->setSelected(inval));
		}
	}
}

void TransformationToolBar::actionItem5(bool & inval) {

	if(!wait){
	unsigned int startIndice = currentPage*5;
	std::vector<GeometryObject*>* objectContainer = m_renderer->getObjects();
	if(startIndice+4 < objectContainer->size()){
		(((*objectContainer)[startIndice+4])->setSelected(inval));
		}
	}
}
