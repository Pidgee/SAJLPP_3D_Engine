#pragma once

#include "ofMain.h"

#include "renderer.h"
#include "menuInterface.h"
#include "geometryToolsInterface.h"


class ofApp : public ofBaseApp{

	public:

		Renderer * renderer;

		//Interface Tools
		MenuBar * menuBar;
		GeometryToolBar *geometryToolBar;

		void setup();
		void update();
		void draw();

		void keyPressed(int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y );
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void mouseEntered(int x, int y);
		void mouseExited(int x, int y);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);
		
		//menu bar gui
		ofxPanel menuPanel;
		ofxButton geometryTools;
		ofxButton drawTools;
		ofxButton imageTools;
		ofxButton cameraTools;

		//geometry toolbar
		ofxPanel geometryPanel;
		ofxButton particleCloudButton;
};
