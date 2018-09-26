#include "Raytracer.hpp"
#include "Window.hpp"
#include "Scene.hpp"

Scene::Scene(Window &win, int width, int height){
	this->win = &win;
	this->pixels = new sf::Uint8[WIDTH*HEIGHT*4];
	this->texture = new sf::Texture();
	this->texture->create(WIDTH, HEIGHT); 
	this->sprite = new sf::Sprite(*this->texture);
}

Scene::~Scene(){

}

void Scene::Run(){
	Color test = {0, 255, 0, 120};
	while (1){
		win->Clear();
		for(int i = 0; i < WIDTH * HEIGHT * 4; i += 4) {
			pixels[i] = test.r;
			pixels[i+1] = test.g;
			pixels[i+2] = test.b;
			pixels[i+3] = test.a;
		}
		texture->update(pixels);
		win->GetWindow().draw(*sprite);
		win->Display();
	}
}