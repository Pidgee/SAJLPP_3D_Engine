#pragma once

#include <vector>
#include "ofMain.h"
#include "particleCloud.h"
#include "geometryPrimitive.h"
#include "importModel.h"
#include "proceduralGeometry.h"
#include "imageObjet.h"

class Renderer
{
public:

	ofFbo fbo;

	Renderer();

	ParticleCloud * particleCloud;
		

	void setup();
	void exporter();
	ofVec3f convertionRGB_HSV(ofColor couleur);
	void update();

	void draw();

	//geometryTools
	void renderParticleCloud();
	void renderSphere();
	void renderCube();
	void renderCylinder();
	void renderCone();
	void renderModel(string path);
	void renderProcedural(string path);

	//imageTools
	void renderImage(ofImage* image, string nom, int x, int y, int z);
	void renderImage(ofImage* image, string nom, int x, int y, int z, ofColor couleur);
	void renderImage(ofImage* image, string nom, int x, int y, int z, ofImage* image1);

	ofEasyCam cam;

	~Renderer();

private:
	//geometryObject container
	std::vector<GeometryObject*> geometryObjectContainer;

};
