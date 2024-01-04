#include <SFML/Graphics.hpp>
#include"GameTemplate.h"
#include<iostream>
#include"Bird.h"
#include"Obstacles.h"
#include"Score.h"
const int screen_width = 1024;
const int screen_height = 800;
int main()
{
    sf::RenderWindow window(sf::VideoMode(screen_width , screen_height) , "Flappy Bird");
    window.setFramerateLimit(60);
    GameTemplate GameT;
    Bird bird;
    Obstacles obstacle;
    Score score;
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
            if(bird.Status) bird.setBirdTransition(event);

        }

        window.clear(sf::Color::White);
        GameT.setBackgroundImage(window);
        bird.setThunderImage(window);
        bird.setBirdImage(window);
        bird.setRestartButton(window);
        obstacle.setAsteroidImage(window);
        score.setScoreText(window);
        window.display();
    }

    return 0;
}