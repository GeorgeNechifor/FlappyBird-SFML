#include <SFML/Graphics.hpp>
#include"GameTemplate.h"
#include<iostream>
#include"Bird.h"
#include"Obstacles.h"
#include"Score.h"
#include"StartGame.h"
#include"JumpAnimation.h"
const int screen_width = 1024;
const int screen_height = 800;

int main()
{
    sf::RenderWindow window(sf::VideoMode(screen_width , screen_height) , "Flappy Bird" , sf::Style::Titlebar | sf::Style::Close);
    window.setFramerateLimit(60);
    GameTemplate GameT;
    Bird bird;
    Obstacles obstacle;
    Score score;
    StartGame start;
    JumpAnimation animation;
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
            if(bird.Status) bird.setBirdTransition(event , start.Start);
            if(!bird.Status) bird.setRestartEvent(event);
            obstacle.setAsteroidsOnStart(event , start.Start);
            start.startGameEvent(event , start.Start);
        }

        window.clear(sf::Color::White);
        GameT.setBackgroundImage(window , bird.Status);
        bird.setThunderImage(window);
        obstacle.setAsteroidImage(window , bird.Status , start.Start);
        bird.setBirdImage(window , start.Start);
        bird.setRestartButton(window);
        animation.setAnimation(window  , bird.BirdSprite.getPosition().y);
        score.setScoreText(window , bird.Status , start.Start);
        if(start.Start){
            start.setTitle(window);
            start.setStartButton(window);
        }
        window.display();
    }

    return 0;
}