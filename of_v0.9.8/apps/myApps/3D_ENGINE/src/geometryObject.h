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
	GeometryObject(){};
	~GeometryObject(){};

	//rotation transformations must be defined
	virtual void rotateX();
	virtual void rotateY();
	virtual void rotateZ();

	//translation transformations must be defines
	virtual void translateX();
	virtual void translateY();
	virtual void translateZ();

	//scale transformation must be defined
	virtual void scale();

	//instance of class must have a name
	virtual std::string id();

};



#endif /* SRC_GEOMETRYOBJECT_H_ */
