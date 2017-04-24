
#include "parametricMesh.h"

ParametricMesh::ParametricMesh() : select(false){}

void ParametricMesh::setup()
{
	// paramètres
	lineResolution = 100;

	radius = 32.0f;

	lineWidthOutline = 4.0f;
	lineWidthCurve = 8.0f;

	// initialisation des sommets de la ligne
	for (index = 0; index <= lineResolution; ++index) {
		lineRenderer1.addVertex(ofPoint());
		lineRenderer2.addVertex(ofPoint());
		lineRenderer3.addVertex(ofPoint());
		lineRenderer4.addVertex(ofPoint());
	}

	pt1 = { 200, 0, 200 };
	pt2 = { -200, 0, 200 };
	pt3 = { -200, 0, -200 };
	pt3 = { 200, 0, -200 };

	axe1 = { 1, 0, 0 };
	axe2 = { 0, 0, 1 };

	v1 = { 150, 120, 100 };
	v2 = { 75, 100, 75 };
	v3 = { -50, 120, -120 };
	v4 = { 60, 75, 60 };
	v5 = { 0 , 0 , 0 };
	v6 = { 60, 70, 55 };
	v7 = { 30, 60, 75 };
	v8 = { 60, 40, -10 };

}

void ParametricMesh::draw()
{	
	ofSetLineWidth(lineWidthCurve);
	for (index = 0; index <= lineResolution; ++index)
	{
	hermiteCurve(
		index / (float)lineResolution,
		pt1.x, pt1.y, pt1.z,
		pt2.x, pt2.y, pt2.z,
		v1.x, v1.y, v1.z,
		v2.x, v2.y, v2.z,
		position.x, position.y, position.z);
	// affecter la position du point sur la courbe
	lineRenderer1[index] = position;
	}
	lineRenderer1.draw();

	for (index = 0; index <= lineResolution; ++index)
	{
		hermiteCurve(
			index / (float)lineResolution,
			pt2.x, pt2.y, pt2.z,
			pt3.x, pt3.y, pt3.z,
			v3.x, v3.y, v3.z,
			v4.x, v4.y, v4.z,
			position.x, position.y, position.z);
		// affecter la position du point sur la courbe
		lineRenderer2[index] = position;
	}
	lineRenderer2.draw();

	for (index = 0; index <= lineResolution; ++index)
	{
		hermiteCurve(
			index / (float)lineResolution,
			pt3.x, pt3.y, pt3.z,
			pt4.x, pt4.y, pt4.z,
			v5.x, v5.y, v5.z,
			v6.x, v6.y, v6.z,
			position.x, position.y, position.z);
		// affecter la position du point sur la courbe
		lineRenderer3[index] = position;
	}
	lineRenderer3.draw();

	for (index = 0; index <= lineResolution; ++index)
	{
		hermiteCurve(
			index / (float)lineResolution,
			pt4.x, pt4.y, pt4.z,
			pt1.x, pt1.y, pt1.z,
			v7.x, v7.y, v7.z,
			v8.x, v8.y, v8.z,
			position.x, position.y, position.z);
		// affecter la position du point sur la courbe
		lineRenderer4[index] = position;
	}
	lineRenderer4.draw();

	c1 = lineRenderer1.getVertices();
	c2 = lineRenderer2.getVertices();
	c3 = lineRenderer3.getVertices();
	c4 = lineRenderer4.getVertices();

	for (index = 0; index <= lineResolution; ++index)
	{
		lerp1x = (1 - axe2.x)*c1[index].x + axe2.x*c2[index].x;
		lerp1y = (1 - axe2.y)*c1[index].y + axe2.y*c2[index].y;
		lerp1z = (1 - axe2.z)*c1[index].z + axe2.z*c2[index].z;
		lerp2x = (1 - axe1.x)*c3[index].x + axe1.x*c4[index].x;
		lerp2y = (1 - axe1.y)*c3[index].y + axe1.y*c4[index].y;
		lerp2z = (1 - axe1.z)*c3[index].z + axe1.z*c4[index].z;
		blerpx = (1 - axe1.x)*(1 - axe2.x)*pt1.x + axe1.x*(1 - axe2.x)*pt2.x + (1 - axe1.x)*axe2.x*pt3.x + axe1.x*axe2.x*pt4.x;
		blerpy = (1 - axe1.y)*(1 - axe2.y)*pt1.y + axe1.y*(1 - axe2.y)*pt2.y + (1 - axe1.y)*axe2.y*pt3.y + axe1.y*axe2.y*pt4.y;
		blerpz = (1 - axe1.z)*(1 - axe2.z)*pt1.z + axe1.z*(1 - axe2.z)*pt2.z + (1 - axe1.z)*axe2.z*pt3.z + axe1.z*axe2.z*pt4.z;

		coonsx = lerp1x + lerp2x + blerpx;
		coonsy = lerp1y + lerp2y + blerpy;
		coonsz = lerp1z + lerp2z + blerpz;

		mesh.addVertex(ofPoint(coonsx, coonsy, coonsz));
	}
	mesh.draw();

}

bool ParametricMesh::getSelected() {
	return select;
}

void ParametricMesh::setSelected(bool val) {
	select = val;
}

std::string ParametricMesh::id() {
	return "parametricMesh";
}

void ParametricMesh::rotateX(float x) {
}

void ParametricMesh::rotateY(float y) {
}

void ParametricMesh::rotateZ(float z) {
}

void ParametricMesh::translateX(float x) {
}

void ParametricMesh::translateY(float y) {
}

void ParametricMesh::translateZ(float z) {
}

void ParametricMesh::scale(float scale) {
}

void ParametricMesh::hermiteCurve(
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

ParametricMesh::~ParametricMesh() {}

