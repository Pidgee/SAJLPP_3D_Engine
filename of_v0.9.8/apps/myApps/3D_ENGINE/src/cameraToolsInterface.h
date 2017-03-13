#include "ofxGui.h"
#include "renderer.h"

#ifndef SRC_CAMERATOOLSINTERFACE_H_
#define SRC_CAMERATOOLSINTERFACE_H_

class CameraToolBar
{
public:
	CameraToolBar(Renderer* p_renderer);

	void setup();
	void draw();
	void show();
	void hide();
	void button();

private:
	ofxPanel m_cameraPanel;
	Renderer* m_renderer;

	ofParameter<bool> toggleEasyCam;
	ofParameter<bool> projMode;
	ofParameter<float> sliderFOV;
	ofParameter<float> sliderNearClip;
	ofParameter<float> slideFarClip;
	ofParameter<float> sliderAspectRatio;

	bool visible;
	bool useEasyCam;
};

#endif /* SRC_CAMERATOOLSINTERFACE_H_ */
