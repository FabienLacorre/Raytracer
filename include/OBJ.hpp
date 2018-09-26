#ifndef __OBJ_HPP__
#define __OBJ_HPP__

#include "Raytracer.hpp"

class OBJ {
public:
	OBJ(float x, float y, float z, Color color);
	virtual ~OBJ();

	Pos GetPos() const;
	void SetPos(Pos position);
	Color GetColor() const;
	void SetColor(Color col);
protected:
	Pos pos;
	Color color;
};

#endif