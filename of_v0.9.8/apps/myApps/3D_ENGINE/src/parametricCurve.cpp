

#include "parametricCurve.h"

ParametricCurve::ParametricCurve(string p_curveType) : m_curveType(p_curveType), select(false) {}

void ParametricCurve::setup()
{
	ofSetFrameRate(60);
	ofSetSphereResolution(32);
	ofDisableDepthTest();

	// paramètres
	lineResolution = 100;

	radius = 32.0f;
	offset = 64.0f;

	lineWidthOutline = 4.0f;
	lineWidthCurve = 8.0f;

	motionSpeed = 250.0f;

	// initialisation des sommets de la ligne
	for (index = 0; index <= lineResolution; ++index)
		lineRenderer.addVertex(ofPoint());


	// initialisation de la scène
	reset();
}

void ParametricCurve::reset()
{
	// initialisation des variables
	framebufferWidth = ofGetWidth();
	framebufferHeight = ofGetHeight();

	// ratios de positionnement dans la fenêtre
	float w_1_8 = framebufferWidth / 8.0f;
	float w_1_4 = framebufferWidth / 4.0f;
	float w_1_2 = framebufferWidth / 2.0f;
	float w_3_4 = framebufferWidth * 3.0f / 4.0f;
	float w_7_8 = framebufferWidth * 7.0f / 8.0f;
	float w_8_9 = framebufferWidth * 8.0F / 9.0f;
	float h_1_5 = framebufferHeight / 5.0f;
	float h_1_3 = framebufferHeight / 3.0f;
	float h_4_5 = framebufferHeight * 4.0f / 5.0f;

	initialPosition1 = { w_1_8, h_4_5, 0 };
	initialPosition2 = { w_1_4, h_1_3, 0 };
	initialPosition3 = { w_1_2, h_1_5, 0 };
	initialPosition4 = { w_3_4, h_1_3, 0 };
	initialPosition5 = { w_7_8, h_4_5, 0 };
	initialPosition6 = { w_8_9, h_1_5, 0 };

	// paramètres selon le type de courbe
	if (m_curveType == "bezier_quad")
	{

		curveName = "Bézier quadratique";

		ctrlPoint1 = initialPosition1;
		ctrlPoint2 = initialPosition3;
		ctrlPoint3 = initialPosition5;
		ctrlPoint4 = initialPosition5;
		ctrlPoint5 = initialPosition5;
		ctrlPoint6 = initialPosition5;

	} else if (m_curveType == "bezier_cubic")
	{
		curveName = "Bézier cubique";

		ctrlPoint1 = initialPosition1;
		ctrlPoint2 = initialPosition2;
		ctrlPoint3 = initialPosition4;
		ctrlPoint4 = initialPosition5;
		ctrlPoint5 = initialPosition5;
		ctrlPoint6 = initialPosition5;

	}

	else if (m_curveType == "bezier_six") {

		curveName = "Bézier à six points de contrôle";

		ctrlPoint1 = initialPosition1;
		ctrlPoint2 = initialPosition2;
		ctrlPoint3 = initialPosition3;
		ctrlPoint4 = initialPosition4;
		ctrlPoint5 = initialPosition5;
		ctrlPoint6 = initialPosition6;

	}
	else if (m_curveType == "hermite") {

		curveName = "Courbe de type hermite";

		ctrlPoint1 = initialPosition1;
		ctrlPoint2 = initialPosition2;
		ctrlPoint3 = initialPosition3;
		ctrlPoint4 = initialPosition4;
		ctrlPoint5 = initialPosition4;
		ctrlPoint6 = initialPosition4;

	}

	xDelta = motionSpeed;
	yDelta = motionSpeed;

}

void ParametricCurve::update()
{
	for (index = 0; index <= lineResolution; ++index)
	{
		// paramètres selon le type de courbe
		if (m_curveType == "bezier_quad")
		{
			bezierQuadratic(
				index / (float)lineResolution,
				ctrlPoint1.x, ctrlPoint1.y, ctrlPoint1.z,
				ctrlPoint2.x, ctrlPoint2.y, ctrlPoint2.z,
				ctrlPoint3.x, ctrlPoint3.y, ctrlPoint3.z,
				position.x, position.y, position.z);

			// pour masquer le 4ième point de contrôle
		}
		else if (m_curveType == "bezier_cubic")
		{
			bezierCubic(
				index / (float)lineResolution,
				ctrlPoint1.x, ctrlPoint1.y, ctrlPoint1.z,
				ctrlPoint2.x, ctrlPoint2.y, ctrlPoint2.z,
				ctrlPoint3.x, ctrlPoint3.y, ctrlPoint3.z,
				ctrlPoint4.x, ctrlPoint4.y, ctrlPoint4.z,
				position.x, position.y, position.z);
		}
		else if (m_curveType == "bezier_six")
		{
			bezierSix(
				index / (float)lineResolution,
				ctrlPoint1.x, ctrlPoint1.y, ctrlPoint1.z,
				ctrlPoint2.x, ctrlPoint2.y, ctrlPoint2.z,
				ctrlPoint3.x, ctrlPoint3.y, ctrlPoint3.z,
				ctrlPoint4.x, ctrlPoint4.y, ctrlPoint4.z,
				ctrlPoint5.x, ctrlPoint5.y, ctrlPoint5.z,
				ctrlPoint6.x, ctrlPoint6.y, ctrlPoint6.z,
				position.x, position.y, position.z);
		}
		else if (m_curveType == "hermite")
		{
			hermiteCurve(
				index / (float)lineResolution,
				ctrlPoint1.x, ctrlPoint1.y, ctrlPoint1.z,
				ctrlPoint2.x, ctrlPoint2.y, ctrlPoint2.z,
				ctrlPoint3.x, ctrlPoint3.y, ctrlPoint3.z,
				ctrlPoint4.x, ctrlPoint4.y, ctrlPoint4.z,
				position.x, position.y, position.z);
		}
		// affecter la position du point sur la courbe
		lineRenderer[index] = position;
	}
}

void ParametricCurve::draw()
{
	update();
	// dessiner les positions initiales
	ofSetColor(63, 63, 63);

	ofDrawEllipse(initialPosition1.x, initialPosition1.y, radius / 2, radius / 2);
	ofDrawEllipse(initialPosition2.x, initialPosition2.y, radius / 2, radius / 2);
	ofDrawEllipse(initialPosition3.x, initialPosition3.y, radius / 2, radius / 2);
	ofDrawEllipse(initialPosition4.x, initialPosition4.y, radius / 2, radius / 2);
	ofDrawEllipse(initialPosition5.x, initialPosition5.y, radius / 2, radius / 2);
	ofDrawEllipse(initialPosition6.x, initialPosition6.y, radius / 2, radius / 2);


	ofSetColor(255, 255, 255);
	ofSetLineWidth(lineWidthCurve);

	lineRenderer.draw();

	// dessiner les points de contrôle
	ofSetColor(255, 0, 0);

	ofDrawEllipse(ctrlPoint1.x, ctrlPoint1.y, radius, radius);
	ofDrawEllipse(ctrlPoint2.x, ctrlPoint2.y, radius, radius);
	ofDrawEllipse(ctrlPoint3.x, ctrlPoint3.y, radius, radius);
	ofDrawEllipse(ctrlPoint4.x, ctrlPoint4.y, radius, radius);
	ofDrawEllipse(ctrlPoint5.x, ctrlPoint5.y, radius, radius);
	ofDrawEllipse(ctrlPoint6.x, ctrlPoint6.y, radius, radius);
}

void ParametricCurve::hermiteCurve(
	float t,
	float p1x, float p1y, float p1z,
	float p2x, float p2y, float p2z,
	float v1x, float v1y, float v1z,
	float v2x, float v2y, float v2z,
	float&  x, float& y, float&  z) 
{
	float u1 = 1 - 3 * t*t + 2 * t*t*t;
	float u2 = t - 2 * t*t + t*t*t;
	float u3 = t*t*t - t*t;
	float u4 = 3 * t*t - 2 * t*t*t;

	x = u1*p1x + u2*v1x + u3*v2x + u4*p2x;
	y = u1*p1y + u2*v1y + u3*v2y + u4*p2y;
	z = u1*p1z + u2*v1z + u3*v2z + u4*p2z;
}

// fonction d'évaluation d'une courbe de Bézier quadratique (3 points de contrôle)
void ParametricCurve::bezierQuadratic(
	float t,
	float p1x, float p1y, float p1z,
	float p2x, float p2y, float p2z,
	float p3x, float p3y, float p3z,
	float&  x, float& y, float&  z)
{
	float u = 1 - t;

	x = u * (u * p1x + t * p2x) + t * (u * p2x + t * p3x);
	y = u * (u * p1y + t * p2y) + t * (u * p2y + t * p3y);
	z = u * (u * p1z + t * p2z) + t * (u * p2z + t * p3z);
}

// fonction d'évaluation d'une courbe de Bézier cubique (4 points de contrôle)
void ParametricCurve::bezierCubic(
	float t,
	float p1x, float p1y, float p1z,
	float p2x, float p2y, float p2z,
	float p3x, float p3y, float p3z,
	float p4x, float p4y, float p4z,
	float&  x, float& y, float&  z)
{
	float u = 1 - t;
	float uu = u * u;
	float uuu = uu * u;
	float tt = t * t;
	float ttt = tt * t;

	x = (uuu * p1x) + (3 * uu * t * p2x) + (3 * u * tt * p3x) + ttt * p4x;
	y = uuu * p1y + 3 * uu * t * p2y + 3 * u * tt * p3y + ttt * p4y;
	z = uuu * p1z + 3 * uu * t * p2z + 3 * u * tt * p3z + ttt * p4z;
}

void ParametricCurve::bezierSix(
	float t,
	float p1x, float p1y, float p1z,
	float p2x, float p2y, float p2z,
	float p3x, float p3y, float p3z,
	float p4x, float p4y, float p4z,
	float p5x, float p5y, float p5z,
	float p6x, float p6y, float p6z,
	float&  x, float& y, float&  z)
{
	float u = 1 - t;
	float uu = u * u;
	float uuu = uu * u;
	float u4 = uuu * u;
	float u5 = u4 * u;
	float tt = t * t;
	float ttt = tt * t;
	float t4 = ttt * t;
	float t5 = t4 * t;

	x = u5 * p1x + 5 * t * u4 * p2x + 10 * tt * uuu * p3x + 10 * ttt * uu * p4x + 5 * t4 * u * p5x + t5 * p6x;
	y = u5 * p1y + 5 * t * u4 * p2y + 10 * tt * uuu * p3y + 10 * ttt * uu * p4y + 5 * t4 * u * p5y + t5 * p6y;
	z = u5 * p1z + 5 * t * u4 * p2z + 10 * tt * uuu * p3z + 10 * ttt * uu * p4z + 5 * t4 * u * p5z + t5 * p6z;

}

bool ParametricCurve::getSelected() {
	return select;
}

void ParametricCurve::setSelected(bool val) {
	select = val;
}

std::string ParametricCurve::id() {
	return curveName;
}

void ParametricCurve::rotateX(float x) {
}

void ParametricCurve::rotateY(float y) {
}

void ParametricCurve::rotateZ(float z) {
}

void ParametricCurve::translateX(float x) {
}

void ParametricCurve::translateY(float y) {
}

void ParametricCurve::translateZ(float z) {
}

void ParametricCurve::scale(float scale) {
}

ParametricCurve::~ParametricCurve() {}

