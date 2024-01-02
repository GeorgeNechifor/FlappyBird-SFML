#include <SFML/Graphics.hpp>

#include<iostream>

const int screen_width = 900;
const int screen_height = 700;

int nr = 1;
int main()
{
    sf::RenderWindow window(sf::VideoMode(screen_width , screen_height) , "Flappy Bird");
    window.setFramerateLimit(60);


    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear(sf::Color::White);

        window.display();
    }

    return 0;
}