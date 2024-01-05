#pragma once
#include<SFML/Graphics.hpp>
#include<SFML/System/Clock.hpp>
#include<iostream>
class Feelings{

public:
    Feelings(){
        CircleTexture.loadFromFile(R"(C:\GamesCpp\TetrisGame\images\circle.png)");
    }
    void setAnimation(sf::RenderWindow& window , float BirdPosition){
        setInterval(BirdPosition);
        AnimationImage.loadFromFile(EmojiLinks[index]);
        AnimationImageSprite.setTexture(AnimationImage);
        AnimationImageSprite.setScale(0.2 , 0.2);
        AnimationImageSprite.setPosition(530 , BirdPosition - 130);
        window.draw(AnimationImageSprite);
        Circle1.setTexture(CircleTexture);
        Circle1.setScale(0.07 , 0.07);
        Circle1.setPosition(540 , BirdPosition - 15);
        Circle2.setTexture(CircleTexture);
        Circle2.setScale(0.1 , 0.1);
        Circle2.setPosition(525 ,BirdPosition - 55);
        window.draw(Circle2);
        window.draw(Circle1);

    }

private:
    sf::Texture AnimationImage;
    sf::Sprite AnimationImageSprite;
    sf::Clock clock;
    sf::Texture CircleTexture;
    sf::Sprite Circle1;
    sf::Sprite Circle2;
    bool AnimationEx = true;
    int index = 0;
    std::string EmojiLinks[4] = {R"(C:\GamesCpp\TetrisGame\images\e1.png)" ,
                                 R"(C:\GamesCpp\TetrisGame\images\e2.png)",
                                 R"(C:\GamesCpp\TetrisGame\images\e3.png)",
                                 R"(C:\GamesCpp\TetrisGame\images\e4.png)"
    };
    void setInterval(float& BirdPosition){
        sf::Time elapsed = clock.getElapsedTime();
        if(elapsed.asMilliseconds()  < 400){
            if(AnimationEx){
                increaseIndex();
                AnimationEx = false;
            }
        }
        else{

            AnimationEx = true;
            clock.restart();
        }
    }
    void increaseIndex(){
        if(index < 3) index++;
        else index = 0;
    }

};