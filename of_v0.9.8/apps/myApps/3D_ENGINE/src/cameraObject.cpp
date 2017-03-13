/*
 * cameraObject.cpp
 *
 *  Created on: Mar 12, 2017
 *      Author: ada
 */
#include "cameraObject.h"

CameraObject::CameraObject() {

}

void CameraObject::setup() {

	cam.setPosition(0,0,0);
	cameraParameters.add(projMode.set("Projection Mode", false));
	cameraParameters.add(sliderFOV.set("FOV", 30, 20 , 120));
	cameraParameters.add(slideFarClip.set("Far Clip", 13000, 10000 , 50000));
	cameraParameters.add(sliderNearClip.set("Near Clip", 10, 13 , 50));
	cameraParameters.add(sliderAspectRatio.set("Aspect Ratio", 1, 0.5 , 2));
}

void CameraObject::draw() {
	//void
}

void CameraObject::update() {
	cam.setAspectRatio(sliderAspectRatio);
	cam.setNearClip(sliderNearClip);
	cam.setFarClip(slideFarClip);
	cam.setFov(sliderFOV);
	bool  mode = projMode;
	if(!mode)
		cam.disableOrtho();
	else
		cam.enableOrtho();

}


bool CameraObject::getSelected() {
}

void CameraObject::setSelected(bool val) {
}

void CameraObject::rotateX(float x) {
}

void CameraObject::rotateY(float y) {
}

void CameraObject::rotateZ(float z) {
}

void CameraObject::translateX(float x) {
}

void CameraObject::translateY(float y) {
}

void CameraObject::translateZ(float z) {
}

void CameraObject::scale(float scale) {
}


std::string CameraObject::id() {
}
