#pragma once

#include "ofMain.h"
#include "geometryObject.h"

class ParametricMesh : public GeometryObject
{
public:
	ParametricMesh();

	ofPolyline lineRenderer1;
	ofPolyline lineRenderer2;
	ofPolyline lineRenderer3;
	ofPolyline lineRenderer4;

	ofMesh mesh;

	ofVec3f position;

	void setup();
	void draw();

	int lineResolution;
	float radius;
	float lineWidthOutline;
	float lineWidthCurve;
	int index;

	//rotation transformations
	void rotateX(float x);
	void rotateY(float y);
	void rotateZ(float z);

	//translation transformations
	void translateX(float x);
	void translateY(float y);
	void translateZ(float z);

	//scale transformation
	void scale(float scale);

	//instance name
	std::string id();

	bool getSelected();
	void setSelected(bool val);

	ofVec3f pt1;
	ofVec3f pt2;
	ofVec3f pt3;
	ofVec3f pt4;

	ofVec3f v1;
	ofVec3f v2;
	ofVec3f v3;
	ofVec3f v4;
	ofVec3f v5;
	ofVec3f v6;
	ofVec3f v7;
	ofVec3f v8;

	ofVec3f axe1;
	ofVec3f axe2;

	vector<ofVec3f> c1;
	vector<ofVec3f> c2;
	vector<ofVec3f> c3;
	vector<ofVec3f> c4;

	float lerp1x;
	float lerp1y;
	float lerp1z;
	float lerp2x;
	float lerp2y;
	float lerp2z;
	float blerpx;
	float blerpy;
	float blerpz;
	float coonsx;
	float coonsy;
	float coonsz;

	void hermiteCurve(float t,
		float p1x, float p1y, float p1z,
		float p2x, float p2y, float p2z,
		float v1x, float v1y, float v1z,
		float v2x, float v2y, float v2z,
		float&  x, float& y, float&  z);

	~ParametricMesh();

private:
	bool select;

};