#ifndef __SCENE_HPP__
#define __SCENE_HPP__

#include "OBJ.hpp"

class Scene {
public:
	Scene(Window &win, int width, int height);
	~Scene();

	void Run();
	Pos ComputeCurrentRay(int x, int y, Pos camera);
	float ComputeLight(float d, Pos ray, Pos camera, OBJ &s, Light light);
	void PutColor(float angle, int x, int y, OBJ &obj);
private:
	Window *win;
	sf::Uint8 *pixels;
	sf::Texture *texture;
	sf::Sprite *sprite;

	void FillBackground(Color col);
};

#endif
