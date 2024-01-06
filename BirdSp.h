
#include<SFML/Graphics.hpp>
#include<SFML/System/Clock.hpp>
#include<iostream>
class BirdSp{
public:
    BirdSp(){
        ImageTexture.loadFromFile(R"(C:\GamesCpp\TetrisGame\images\brokenHeart.png)");
        ImageTexture1.loadFromFile(R"(C:\GamesCpp\TetrisGame\images\heart.png)");
        ImageSprite.setTexture(ImageTexture);
        ImageSprite.setScale(0.07 , 0.07);
        ImageSprite.setPosition(-10 , 0);
        ImageSprite.setOrigin((sf::Vector2f) ImageTexture.getSize() / 2.f);


    }
    void setAnimatedImage(sf::RenderWindow& window , float BirdY , bool status , bool PowerOn);

private:
    sf::Texture ImageTexture;
    sf::Texture ImageTexture1;
    sf::Sprite ImageSprite;
    sf::Clock clock;
    const float AnimationSpeed = 9;
};

void BirdSp::setAnimatedImage(sf::RenderWindow &window , float BirdY , bool status , bool PowerOn) {
    window.draw(ImageSprite);
    if(status){
        if(PowerOn){
            ImageSprite.setTexture(ImageTexture1);
        }
        else ImageSprite.setTexture(ImageTexture);
        float ImageX = ImageSprite.getPosition().x;
        ImageSprite.rotate(9);
        if(ImageX > 0){
            ImageSprite.move(-AnimationSpeed , -2.8);
        }
        else{
            ImageSprite.setPosition(470 , BirdY);
        }
    }
}

