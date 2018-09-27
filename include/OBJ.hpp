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

	virtual float Intersect(Pos ray, Pos camera) const = 0;
protected:
	Pos pos;
	Color color;
};

#endif