#ifndef __SCENE_HPP__
#define __SCENE_HPP__

class Scene {
public:
	Scene(Window &win, int width, int height);
	~Scene();

	void Run();
private:
	Window *win;
	sf::Uint8 *pixels;
	sf::Texture *texture;
	sf::Sprite *sprite;

	void FillBackground(Color col);
};

#endif
