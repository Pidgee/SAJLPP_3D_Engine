#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
	ofBackground(100);
	renderer = new Renderer();
	geometryToolBar = new GeometryToolBar(renderer);
	imageToolBar = new ImageToolBar(&imagePanel, &importButton, &exportButton, &teinteButton, &compositionButton, renderer);
	drawToolBar = new DrawToolBar(&drawPanel, &lineButton, &triangleButton, &circleButton);
	transformationToolBar = new TransformationToolBar();
	menuBar = new MenuBar(geometryToolBar, imageToolBar, drawToolBar);

	menuBar->setup();
	transformationToolBar->setup();
	geometryToolBar->setup();
	imageToolBar->setup();
	drawToolBar->setup();
	renderer->setup();

}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){
	menuBar->draw();
	transformationToolBar->draw();
	geometryToolBar->draw();
	imageToolBar->draw();
	drawToolBar->draw();
	renderer->draw();

}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
