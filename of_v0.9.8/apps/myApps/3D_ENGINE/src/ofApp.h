#pragma once

#include "ofMain.h"

#include "renderer.h"
#include "menuInterface.h"
#include "geometryToolsInterface.h"
#include "imageToolsInterface.h"
#include "drawToolsInterface.h"
#include "transformToolsInterface.h"
#include "shaderToolsInterface.h"


class ofApp : public ofBaseApp {

public:

	Renderer* renderer;

		//Interface Tools
		MenuBar* menuBar;
		GeometryToolBar* geometryToolBar;
		ImageToolBar* imageToolBar;
		DrawToolBar* drawToolBar;
		TransformationToolBar* transformationToolBar;
		ShaderToolBar* shaderToolBar;

	void setup();
	void update();
	void draw();

	void keyPressed(int key);
	void keyReleased(int key);
	void mouseMoved(int x, int y);
	void mouseDragged(int x, int y, int button);
	void mousePressed(int x, int y, int button);
	void mouseReleased(int x, int y, int button);
	void mouseEntered(int x, int y);
	void mouseExited(int x, int y);
	void windowResized(int w, int h);
	void dragEvent(ofDragInfo dragInfo);
	void gotMessage(ofMessage msg);





};
