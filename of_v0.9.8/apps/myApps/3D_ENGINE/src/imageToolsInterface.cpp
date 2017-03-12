/*
 * imageToolsInterface.cpp
 *
 *  Created on: Mar 8, 2017
 *      Author: ada
 */
#include "imageToolsInterface.h"
#include "stdio.h"

ImageToolBar::ImageToolBar(Renderer* p_renderer):
	m_imagePanel(ofxPanel()), m_importButton(ofxButton()), m_exportButton(ofxButton()), m_teinte(ofxButton()),m_composition(ofxButton()), m_renderer(p_renderer), visible(false){
	m_exportButton.addListener(this, &ImageToolBar::exporter);
	m_importButton.addListener(this, &ImageToolBar::importer);
	m_teinte.addListener(this, &ImageToolBar::teinte);
	m_composition.addListener(this, &ImageToolBar::composition);
}

void ImageToolBar::setup() {
	m_imagePanel.setup();
	m_imagePanel.setName("Image Tools");
	m_imagePanel.setPosition(5,90);
	m_imagePanel.add(m_importButton.setup("Import Image"));
	m_imagePanel.add(m_exportButton.setup("Export Image"));
	m_imagePanel.add(m_teinte.setup("Teinte Image"));
	m_imagePanel.add(m_composition.setup("Composition Image"));


	m_imagePanel.setSize(150,200);
	m_importButton.setSize(150,15);
	m_exportButton.setSize(150,15);
	m_teinte.setSize(150, 15);
	m_composition.setSize(150, 15);


}

void ImageToolBar::draw() {
	if(visible)
		m_imagePanel.draw();
}

void ImageToolBar::show() {
	visible=true;
}

void ImageToolBar::hide() {
	visible=false;
}

void ImageToolBar::importer() {

	ofFileDialogResult resultat = ofSystemLoadDialog("Importation d'image");

	if (resultat.bSuccess) {

		ofImage temp;

		string chemin = resultat.filePath;

		string nom = resultat.fileName;

		string nom_complet = chemin;

		temp.load(chemin);

		ofVec3f coordonnee = demanderInfo();

		m_renderer->renderImage(&temp, nom, coordonnee.x, coordonnee.y, coordonnee.z);

	}

}

ofVec3f ImageToolBar::demanderInfo() {

	ofVec3f coordonnees;

	string s_x;

	string s_y;

	string s_z;

	s_x = ofSystemTextBoxDialog("Quel est la coordonnee en x de l'image?");

	s_y = ofSystemTextBoxDialog("Quel est la coordonnee en y de l'image?");

	s_z = ofSystemTextBoxDialog("Quel est la coordonnee en z de l'image?");

	coordonnees[0] = stof(s_x);

	coordonnees[1] = stof(s_y);

	coordonnees[2] = stof(s_z);

	return coordonnees;

}

void ImageToolBar::teinte() {

	ofFileDialogResult resultat = ofSystemLoadDialog("Choisir image");

	if (resultat.bSuccess) {

		ofImage temp;

		string chemin = resultat.filePath;

		string nom = resultat.fileName;

		string nom_complet = chemin;

		temp.load(nom_complet);

		ofVec3f coordonnee = demanderInfo();

		string s_r;

		string s_g;

		string s_b;

		string s_a;

		s_r = ofSystemTextBoxDialog("Quel est la composante en rouge de la teinte?");

		s_g = ofSystemTextBoxDialog("Quel est la composante en vert de la teinte?");

		s_b = ofSystemTextBoxDialog("Quel est la composante en bleu de la teinte?");

		s_a = ofSystemTextBoxDialog("Quel est la composante alpha de la teinte?");

		int r = stoi(s_r);

		int g = stoi(s_g);

		int b = stoi(s_b);

		int a = stoi(s_a);

		ofColor couleur(r, g, b, a);

		m_renderer->renderImage(&temp, nom, coordonnee.x, coordonnee.y, coordonnee.z, couleur);

	}
}

void ImageToolBar::composition() {

	ofFileDialogResult resultat = ofSystemLoadDialog("Choisir image");

	if (resultat.bSuccess) {

		ofImage temp;

		string chemin = resultat.filePath;

		string nom = resultat.fileName;

		string nom_complet = chemin;

		temp.load(nom_complet);

		ofVec3f coordonnee = demanderInfo();

		ofFileDialogResult resultat1 = ofSystemLoadDialog("Choisir autre image");

		if (resultat1.bSuccess) {

			ofImage temp1;

			string chemin1 = resultat1.filePath;

			string nom1 = resultat1.fileName;

			string nom_complet1 = chemin1;

			temp1.load(nom_complet1);

			m_renderer->renderImage(&temp, nom, coordonnee.x, coordonnee.y, coordonnee.z, &temp1);

		}

	}
}

void ImageToolBar::exporter() {

	m_renderer->exporter();

}







