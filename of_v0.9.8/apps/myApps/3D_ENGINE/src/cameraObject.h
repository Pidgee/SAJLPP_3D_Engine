/*
 * cameraObject.h
 *
 *  Created on: Mar 12, 2017
 *      Author: ada
 */
#include "ofMain.h"
#include "geometryObject.h"

#ifndef SRC_CAMERAOBJECT_H_
#define SRC_CAMERAOBJECT_H_

class CameraObject: public GeometryObject{
public:
	CameraObject();

	void setup();
	void draw();
	void update();

	bool getSelected();
	void setSelected(bool val);

	void rotateX(float x);
	void rotateY(float y);
	void rotateZ(float z);
	void translateX(float x);
	void translateY(float y);
	void translateZ(float z);
	void scale(float scale);

	std::string id();

	ofParameterGroup cameraParameters;
	ofEasyCam cam;


private:
	bool select;

	ofParameter<bool> toggleEasyCam;
	ofParameter<bool> projMode;
	ofParameter<float> sliderFOV;
	ofParameter<float> sliderNearClip;
	ofParameter<float> slideFarClip;
	ofParameter<float> sliderAspectRatio;


};





#endif /* SRC_CAMERAOBJECT_H_ */
