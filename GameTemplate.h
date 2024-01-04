#pragma once

#include<SFML/Graphics.hpp>
#include<iostream>
class GameTemplate{
public:
    GameTemplate(){
        getBackgroundImage();
    }
    void setBackgroundImage(sf::RenderWindow& window , bool& status);
private:
    sf::Sprite BackgroundImageSprite;
    sf::Sprite BackgroundImageSprite1;
    sf::Sprite BackgroundImageSprite2;
    sf::Sprite DropImageSprite;
    sf::Texture DropImage;
    sf::Texture BackgroundImage;
    void getBackgroundImage();
    void setImagePosition();
};

void GameTemplate::getBackgroundImage() {
    BackgroundImage.loadFromFile(R"(C:\GamesCpp\TetrisGame\images\bkImage.png)");
    BackgroundImageSprite.setTexture(BackgroundImage);
    BackgroundImageSprite1.setTexture(BackgroundImage);
    BackgroundImageSprite2.setTexture(BackgroundImage);
    float Image1X = BackgroundImageSprite.getPosition().x;
    float Image2X = BackgroundImageSprite1.getPosition().x;
    BackgroundImageSprite2.setPosition(2045 , 0);
    BackgroundImageSprite1.setPosition( 1024 , 0);
    setImagePosition();
}

void GameTemplate::setBackgroundImage(sf::RenderWindow& window , bool& status) {
    window.draw(BackgroundImageSprite);
    window.draw(BackgroundImageSprite1);
    window.draw(BackgroundImageSprite2);
    if(status) setImagePosition();
}

void GameTemplate::setImagePosition() {

    if(BackgroundImageSprite.getPosition().x < -1018){
        BackgroundImageSprite.setPosition(2043, 0);
    }
    else BackgroundImageSprite.move(-3 , 0);

    if(BackgroundImageSprite1.getPosition().x < -1018){
        BackgroundImageSprite1.setPosition(2043 , 0);
    }
    else BackgroundImageSprite1.move(-3 , 0);

    if(BackgroundImageSprite2.getPosition().x < -1018){
        BackgroundImageSprite2.setPosition(2043 , 0);
    }
    else BackgroundImageSprite2.move(-3 , 0);
}
