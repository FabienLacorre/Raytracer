#include <math.h> 

#include "Raytracer.hpp"
#include "Window.hpp"
#include "Scene.hpp"
#include "OBJ_Sphere.hpp"
#include "ManagerOBJ.hpp"

Scene::Scene(Window &win, int width, int height){
	this->win = &win;
	this->pixels = new sf::Uint8[WIDTH*HEIGHT*4];
	this->texture = new sf::Texture();
	this->texture->create(WIDTH, HEIGHT); 
	this->sprite = new sf::Sprite(*this->texture);
}

Scene::~Scene(){
}

Pos Normalise(Pos v){
	float norm = sqrt(pow(v.x, 2) + pow(v.y, 2) + pow(v.z, 2));
	Pos newVec = {(v.x / norm), (v.y / norm), (v.z / norm)};
	return newVec;
}

Pos Scene::ComputeCurrentRay(int x, int y, Pos camera){
	Pos sp = {0, 0, 0};

	sp.x = y - (WIDTH / 2);
	sp.y = x - (HEIGHT / 2);
	sp.z = sqrt(pow(WIDTH, 2) + pow(HEIGHT, 2));
	sp = Normalise(sp);
	Pos ray = {sp.x - camera.x, sp.y - camera.y, sp.z - camera.z};
	ray = Normalise(ray);
	return ray;
}

void Scene::Run(){
	ManagerOBJ manager;

	Color black = {0, 0, 0, 255};
	Color white = {255, 255, 255, 150};
	Color blue = {51, 204, 204, 255};
	Color red = {255, 0, 0, 255};

	Pos camera = {0, 0, 0};
	Pos ray = {0, 0, 0};

	// add objs dans le manager //
	OBJ_Sphere s1(-10, 0, 40, 5, white);
	OBJ_Sphere s2(10, 0, 40, 5, blue);
	OBJ_Sphere s3(0, 0, 40, 7, red);
	manager.AddObject(s1);
	manager.AddObject(s2);
	manager.AddObject(s3);

		// add lights //
	Light light = {0, 0, 25, white};
	Light light2 = {20, 40, 25, white};
	Light light3 = {-20, -40, 25, white};
	manager.AddLight(&light);
	//manager.AddLight(&light2);
	manager.AddLight(&light3);

	this->win->Clear();
	this->FillBackground(black);

	for (int y = 0; y < WIDTH; y++){
		for (int x = 0; x < HEIGHT; x++){
			ray = this->ComputeCurrentRay(x, y, camera);
			float d = manager.ComputeIntersect(x, y, ray, camera);
			if (d > 0) {
				manager.ComputeLight(pixels, x, y, d, ray, camera);
			}
		}
	}
	this->texture->update(pixels);
	this->win->GetWindow().draw(*sprite);
	this->win->Display();
	while (1);
}

void Scene::FillBackground(Color col){
	for (int i = 0; i < WIDTH * HEIGHT * 4; i += 4) {
		this->pixels[i] = col.r;
		this->pixels[i+1] = col.g;
		this->pixels[i+2] = col.b;
		this->pixels[i+3] = col.a;
	}
}

