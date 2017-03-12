

#include "imageObjet.h"

imageObjet::imageObjet() {}

void imageObjet::setup()
{
}

void imageObjet::setImage(ofImage * image_param) {

	image = *image_param;
}


void imageObjet::draw()
{

	ofTexture texture = image.getTexture();

	texture.draw(p2,p4,p3,p1);
	
}

void imageObjet::rotateX(/*int angle*/) {

	//p1.set(p1.x, p1.y* cos(angle) + p1.z * sin(angle), p1.z *cos(angle) - p1.y*sin(angle));
	//p2.set(p2.x, p2.y* cos(angle) + p2.z * sin(angle), p2.z *cos(angle) - p2.y*sin(angle));
	//p3.set(p3.x, p3.y* cos(angle) + p3.z * sin(angle), p3.z *cos(angle) - p3.y*sin(angle));
	//p4.set(p4.x, p4.y* cos(angle) + p4.z * sin(angle), p4.z *cos(angle) - p4.y*sin(angle));

}

void imageObjet::rotateY(/*int angle*/) {

	//p1.set(p1.x* cos(angle) + p1.z * sin(angle), p1.y, p1.z *cos(angle) - p1.x*sin(angle));
	//p2.set(p2.x* cos(angle) + p2.z * sin(angle), p2.y, p2.z *cos(angle) - p2.x*sin(angle));
	//p3.set(p3.x* cos(angle) + p3.z * sin(angle), p3.y, p3.z *cos(angle) - p3.x*sin(angle));
	//p4.set(p4.x* cos(angle) + p4.z * sin(angle), p4.y, p4.z *cos(angle) - p4.x*sin(angle));

}

void imageObjet::rotateZ(/*int angle*/) {

	//p1.set(p1.x * cos(angle) + p1.y * sin(angle), p1.y*cos(angle) - p1.x*sin(angle), p1.z);
	//p2.set(p2.x * cos(angle) + p2.y * sin(angle), p2.y*cos(angle) - p2.x*sin(angle), p2.z);
	//p3.set(p3.x * cos(angle) + p3.y * sin(angle), p3.y*cos(angle) - p3.x*sin(angle), p3.z);
	//p4.set(p4.x * cos(angle) + p4.y * sin(angle), p4.y*cos(angle) - p4.x*sin(angle), p4.z);

}

void imageObjet::translateX(/*int valeur*/) {

	//coordX += valeur;

	//p1.set(p1.x + valeur, p1.y, p1.z);
	//p2.set(p2.x + valeur, p2.y, p2.z);
	//p3.set(p3.x + valeur, p3.y, p3.z);
	//p4.set(p4.x + valeur, p4.y, p4.z);
}

void imageObjet::translateY(/*int valeur*/) {

	//coordY += valeur;

	//p1.set(p1.x, p1.y + valeur, p1.z);
	//p2.set(p2.x, p2.y + valeur, p2.z);
	//p3.set(p3.x, p3.y + valeur, p3.z);
	//p4.set(p4.x, p4.y + valeur, p4.z);
	
}

void imageObjet::translateZ(/*int valeur*/) {

	//coordZ += valeur;

	//p1.set(p1.x, p1.y, p1.z + valeur);
	//p2.set(p2.x, p2.y, p2.z + valeur);
	//p3.set(p3.x, p3.y, p3.z + valeur);
	//p4.set(p4.x, p4.y, p4.z + valeur);

}

void imageObjet::scale(/*float proportion*/) {

	//width *= proportion;
	//height *= proportion;

	//p1.set(p1.x * proportion, p1.y * proportion, p1.z * proportion);
	//p2.set(p2.x * proportion, p2.y * proportion, p2.z * proportion);
	//p3.set(p3.x * proportion, p3.y * proportion, p3.z * proportion);
	//p4.set(p4.x * proportion, p4.y * proportion, p4.z * proportion);

}

std::string imageObjet::id() {
	return nom;
}

ofImage imageObjet::ajouter_teinte(ofColor couleur){

	ofColor couleur_ancienne;

	ofColor couleur_nouvelle;

	for (int x = 0; x < image.getWidth(); x++) {
		for (int y = 0; y < image.getHeight(); y++) {
			couleur_ancienne = image.getColor(x, y);

			if (couleur_ancienne.r + couleur.r > 255) {
				couleur_nouvelle.r = 255;
			}
			else {
				couleur_nouvelle.r = couleur_ancienne.r + couleur.r;
			}
			if (couleur_ancienne.g + couleur.g > 255) {
				couleur_nouvelle.g = 255;
			}
			else {
				couleur_nouvelle.g = couleur_ancienne.g + couleur.g;
			}
			if (couleur_ancienne.b + couleur.b > 255) {
				couleur_nouvelle.b = 255;
			}
			else {
				couleur_nouvelle.b = couleur_ancienne.b + couleur.b;
			}
			if (couleur_ancienne.a + couleur.a > 255) {
				couleur_nouvelle.a = 255;
			}
			else {
				couleur_nouvelle.a = couleur_ancienne.a + couleur.a;
			}
			image.setColor(x, y, couleur_nouvelle);
		}
	}

	return image;

}

ofImage imageObjet::ajouter_image(ofImage * image_param) {

	ofImage image_ajout = *image_param;

	ofColor couleur_ancienne;
	ofColor couleur_ancienne1;
	ofColor couleur_nouvelle;

	for (int x = 0; x < image.getWidth(); x++) {
		for (int y = 0; y < image.getHeight(); y++) {
			couleur_ancienne = image.getColor(x, y);
			couleur_ancienne1 = image_ajout.getColor(x, y);

			if (couleur_ancienne.r + couleur_ancienne1.r > 255) {
				couleur_nouvelle.r = 255;
			}
			else {
				couleur_nouvelle.r = couleur_ancienne.r + couleur_ancienne1.r;
			}
			if (couleur_ancienne.g + couleur_ancienne1.g > 255) {
				couleur_nouvelle.g = 255;
			}
			else {
				couleur_nouvelle.g = couleur_ancienne.g + couleur_ancienne1.g;
			}
			if (couleur_ancienne.b + couleur_ancienne1.b > 255) {
				couleur_nouvelle.b = 255;
			}
			else {
				couleur_nouvelle.b = couleur_ancienne.b + couleur_ancienne1.b;
			}
			if (couleur_ancienne.a + couleur_ancienne1.a > 255) {
				couleur_nouvelle.a = 255;
			}
			else {
				couleur_nouvelle.a = couleur_ancienne.a + couleur_ancienne1.a;
			}
			image.setColor(x, y, couleur_nouvelle);
		}
	}

	return image;

}

imageObjet::~imageObjet()
{

}