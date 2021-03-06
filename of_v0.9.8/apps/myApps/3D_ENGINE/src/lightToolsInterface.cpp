/*
* lightToolsInterface.cpp
*
*  Created on: Mar 8, 2017
*      Author: ada
*/
#include "lightToolsInterface.h"
#include "stdio.h"

LightToolBar::LightToolBar(Renderer* p_renderer) :
	m_lightPanel(ofxPanel()), m_ambientButton(ofxButton()), m_directionnelButton(ofxButton()), m_pointButton(ofxButton()), m_spotButton(ofxButton()), m_renderer(p_renderer), visible(false) {
	m_ambientButton.addListener(this, &LightToolBar::ambient);
	m_directionnelButton.addListener(this, &LightToolBar::directionel);
	m_pointButton.addListener(this, &LightToolBar::point);
	m_spotButton.addListener(this, &LightToolBar::spot);
	m_glaceButton.addListener(this, &LightToolBar::materialGlace);
	m_natureButton.addListener(this, &LightToolBar::materialNature);
	m_magmaButton.addListener(this, &LightToolBar::materialMagma);
	m_luneButton.addListener(this, &LightToolBar::materialLune);
}

void LightToolBar::setup() {
	m_lightPanel.setup();
	m_lightPanel.setName("Light Tools");
	m_lightPanel.setPosition(1385, 470);
	m_lightPanel.add(m_ambientButton.setup("Lumiere ambiente"));
	m_lightPanel.add(m_directionnelButton.setup("Lumiere directionnelle"));
	m_lightPanel.add(m_pointButton.setup("Lumiere point"));
	m_lightPanel.add(m_spotButton.setup("Lumiere spotlight"));
	m_lightPanel.add(m_glaceButton.setup("Materiaux glace"));
	m_lightPanel.add(m_natureButton.setup("Materiaux nature"));
	m_lightPanel.add(m_magmaButton.setup("Materiaux magma"));
	m_lightPanel.add(m_luneButton.setup("Materiaux lune"));


	m_lightPanel.setSize(200, 200);
	m_ambientButton.setSize(200, 15);
	m_directionnelButton.setSize(200, 15);
	m_pointButton.setSize(200, 15);
	m_spotButton.setSize(200, 15);
	m_glaceButton.setSize(200, 15);
	m_natureButton.setSize(200, 15);
	m_magmaButton.setSize(200, 15);
	m_luneButton.setSize(200, 15);


}

void LightToolBar::draw() {
	if (visible)
		m_lightPanel.draw();
	if (ouvert_boite)
		m_boiteInfo.draw();
}

void LightToolBar::show() {
	visible = true;
}

void LightToolBar::hide() {
	visible = false;
}

void LightToolBar::ambient() {

	m_boiteInfo.setup();
	m_boiteInfo.setName("Lumiere ambiente");
	m_boiteInfo.setPosition(1385, 640);
	m_boiteInfo.setSize(200, 200);

	m_RSlider.setSize(200, 15);
	m_GSlider.setSize(200, 15);
	m_BSlider.setSize(200, 15);
	m_confirm.setSize(200, 15);

	m_boiteInfo.add(m_RSlider.setup("Composante rouge:", 0, 0, 255));
	m_boiteInfo.add(m_GSlider.setup("Composante verte:", 0, 0, 255));
	m_boiteInfo.add(m_BSlider.setup("Composante bleu:", 0, 0, 255));
	m_boiteInfo.add(m_confirm.setup("Confirmation"));

	m_confirm.addListener(this, &LightToolBar::fermerBoiteAmbient);

	ouvert_boite = true;

}

void LightToolBar::fermerBoiteAmbient() {

	float r = m_RSlider;
	float g = m_GSlider;
	float b = m_BSlider;

	ofColor couleur(r, g, b);

	m_renderer->ajouterLumiere(couleur);

	m_boiteInfo.clear();
	m_confirm.removeListener(this, &LightToolBar::fermerBoiteAmbient);

	ouvert_boite = false;

}

void LightToolBar::demanderInfo() {

}

void LightToolBar::directionel() {

	type = 1;
	
	m_boiteInfo.setup();
	m_boiteInfo.setName("Lumiere directionnelle");
	m_boiteInfo.setPosition(1385, 640);
	m_boiteInfo.setSize(200, 200);

	m_RSlider.setSize(200, 15);
	m_GSlider.setSize(200, 15);
	m_BSlider.setSize(200, 15);
	m_XSlider.setSize(200, 15);
	m_YSlider.setSize(200, 15);
	m_ZSlider.setSize(200, 15);
	m_confirm.setSize(400, 15);

	m_boiteInfo.add(m_RSlider.setup("Composante rouge:", 0, 0, 255));
	m_boiteInfo.add(m_GSlider.setup("Composante verte:", 0, 0, 255));
	m_boiteInfo.add(m_BSlider.setup("Composante bleu:", 0, 0, 255));
	m_boiteInfo.add(m_XSlider.setup("Angle x:", 0, -180, 180));
	m_boiteInfo.add(m_YSlider.setup("Angle y:", 0, -180, 180));
	m_boiteInfo.add(m_ZSlider.setup("Angle z:", 0, -180, 180));
	m_boiteInfo.add(m_confirm.setup("Confirmation"));

	m_confirm.addListener(this, &LightToolBar::fermerBoiteDirection);

	ouvert_boite = true;
	
}

void LightToolBar::fermerBoiteDirection() {
	
	float r = m_RSlider;
	float g = m_GSlider;
	float b = m_BSlider;
	float x = m_XSlider;
	float y = m_YSlider;
	float z = m_ZSlider;

	ofColor couleur(r, g, b);
	ofVec3f direction(x,y,z);

	m_renderer->ajouterLumiere(type, direction, couleur);

	m_boiteInfo.clear();
	m_confirm.removeListener(this, &LightToolBar::fermerBoiteDirection);

	ouvert_boite = false;
	
}

void LightToolBar::point() {

	type = 0;

	m_boiteInfo.setup();
	m_boiteInfo.setName("Lumiere point");
	m_boiteInfo.setPosition(1385, 640);
	m_boiteInfo.setSize(200, 200);

	m_RSlider.setSize(200, 15);
	m_GSlider.setSize(200, 15);
	m_BSlider.setSize(200, 15);
	m_XSlider.setSize(200, 15);
	m_YSlider.setSize(200, 15);
	m_ZSlider.setSize(200, 15);
	m_confirm.setSize(400, 15);

	m_boiteInfo.add(m_RSlider.setup("Composante rouge:", 0, 0, 255));
	m_boiteInfo.add(m_GSlider.setup("Composante verte:", 0, 0, 255));
	m_boiteInfo.add(m_BSlider.setup("Composante bleu:", 0, 0, 255));
	m_boiteInfo.add(m_XSlider.setup("Position x:", 0, -800, 800));
	m_boiteInfo.add(m_YSlider.setup("Position y:", 0, -800, 800));
	m_boiteInfo.add(m_ZSlider.setup("Position z:", 0, -800, 800));
	m_boiteInfo.add(m_confirm.setup("Confirmation"));

	m_confirm.addListener(this, &LightToolBar::fermerBoiteDirection);

	ouvert_boite = true;

}

void LightToolBar::spot() {

	m_boiteInfo.setup();
	m_boiteInfo.setName("Lumiere Spotlight");
	m_boiteInfo.setPosition(1385, 640);
	m_boiteInfo.setSize(200, 200);

	m_RSlider.setSize(200, 15);
	m_GSlider.setSize(200, 15);
	m_BSlider.setSize(200, 15);
	m_XSlider.setSize(200, 15);
	m_YSlider.setSize(200, 15);
	m_ZSlider.setSize(200, 15);
	m_OXSlider.setSize(200, 15);
	m_OYSlider.setSize(200, 15);
	m_OZSlider.setSize(200, 15);
	m_confirm.setSize(400, 15);

	m_boiteInfo.add(m_RSlider.setup("Composante rouge:", 0, 0, 255));
	m_boiteInfo.add(m_GSlider.setup("Composante verte:", 0, 0, 255));
	m_boiteInfo.add(m_BSlider.setup("Composante bleu:", 0, 0, 255));
	m_boiteInfo.add(m_XSlider.setup("Position x:", 0, -800, 800));
	m_boiteInfo.add(m_YSlider.setup("Position y:", 0, -800, 800));
	m_boiteInfo.add(m_ZSlider.setup("Position z:", 0, -800, 800));
	m_boiteInfo.add(m_OXSlider.setup("Orienter vers point(x):", 0, -800, 800));
	m_boiteInfo.add(m_OYSlider.setup("Orienter vers point(y):", 0, -800, 800));
	m_boiteInfo.add(m_OZSlider.setup("Orienter vers point(z):", 0, -800, 800));
	m_boiteInfo.add(m_confirm.setup("Confirmation"));

	m_confirm.addListener(this, &LightToolBar::fermerBoiteSpot);

	ouvert_boite = true;

}

void LightToolBar::fermerBoiteSpot() {

	float r = m_RSlider;
	float g = m_GSlider;
	float b = m_BSlider;
	float x = m_XSlider;
	float y = m_YSlider;
	float z = m_ZSlider;
	float ox = m_OXSlider;
	float oy = m_OYSlider;
	float oz = m_OZSlider;

	ofColor couleur(r, g, b);
	ofVec3f position(x, y, z);
	ofVec3f direction(ox, oy, oz);

	m_renderer->ajouterLumiere(position, direction, couleur);

	m_boiteInfo.clear();
	m_confirm.removeListener(this, &LightToolBar::fermerBoiteSpot);

	ouvert_boite = false;

}

void LightToolBar::materialGlace() {

	ofMaterial material;

	material.setSpecularColor(ofColor(255, 255, 255));
	material.setDiffuseColor(ofColor(43, 250, 250));
	material.setAmbientColor(ofColor(128, 208, 208));
	material.setShininess(10);

	m_renderer->setMaterial(material);

}

void LightToolBar::materialNature() {

	ofMaterial material;

	material.setSpecularColor(ofColor(151, 223, 198));
	material.setDiffuseColor(ofColor(58, 242, 75));
	material.setAmbientColor(ofColor(58, 137, 35));
	material.setShininess(9);

	m_renderer->setMaterial(material);

}

void LightToolBar::materialMagma() {

	ofMaterial material;

	material.setSpecularColor(ofColor(204, 78, 92));
	material.setDiffuseColor(ofColor(247, 35, 12));
	material.setAmbientColor(ofColor(188, 32, 1));
	material.setShininess(8);

	m_renderer->setMaterial(material);

}

void LightToolBar::materialLune() {

	ofMaterial material;

	material.setSpecularColor(ofColor(239, 239, 239));
	material.setDiffuseColor(ofColor(199, 208, 204));
	material.setAmbientColor(ofColor(103, 113, 121));
	material.setShininess(10);

	m_renderer->setMaterial(material);

}
