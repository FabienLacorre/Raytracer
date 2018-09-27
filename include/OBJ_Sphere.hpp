#ifndef __OBJ_SPHERE_HPP__
#define __OBJ_SPHERE_HPP__

#include "OBJ.hpp"

class OBJ_Sphere : public OBJ {
public:
	OBJ_Sphere(float x, float y, float z, float rayon, Color color);
	~OBJ_Sphere();
	float Intersect(Pos ray, Pos camera) const;

	float rayon;
private:
};

#endif