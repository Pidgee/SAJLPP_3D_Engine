#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup() {
	ofBackground(100);
	renderer = new Renderer();
	geometryToolBar = new GeometryToolBar(renderer);
	shaderToolBar = new ShaderToolBar(renderer);
	imageToolBar = new ImageToolBar(renderer);
	drawToolBar = new DrawToolBar(renderer);

	transformationToolBar = new TransformationToolBar(renderer);
	menuBar = new MenuBar(geometryToolBar, imageToolBar, drawToolBar, shaderToolBar);

	menuBar->setup();
	transformationToolBar->setup();
	geometryToolBar->setup();
	shaderToolBar->setup();
	imageToolBar->setup();
	drawToolBar->setup();
	renderer->setup();

}

//--------------------------------------------------------------
void ofApp::update() {
	transformationToolBar->update();
	renderer->update();
}

//--------------------------------------------------------------
void ofApp::draw() {
	menuBar->draw();
	transformationToolBar->draw();
	geometryToolBar->draw();
	imageToolBar->draw();
	drawToolBar->draw();
	shaderToolBar->draw();
	renderer->draw();

}

//--------------------------------------------------------------
void ofApp::keyPressed(int key) {

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key) {

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){
	drawToolBar->mouseMoved(x, y);
}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){
	drawToolBar->mouseDragged(x, y);
}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){
	drawToolBar->mousePressed(x, y, button);
}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){
	drawToolBar->mouseReleased(x, y, button);
}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){
	drawToolBar->mouseEntered(x, y);
}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y) {
	drawToolBar->mouseExited(x, y);
}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h) {

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg) {

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo) {

}
