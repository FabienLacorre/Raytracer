#ifndef __RAYTRACER_HPP__
#define __RAYTRACER_HPP__

#define HEIGHT 640
#define WIDTH 1200

struct Pos {
	float x, y, z;
};

struct Vector {
	float x, y, z;
};

struct Ray {
	Pos start;
	Vector dir;
};

struct Color {
	int r, g, b, a;
};

struct Light {
	float x, y, z;
	Color color;
};

#endif
