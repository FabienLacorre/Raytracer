#include "Raytracer.hpp"
#include "Window.hpp"
#include "Scene.hpp"

int main(){
	Window win("Raytracer", WIDTH, HEIGHT);
	Scene mainScene(win, WIDTH, HEIGHT);
	mainScene.Run();
	return (0);
}