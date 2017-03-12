#pragma once

#include <vector>
#include "ofMain.h"
#include "particleCloud.h"
#include "drawing.h"
#include "imageObjet.h"

class Renderer
{
public:

	ofFbo fbo;
	Drawing* drawing;

	Renderer();

	ParticleCloud * particleCloud;
		

	void setup();
	void exporter();
	ofVec3f convertionRGB_HSV(ofColor couleur);
	void update();

	void draw();

	void appendObject(GeometryObject*);

	//geometryTools
	void renderParticleCloud();
	void drawLine(float x1, float y1, float x2, float y2);
	void drawTriangle(float x1, float y1, float x2, float y2, float x3, float y3);
	void drawCircle(float x1, float y1, float x2, float y2);
	void renderDrawing();
	void saveDrawing();

	//imageTools
	void renderImage(ofImage* image, string nom, int x, int y, int z);
	void renderImage(ofImage* image, string nom, int x, int y, int z, ofColor couleur);
	void renderImage(ofImage* image, string nom, int x, int y, int z, ofImage* image1);

	ofEasyCam cam;

	~Renderer();

private:
	//geometryObject container
	std::vector<GeometryObject*> geometryObjectContainer;
	bool drawingToolActivated;

};
