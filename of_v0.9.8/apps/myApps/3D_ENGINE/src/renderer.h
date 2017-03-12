#pragma once

#include <vector>
#include "ofMain.h"
#include "particleCloud.h"
#include "imageObjet.h"

class Renderer
{
public:

	ofFbo fbo;
	Renderer();
		

	void setup();
	void update();
	void draw();

	//getters
	std::vector<GeometryObject*>* getObjects();
	int getNumberOfObjects();

	//geometryTools
	void renderParticleCloud();

	//imageTools
	void renderImage(ofImage* image, string nom, int x, int y, int z);
	void renderImage(ofImage* image, string nom, int x, int y, int z, ofColor couleur);
	void renderImage(ofImage* image, string nom, int x, int y, int z, ofImage* image1);
	void exporter();
	ofVec3f convertionRGB_HSV(ofColor couleur);

	//transformationTools
	void renderTransformation();
	ofEasyCam cam;

	~Renderer();

private:
	//geometryObject container
	std::vector<GeometryObject*> geometryObjectContainer;

};
