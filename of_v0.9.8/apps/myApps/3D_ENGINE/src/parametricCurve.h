#pragma once

#include "ofMain.h"
#include "geometryObject.h"

class ParametricCurve : public GeometryObject
{
public:
	ParametricCurve(string p_curveType);

	ofPolyline lineRenderer;

	ofVec3f ctrlPoint1;
	ofVec3f ctrlPoint2;
	ofVec3f ctrlPoint3;
	ofVec3f ctrlPoint4;
	ofVec3f ctrlPoint5;
	ofVec3f ctrlPoint6;

	ofVec3f position;

	float lineWidthOutline;
	float lineWidthCurve;

	float radius;
	float smooth;
	float offset;

	float xDelta;
	float yDelta;

	int framebufferWidth;
	int framebufferHeight;

	int lineResolution;

	int index;

	void setup();
	void draw();

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
	string curveName;

	bool getSelected();
	void setSelected(bool val);

	~ParametricCurve();

	void hermiteCurve(float t,
		float p1x, float p1y, float p1z,
		float p2x, float p2y, float p2z,
		float v1x, float v1y, float v1z,
		float v2x, float v2y, float v2z,
		float&  x, float& y, float&  z);

	void bezierQuadratic(
		float t,
		float p1x, float p1y, float p1z,
		float p2x, float p2y, float p2z,
		float p3x, float p3y, float p3z,
		float&  x, float& y, float&  z);
	void bezierCubic(
		float t,
		float p1x, float p1y, float p1z,
		float p2x, float p2y, float p2z,
		float p3x, float p3y, float p3z,
		float p4x, float p4y, float p4z,
		float&  x, float& y, float&  z);
	void bezierSix(
		float t,
		float p1x, float p1y, float p1z,
		float p2x, float p2y, float p2z,
		float p3x, float p3y, float p3z,
		float p4x, float p4y, float p4z,
		float p5x, float p5y, float p5z,
		float p6x, float p6y, float p6z,
		float&  x, float& y, float&  z);

private:
	string m_curveType;
	bool select;
};