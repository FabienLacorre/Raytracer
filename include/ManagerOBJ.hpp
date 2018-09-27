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
	float ComputeIntersect(int x, int y, Pos Ray, Pos camera);
private:
	std::vector <OBJ *>objects;
};

#endif
