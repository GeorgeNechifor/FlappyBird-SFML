#include <SFML/Graphics.hpp>
#include"GameTemplate.h"
#include<iostream>

const int screen_width = 1024;
const int screen_height = 800;
int main()
{
    sf::RenderWindow window(sf::VideoMode(screen_width , screen_height) , "Flappy Bird");
    window.setFramerateLimit(60);
    GameTemplate GameT;

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear(sf::Color::White);
        GameT.setBackgroundImage(window);
        GameT.setDropImage(window);

        window.display();
    }

    return 0;
}