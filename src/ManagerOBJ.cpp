#include "ManagerOBJ.hpp"

ManagerOBJ::ManagerOBJ(){

}

ManagerOBJ::~ManagerOBJ(){

}

void ManagerOBJ::AddObject(OBJ &obj){
	this->objects.push_back(&obj);
}

float ManagerOBJ::ComputeIntersect(int x, int y, Pos ray, Pos camera) {
	float minD = 99999;
	float d = 0;
	for (auto o : this->objects){
		d = o->Intersect(ray, camera);
		if (d < minD){
			minD = d;
		}
	}
	return minD;
}