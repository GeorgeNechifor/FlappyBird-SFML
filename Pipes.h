#include<SFML/Graphics.hpp>

class Pipes{
public:

    void setPipeImageUp(sf::RenderWindow& window ,sf::Sprite& Pipe);
    void getPipeImage(sf::Sprite& pipe1 ,sf::Sprite& pipe2);
    void setPipeImageDown(sf::RenderWindow& window , sf::Sprite& Pipe);

private:
    sf::Texture PipeImage;
    sf::Sprite PipeSprite;
    sf::Sprite PipeSpriteRev;

};

void Pipes::getPipeImage(sf::Sprite& pipe1 , sf::Sprite& pipe2) {
    PipeImage.loadFromFile("C:\\GamesCpp\\TetrisGame\\images\\pipe.png");
    pipe1.setTexture(PipeImage);
    pipe1.setPosition(1370 , 500);
    pipe2.setTexture(PipeImage);
    pipe2.setPosition(1400 , 300);
    pipe2.rotate(180);
}

void Pipes::setPipeImageUp(sf::RenderWindow &window , sf::Sprite& Pipe) {
    float PipeX = Pipe.getPosition().x;
    Pipe.move(-3 , 0);
    if(PipeX < 200){
        float randomX = (rand() % 1400) + 1350;
        float randomY = (rand() % 350) + 50;
        Pipe.setPosition(randomX , randomY);
    }

    window.draw(Pipe);

}

void Pipes::setPipeImageDown(sf::RenderWindow &window, sf::Sprite &Pipe) {
    float PipeX = Pipe.getPosition().x;
    Pipe.move(-3 , 0);
    if(PipeX < 0){
        float randomX = (rand() % 1100) + 1050;
        float randomY = (rand() % 600) + 400;
        Pipe.setPosition(randomX , randomY);
    }

    window.draw(Pipe);
}