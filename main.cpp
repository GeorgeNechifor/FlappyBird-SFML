#include <SFML/Graphics.hpp>
#include"ScreenTemplate.h"
#include"DrawShapes.h"
#include<iostream>

const float screen_width = 700;
const float screen_height = 900;
const float block_size = 50;
const float block_final = 500;

int main()
{
    sf::RenderWindow window(sf::VideoMode(screen_width , screen_height) , "TETRIS");
    window.setFramerateLimit(60);
    ScreenTemplate temp;
    DrawShapes shape;

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
            shape.ShapeEvent(event);
        }

        window.clear(sf::Color::White);
        temp.setBlockField(window , block_size , screen_height , block_final);
        shape.ShapeMove(window);
        window.display();
    }

    return 0;
}