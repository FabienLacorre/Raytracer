#include "OBJ_Sphere.hpp"

OBJ_Sphere::OBJ_Sphere(float x, float y, float z, float rayon, Color color) 
: OBJ(x, y, z, color){
	this->rayon = rayon;
}

OBJ_Sphere::~OBJ_Sphere() {

}