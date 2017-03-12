

#include "ofMain.h"
#include "geometryObject.h"
#include "ofxAssimpModelLoader.h"

class imageObjet : public GeometryObject
{

public:

	imageObjet();

	ofImage image;

	ofPoint p1;
	ofPoint p2;
	ofPoint p3;
	ofPoint p4;

	string nom;

	void setup();
	void draw();

	ofImage ajouter_teinte(ofColor couleur);
	ofImage ajouter_image(ofImage * image_param);

	void setImage(ofImage * image_param);

	bool getSelected();
	void setSelected(bool val);

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

	~imageObjet();

private:
	bool select;
};
