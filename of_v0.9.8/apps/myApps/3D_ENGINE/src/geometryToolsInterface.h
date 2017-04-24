/*
 * geometryToolsInterface.h
 *
 *  Created on: Mar 7, 2017
 *      Author: ada
 */
#include "ofxGui.h"
#include "renderer.h"
#include "ofxAssimpModelLoader.h"


#ifndef SRC_GEOMETRYTOOLSINTERFACE_H_
#define SRC_GEOMETRYTOOLSINTERFACE_H_


class GeometryToolBar
{
public:

	GeometryToolBar(Renderer* p_renderer);

	void setup();
	void draw();
	void show();
	void hide();
	void renderParticleCloud();
	void renderSphere();
	void renderCube();
	void renderCylinder();
	void renderCone();
	void renderProcedural();
	void renderModel();

	void renderBezierQuad();
	void renderBezierCubic();
	void renderBezierSix();
	void renderHermiteCurve();

	void renderParametricMesh();

private:
	ofxPanel m_geometryPanel;
	ofxButton m_particleCloudButton;
	ofxButton m_sphereButton;
	ofxButton m_cubeButton;
	ofxButton m_cylinderButton;
	ofxButton m_coneButton;
	ofxButton m_proceduralButton;
	ofxButton m_loadModelButton;

	ofxButton m_bezierQuadButton;
	ofxButton m_bezierCubicButton;
	ofxButton m_bezierSixButton;
	ofxButton m_hermiteCurveButton;

	ofxButton m_parametricMeshButton;

	Renderer* m_renderer;
	bool visible;

};




#endif /* SRC_GEOMETRYTOOLSINTERFACE_H_ */
