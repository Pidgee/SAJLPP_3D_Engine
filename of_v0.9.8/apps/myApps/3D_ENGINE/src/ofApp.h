#pragma once

#include "ofMain.h"

#include "renderer.h"
#include "menuInterface.h"
#include "geometryToolsInterface.h"
#include "imageToolsInterface.h"
#include "drawToolsInterface.h"
#include "transformToolsInterface.h"


class ofApp : public ofBaseApp{

	public:

		Renderer* renderer;

		//Interface Tools
		MenuBar* menuBar;
		GeometryToolBar* geometryToolBar;
		ImageToolBar* imageToolBar;
		DrawToolBar* drawToolBar;
		TransformationToolBar* transformationToolBar;

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
		
		//menu bar widgets
		ofxPanel menuPanel;
		ofxButton geometryTools;
		ofxButton drawTools;
		ofxButton imageTools;
		ofxButton cameraTools;

		//geometry toolbar widgets
		ofxPanel geometryPanel;
		ofxButton particleCloudButton;

		//image toolbar widgets
		ofxPanel imagePanel;
		ofxButton importButton;
		ofxButton exportButton;
		ofxButton teinteButton;
		ofxButton compositionButton;

		//draw toolbar widgets
		ofxPanel drawPanel;
		ofxButton lineButton;
		ofxButton triangleButton;
		ofxButton circleButton;

		//transform toolbar widgets
		ofxPanel transformPanel;
		ofxFloatSlider rotateXSlider;
		ofxFloatSlider rotateYSlider;
		ofxFloatSlider rotateZSlider;
		ofxFloatSlider translateXSlider;
		ofxFloatSlider translateYSlider;
		ofxFloatSlider translateZSlider;
		ofxFloatSlider scaleSlider;
		ofxButton transformButton;





};
