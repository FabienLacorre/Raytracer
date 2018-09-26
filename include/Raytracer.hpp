#define HEIGHT 640
#define WIDTH 640

struct Dot {
	float x, y, z;
};

struct Vector {
	float x, y, z;
};

struct Ray {
	Dot start;
	Vector dir;
};

struct Color {
	int r, g, b, a;
};