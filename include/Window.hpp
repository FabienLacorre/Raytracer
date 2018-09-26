#ifndef __WINDOW_HPP__
#define __WINDOW_HPP__

#include <iostream>
#include <SFML/Graphics.hpp>

class Window {
public:
    Window(std::string name, int x, int y);
    ~Window();

    sf::RenderWindow &GetWindow();
    void Display();
    void Clear();
    const bool IsOpen() const;
    void Close();
private:
    sf::RenderWindow window;
};

#endif