/*
 * shaderToolsInterface.cpp
 *
 *  Created on: Apr 22, 2017
 *      Author: ada
 */
#include "shaderToolsInterface.h"



ShaderToolBar::ShaderToolBar(Renderer* p_renderer):m_renderer(p_renderer), visible(false), m_colorShaderButton(ofxButton()), m_displacementShaderButton(ofxButton()),
							m_noShader(ofxButton()){
	m_colorShaderButton.addListener(this,  &ShaderToolBar::colorShader);
	m_displacementShaderButton.addListener(this,  &ShaderToolBar::displacementShader);
	m_noShader.addListener(this, &ShaderToolBar::disableShaders);
}

void ShaderToolBar::setup() {

	m_shaderPanel.setup();
	m_shaderPanel.setName("Shaders");
	m_shaderPanel.setPosition(5,90);
	m_shaderPanel.add(m_noShader.setup("No Shaders"));
	m_shaderPanel.add(m_colorShaderButton.setup("Colorful"));
	m_shaderPanel.add(m_displacementShaderButton.setup("Displacement"));

	m_shaderPanel.setSize(150,200);
	m_noShader.setSize(150, 15);
	m_colorShaderButton.setSize(150,15);
	m_displacementShaderButton.setSize(150,15);
}

void ShaderToolBar::draw() {
	if(visible)
		m_shaderPanel.draw();
}

void ShaderToolBar::show() {
	visible=true;
}

void ShaderToolBar::hide() {
	visible=false;
}

void ShaderToolBar::colorShader() {
	m_renderer->enableColorShader();
}

void ShaderToolBar::displacementShader() {
	m_renderer->enableDisplacementShader();
}

void ShaderToolBar::disableShaders() {
	m_renderer->disableShaders();
}
