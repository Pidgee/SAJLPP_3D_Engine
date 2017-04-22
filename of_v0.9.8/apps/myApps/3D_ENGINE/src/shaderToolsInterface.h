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

private:
	ofxPanel m_shaderPanel;
	ofxButton m_colorShaderButton;
	Renderer* m_renderer;
	bool visible;

};





#endif /* SRC_SHADERTOOLSINTERFACE_H_ */
