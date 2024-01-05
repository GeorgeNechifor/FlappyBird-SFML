#pragma once
#include<SFML/Graphics.hpp>
#include<SFML/System/Clock.hpp>
#include<iostream>

class Power{
public:
    Power(){
        getPowerImage();
    }
    void setPowerImage(sf::RenderWindow& window , bool status , bool start , float BirdPositionX , float BirdPositionY){
        if(!PowerOn)window.draw(PowerSprite);
        if(status && !start){
            PowerSprite.rotate(-4);
            setPowerMove(BirdPositionX , BirdPositionY);
        }
    }
    bool PowerOn = false;
private:
    sf::Texture PowerTexture;
    sf::Sprite PowerSprite;
    sf::Clock clock;
    sf::Clock LoveClock;
    int RandomSpeedXIndex = rand() % 3;
    int RandomSpeedYIndex = rand() % 7;
    float SpeedXValues[4] = {-4 , -6 , -7 , -5};
    float SpeedYValues[8] = {-0.6 , 1.3 , -0.8 , 0.7 , 1 , -1 , 1.6 , -1.4};
    void getPowerImage(){
        PowerTexture.loadFromFile(R"(C:\GamesCpp\TetrisGame\images\love.png)");
        PowerSprite.setTexture(PowerTexture);
        PowerSprite.setScale(0.2 , 0.2);
        PowerSprite.setPosition(1100 , 100);
        PowerSprite.setOrigin((sf::Vector2f) PowerTexture.getSize() / 2.f);
    }

    void setPowerMove(float BirdPositionX , float BirdPositionY){
        float PowerX = PowerSprite.getPosition().x;
        float PowerY = PowerSprite.getPosition().y;
        sf::Time elapsed = clock.getElapsedTime();
        sf::Time ElapsedLove = LoveClock.getElapsedTime();
        if(PowerX < -20){
            PowerSprite.setPosition(1100 , (rand() % 740) + 10);
            RandomSpeedXIndex = rand() % 3;
            RandomSpeedYIndex = rand() % 5;
            clock.restart();


        }
        else{
            if(elapsed.asMilliseconds() > 22000){
                if(std::abs(PowerY - BirdPositionY) < 60 && std::abs(PowerX - BirdPositionX) < 60){
                   PowerOn = true;
                   LoveClock.restart();
                }
                else{
                    PowerSprite.move(SpeedXValues[RandomSpeedXIndex] , SpeedYValues[RandomSpeedYIndex]);
                }
            }
            if(ElapsedLove.asMilliseconds() > 7000){
                PowerOn = false;
            }

        }
    }
};