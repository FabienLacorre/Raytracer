#include "OBJ.hpp"

OBJ::OBJ(float x, float y, float z, Color c){
	this->pos.x = x;
	this->pos.y = y;
	this->pos.z = z;
	this->color = c;
}

OBJ::~OBJ(){

}

Pos OBJ::GetPos() const {
	return this->pos;
}

void OBJ::SetPos(Pos position){
	this->pos.x = position.x;
	this->pos.y = position.y;
	this->pos.z = position.z;
}

Color OBJ::GetColor() const {
	return this->color;
}

void OBJ::SetColor(Color col){
	this->color = col;
}