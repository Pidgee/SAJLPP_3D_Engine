/*
 * drawToolsInterface.h
 *
 *  Created on: Mar 9, 2017
 *      Author: ada
 */
#include "ofxGui.h"
#include "renderer.h"

#ifndef SRC_DRAWTOOLSINTERFACE_H_
#define SRC_DRAWTOOLSINTERFACE_H_



class DrawToolBar
{
public:

	DrawToolBar(Renderer* p_renderer);

	void setup();
	void draw();
	void show();
	void hide();
	void mousePressed(int x, int y, int button);
	void mouseReleased(int x, int y, int button);
	void mouseMoved(int x, int y);
	void mouseDragged(int x, int y);
	void mouseEntered(int x, int y);
	void mouseExited(int x, int y);

	bool lineDrawingActivated;
	bool triangleDrawingActivated;
	bool circleDrawingActivated;

private:
	int compteur;
	float x1;
	float x2;
	float x3;
	float y1;
	float y2;
	float y3;
	ofxPanel m_drawPanel;
	ofxButton m_raytracingButton;
	ofxButton m_newDrawingButton;
	ofxButton m_lineButton;
	ofxButton m_triangleButton;
	ofxButton m_circleButton;
	ofxButton m_saveDrawingButton;
	Renderer* m_renderer;
	bool visible;
	void raytracing();
	void renderDrawing();
	void lineDrawing();
	void triangleDrawing();
	void circleDrawing();
	void saveDrawing();

};



#endif /* SRC_DRAWTOOLSINTERFACE_H_ */
