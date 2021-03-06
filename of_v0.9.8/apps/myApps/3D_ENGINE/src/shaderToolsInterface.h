/*
 * shaderToolsInterface.h
 *
 *  Created on: Apr 22, 2017
 *  Author: ada
 */
#include "ofxGui.h"
#include "renderer.h"

#ifndef SRC_SHADERTOOLSINTERFACE_H_
#define SRC_SHADERTOOLSINTERFACE_H_


class ShaderToolBar
{

public:

	ShaderToolBar(Renderer* p_renderer);

	void setup();
	void draw();
	void show();
	void hide();
	void colorShader();
	void displacementShader();
	void blurShader();
	void disableShaders();

private:
	ofxPanel m_shaderPanel;
	ofxButton m_noShader;
	ofxButton m_colorShaderButton;
	ofxButton m_displacementShaderButton;
	ofxButton m_blurShaderButton;
	Renderer* m_renderer;
	bool visible;

};


#endif /* SRC_SHADERTOOLSINTERFACE_H_ */
