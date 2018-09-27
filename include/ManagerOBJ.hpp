#ifndef __MANAGER_OBJ_HPP__
#define __MANAGER_OBJ_HPP__

#include <iostream>
#include <vector>

#include "OBJ.hpp"

class ManagerOBJ {
public:
	ManagerOBJ();
	~ManagerOBJ();

	void AddObject(OBJ &obj);
	void AddLight(Light *l);
	float ComputeIntersect(int x, int y, Pos Ray, Pos camera);
	float ComputeLight(sf::Uint8 *pixels, int x, int y, float d, Pos ray, Pos camera);
	void PutColor(sf::Uint8 *pixels, float angle, int x, int y);
private:
	int currentObjHit;
	std::vector <OBJ *>objects;
	std::vector <Light *>lights;

	Pos Normalise(Pos v);
};

#endif
