/*
 * shaderToolsInterface.cpp
 *
 *  Created on: Apr 22, 2017
 *      Author: ada
 */
#include "shaderToolsInterface.h"



ShaderToolBar::ShaderToolBar(Renderer* p_renderer):m_renderer(p_renderer), visible(false), m_colorShaderButton(ofxButton()) {
	m_colorShaderButton.addListener(this,  &ShaderToolBar::colorShader);



}

void ShaderToolBar::setup() {

	m_shaderPanel.setup();
	m_shaderPanel.setName("Shaders");
	m_shaderPanel.setPosition(5,90);
	m_shaderPanel.add(m_colorShaderButton.setup("Simple Color Shader"));

	m_shaderPanel.setSize(150,200);
	m_colorShaderButton.setSize(150,15);
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
