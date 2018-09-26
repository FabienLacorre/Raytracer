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
	Color Black = {0, 0, 0, 255};

	while (1){
		this->win->Clear();
		this->FillBackground(Black);
		this->texture->update(pixels);
		this->win->GetWindow().draw(*sprite);
		this->win->Display();
	}
}

void Scene::FillBackground(Color col){
	for (int i = 0; i < WIDTH * HEIGHT * 4; i += 4) {
		this->pixels[i] = col.r;
		this->pixels[i+1] = col.g;
		this->pixels[i+2] = col.b;
		this->pixels[i+3] = col.a;
	}
}