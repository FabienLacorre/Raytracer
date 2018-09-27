#include <SFML/Graphics.hpp>
#include "ManagerOBJ.hpp"
#include <math.h> 

ManagerOBJ::ManagerOBJ(){
	this->currentObjHit = 0;
}

ManagerOBJ::~ManagerOBJ(){

}

void ManagerOBJ::AddObject(OBJ &obj){
	this->objects.push_back(&obj);
}
void ManagerOBJ::AddLight(Light *l){
	this->lights.push_back(l);
}

Pos ManagerOBJ::Normalise(Pos v){
	float norm = sqrt(pow(v.x, 2) + pow(v.y, 2) + pow(v.z, 2));
	Pos newVec = {(v.x / norm), (v.y / norm), (v.z / norm)};
	return newVec;
}

float ManagerOBJ::ComputeIntersect(int x, int y, Pos ray, Pos camera) {
	float minD = 9999999;
	float d = 0;
	int i = 0;

	for (auto o : this->objects){
		d = o->Intersect(ray, camera);
		if (d > 0){
			if (d < minD){
				minD = d;
				this->currentObjHit = i;
			}	
		}
		i++;
	}
	return minD;
}

float ManagerOBJ::ComputeLight(sf::Uint8 *pixels, int x, int y, float d, Pos ray, Pos camera){
	Pos impact = {0, 0, 0};
	Pos normal = {0, 0, 0};
	Pos l = {0, 0, 0};

	impact.x = camera.x + (ray.x * d);
	impact.y = camera.y + (ray.y * d);
	impact.z = camera.z + (ray.z * d);
	normal.x = impact.x - this->objects[this->currentObjHit]->GetPos().x;
	normal.y = impact.y - this->objects[this->currentObjHit]->GetPos().y;
	normal.z = impact.z - this->objects[this->currentObjHit]->GetPos().z;

	float angle = 0;
	for (auto lum : this->lights){
		l.x = lum->x - impact.x;
		l.y = lum->y - impact.y;
		l.z = lum->z - impact.z;
		normal = Normalise(normal);
		l = Normalise(l);
		angle = (l.x * normal.x) + (l.y * normal.y) + (l.z * normal.z);	
		if (angle > 0) {
			Color col = this->objects[this->currentObjHit]->GetColor();
			col.r *= angle; 
			col.g *= angle;
			col.b *= angle;
			col.r += pixels[((x * WIDTH) + y) * 4];
			col.g += pixels[(((x * WIDTH) + y) * 4) + 1];
			col.b += pixels[(((x * WIDTH) + y) * 4) + 2];

			if (col.r > 255){
				col.r = 255;
			}
			if (col.g > 255){
				col.g = 255;
			}
			if (col.b > 255){
				col.b = 255;
			}

			pixels[((x * WIDTH) + y) * 4] = col.r;
			pixels[(((x * WIDTH) + y) * 4) + 1] = col.g;
			pixels[(((x * WIDTH) + y) * 4) + 2] = col.b;
			pixels[(((x * WIDTH) + y) * 4) + 3] = 255;	
		}
	}
	
	return angle;
}

void ManagerOBJ::PutColor(sf::Uint8 *pixels, float angle, int x, int y){
	if (angle < 0){
		pixels[((x * WIDTH) + y) * 4] = 0;
		pixels[(((x * WIDTH) + y) * 4) + 1] = 0;
		pixels[(((x * WIDTH) + y) * 4) + 2] = 0;
		pixels[(((x * WIDTH) + y) * 4) + 3] = 255;	
	} else {
		Color col = this->objects[this->currentObjHit]->GetColor();
		col.r *= angle; 
		col.g *= angle;
		col.b *= angle;
		pixels[((x * WIDTH) + y) * 4] = col.r;
		pixels[(((x * WIDTH) + y) * 4) + 1] = col.g;
		pixels[(((x * WIDTH) + y) * 4) + 2] = col.b;
		pixels[(((x * WIDTH) + y) * 4) + 3] = 255;	
	}
}