#include "Window.hpp"

Window::Window(int x, int y):
window(sf::VideoMode(x, y), "Game SFML"){
    this->window.setFramerateLimit(60);
}

Window::~Window(){

}

sf::RenderWindow &Window::GetWindow(){
    return this->window;
}

void Window::Clear() {
    this->window.clear();
}

void Window::Display() {
    this->window.display();
}

const bool Window::IsOpen() const {
    return this->window.isOpen();
}

void Window::Close() {
    this->window.close();
}