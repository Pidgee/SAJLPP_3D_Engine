#pragma once

#include <vector>
#include "ofMain.h"
#include "particleCloud.h"
#include "importModel.h"
#include "proceduralGeometry.h"
#include "geometryPrimitive.h"
#include "drawing.h"
#include "imageObjet.h"
#include "parametricCurve.h"
#include "parametricMesh.h"

class Renderer
{
public:

	ofFbo fbo;
	ofFbo secondaryFbo;
	
	Renderer();


	void setup();
	void update();
	void draw();

	void ajouterLumiere(ofColor couleur);
	void ajouterLumiere(int type, ofVec3f position, ofColor couleur);
	void ajouterLumiere(ofVec3f position, ofVec3f direction, ofColor couleur);
	void setMaterial(ofMaterial materiau);
	//getters
	std::vector<GeometryObject*>* getObjects();
	int getNumberOfObjects();

	//geometryTools
	bool lineCursorActivated;
	bool triangleCursorActivated;
	bool circleCursorActivated;

	int xMouseCurrent;
	int yMouseCurrent;

	void renderParticleCloud();
	void renderSphere();
	void renderCube();
	void renderCylinder();
	void renderCone();
	void renderModel(string path, string name);
	void renderProcedural(string path, string name);
	void drawBlur();

	void raytracing();
	void enableMaterials();
	void enableColorShader();
	void enableDisplacementShader();
	void enableBlurShader();
	void disableShaders();

	void drawLine(float x1, float y1, float x2, float y2);
	void drawTriangle(float x1, float y1, float x2, float y2, float x3, float y3);
	void drawCircle(float x1, float y1, float x2, float y2);
	void renderDrawing();
	void saveDrawing();

	//imageTools
	void renderImage(ofImage* image, string nom, int x, int y, int z);
	void renderImage(ofImage* image, string nom, int x, int y, int z, ofColor couleur);
	void renderImage(ofImage* image, string nom, int x, int y, int z, ofImage* image1);
	void exporter();
	ofVec3f convertionRGB_HSV(ofColor couleur);

	//transformationTools
	void renderTransformation(float rotX, float rotY, float rotZ, float transX, float transY, float transZ, float scale);
	ofEasyCam cam;

	//parametricCurveTools
	void renderBezierQuad();
	void renderBezierCubic();
	void renderBezierSix();
	void renderHermiteCurve();

	void renderParametricMesh();

	~Renderer();

private:
	//geometryObject container
	std::vector<GeometryObject*> geometryObjectContainer;

	std::vector<ofLight> lumiereContainer;

	Drawing* drawing;
	bool drawingToolActivated;

	bool materialsEnabled;
	bool colorShaderEnabled;
	bool displacementShaderEnabled;
	bool blurShaderEnabled;

	ofShader simpleColorShader;
	ofShader displacementShader;
	ofShader blurShader_1;
	ofShader blurShader_2;


	ofMaterial mate;
};

	


