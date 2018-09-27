#include <math.h> 

#include "Raytracer.hpp"
#include "Window.hpp"
#include "Scene.hpp"
#include "OBJ_Sphere.hpp"

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

	sp.x = x - (WIDTH / 2);
	sp.y = y - (HEIGHT / 2);
	sp.z = sqrt(pow(WIDTH, 2) + pow(HEIGHT, 2));
	sp = Normalise(sp);
	Pos ray = {sp.x - camera.x, sp.y - camera.y, sp.z - camera.z};
	ray = Normalise(ray);
	return ray;
}

float Scene::ComputeLight(float d, Pos ray, Pos camera, OBJ &s, Pos light){
	Pos impact = {0, 0, 0};
	Pos normal = {0, 0, 0};
	Pos l = {0, 0, 0};

	impact.x = camera.x + (ray.x * d);
	impact.y = camera.y + (ray.y * d);
	impact.z = camera.z + (ray.z * d);
	normal.x = impact.x - s.GetPos().x;
	normal.y = impact.y - s.GetPos().y;
	normal.z = impact.z - s.GetPos().z;
	l.x = light.x - impact.x;
	l.y = light.y - impact.y;
	l.z = light.z - impact.z;
	normal = Normalise(normal);
	l = Normalise(l);
	float angle = (l.x * normal.x) + (l.y * normal.y) + (l.z * normal.z);
	return angle;
}

void Scene::PutColor(float angle, int x, int y, OBJ &obj){
	if (angle < 0){
		this->pixels[((x * WIDTH) + y) * 4] = 0;
		this->pixels[(((x * WIDTH) + y) * 4) + 1] = 0;
		this->pixels[(((x * WIDTH) + y) * 4) + 2] = 0;
		this->pixels[(((x * WIDTH) + y) * 4) + 3] = 255;	
	} else {
		Color col = obj.GetColor();
		col.r *= angle; 
		col.g *= angle;
		col.b *= angle;
		this->pixels[((x * WIDTH) + y) * 4] = col.r;
		this->pixels[(((x * WIDTH) + y) * 4) + 1] = col.g;
		this->pixels[(((x * WIDTH) + y) * 4) + 2] = col.b;
		this->pixels[(((x * WIDTH) + y) * 4) + 3] = 255;	
	}
}

void Scene::Run(){
	Color Black = {0, 0, 0, 255};
	Color blue = {51, 204, 204, 255};
	OBJ_Sphere s1(0, 0, 30, 5, blue);
	Pos camera = {0, 0, 0};
	Pos light = {30, 30, 0};
	Pos ray = {0, 0, 0};
	this->win->Clear();
	this->FillBackground(Black);

	for (int y = 0; y < WIDTH; y++){
		for (int x = 0; x < HEIGHT; x++){
			ray = this->ComputeCurrentRay(x, y, camera);
			float d = s1.Intersect(ray, camera);
			if (d > 0) {
				float angle = this->ComputeLight(d, ray, camera, s1, light);
				this->PutColor(angle, x, y, s1);
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

