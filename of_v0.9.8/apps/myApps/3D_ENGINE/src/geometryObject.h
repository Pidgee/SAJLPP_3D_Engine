/*
 * geometryObject.h
 *
 *  Created on: Mar 9, 2017
 *      Author: ada
 */

#include <string>

#ifndef SRC_GEOMETRYOBJECT_H_
#define SRC_GEOMETRYOBJECT_H_

//pure virtual class for geometric entities within the fbo
class GeometryObject{
public:

	virtual bool selected()=0;

	//rotation transformations must be defined
	virtual void rotateX()=0;
	virtual void rotateY()=0;
	virtual void rotateZ()=0;

	//translation transformations must be defines
	virtual void translateX()=0;
	virtual void translateY()=0;
	virtual void translateZ()=0;

	//scale transformation must be defined
	virtual void scale()=0;

	//instance of class must have a name
	virtual std::string id()=0;

	virtual void draw()=0;

	virtual void setup()=0;

};



#endif /* SRC_GEOMETRYOBJECT_H_ */
