#include "OBJ_Sphere.hpp"
#include <math.h> 


OBJ_Sphere::OBJ_Sphere(float x, float y, float z, float rayon, Color color) 
: OBJ(x, y, z, color){
	this->rayon = rayon;
}

OBJ_Sphere::~OBJ_Sphere() {

}

float OBJ_Sphere::Intersect(Pos ray, Pos camera) const {
	float a = pow(ray.x, 2) + pow(ray.y, 2) + pow(ray.z, 2);
	float b = 2 * ((ray.x * (camera.x - this->GetPos().x))
		+ (ray.y * (camera.y - this->GetPos().y))
		+ (ray.z * (camera.z - this->GetPos().z)));
	float c = pow(camera.x - this->GetPos().x, 2) + 
	pow(camera.y - this->GetPos().y, 2) + 
	pow(camera.z - this->GetPos().z, 2) -
	pow(this->rayon, 2);
	float delt = pow(b, 2) - (4 * a * c);
	if (delt > 0){
		float k1 = ((-1 * b) + sqrt(delt)) / (2 * a);
		float k2 = ((-1 * b) - sqrt(delt)) / (2 * a);
		if (k1 > k2)
			return k2;
		else 
			return k1;
	}
	if (delt < 0){
		return delt;
	}
	return 0;
}