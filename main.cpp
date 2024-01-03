#include <SFML/Graphics.hpp>
#include"GameTemplate.h"
#include<iostream>
#include"Bird.h"
#include"Pipes.h"
#include<SFML/Audio/SoundBuffer.hpp>
#include<SFML/Audio/Sound.hpp>
const int screen_width = 1024;
const int screen_height = 800;
int main()
{
    sf::RenderWindow window(sf::VideoMode(screen_width , screen_height) , "Flappy Bird");
    window.setFramerateLimit(60);
    GameTemplate GameT;
    Bird bird;
    Pipes pipe;
    sf::Sprite Pipe1, Pipe2 , Pipe3 , Pipe4;
    pipe.getPipeImage(Pipe1 ,Pipe2);
    pipe.getPipeImage(Pipe3 , Pipe4);

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
        bird.setBirdImage(window);
        bird.setThunderImage(window);
        bird.setRestartButton(window);
        window.display();
    }

    return 0;
}