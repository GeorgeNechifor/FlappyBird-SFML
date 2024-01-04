
#include<SFML/Graphics.hpp>
class Obstacles {
public:
    Obstacles(){
        getAsteroidImage();
    }
    void setAsteroidImage(sf::RenderWindow& window);
private:
    sf::Texture Asteroid1;
    sf::Texture Asteroid2;
    sf::Texture Asteroid3;
    sf::Texture Asteroid4;
    sf::Texture Asteroid5;
    sf::Texture Asteroid6;
    sf::Sprite AsteroidSprite1;
    sf::Sprite AsteroidSprite2;
    sf::Sprite AsteroidSprite3;
    sf::Sprite AsteroidSprite4;
    sf::Sprite AsteroidSprite5;
    sf::Sprite AsteroidSprite6;

    void getAsteroidImage();
    void setAsteroidMove(sf::Sprite& asteroid);
    void setAsteroidTemplate(sf::Sprite& asteroid , sf::Texture& texture);
    float AsteroidSpeedValues[4] = {2 , 6 , 9 , 11};
    int AsteroidSpeed = rand() % 3;
    float AsteroidAngleY[3] = {0.3 , 0.4 , 0.5};
    int AsteroidRandomY = rand() % 2;
};

void Obstacles::getAsteroidImage() {
    Asteroid1.loadFromFile(R"(C:\GamesCpp\TetrisGame\images\asteroid1.png)");
    Asteroid2.loadFromFile(R"(C:\GamesCpp\TetrisGame\images\asteroid2.png)");
    Asteroid3.loadFromFile(R"(C:\GamesCpp\TetrisGame\images\asteroid3.png)");
    Asteroid4.loadFromFile(R"(C:\GamesCpp\TetrisGame\images\asteroid4.png)");
    Asteroid5.loadFromFile(R"(C:\GamesCpp\TetrisGame\images\asteroid4.png)");
    Asteroid6.loadFromFile(R"(C:\GamesCpp\TetrisGame\images\asteroid3.png)");

    AsteroidSprite1.setTexture(Asteroid1);
    AsteroidSprite2.setTexture(Asteroid2);
    AsteroidSprite3.setTexture(Asteroid3);
    AsteroidSprite4.setTexture(Asteroid4);
    AsteroidSprite5.setTexture(Asteroid5);
    AsteroidSprite6.setTexture(Asteroid6);

    setAsteroidTemplate(AsteroidSprite1 , Asteroid1);
    setAsteroidTemplate(AsteroidSprite2 , Asteroid2);
    setAsteroidTemplate(AsteroidSprite3 , Asteroid3);
    setAsteroidTemplate(AsteroidSprite4 , Asteroid4);
    setAsteroidTemplate(AsteroidSprite5 , Asteroid5);
    setAsteroidTemplate(AsteroidSprite6 , Asteroid6);

}

void Obstacles::setAsteroidImage(sf::RenderWindow &window) {
    window.draw(AsteroidSprite1);
    window.draw(AsteroidSprite2);
    window.draw(AsteroidSprite3);
    window.draw(AsteroidSprite4);
    window.draw(AsteroidSprite5);
    window.draw(AsteroidSprite6);
    setAsteroidMove(AsteroidSprite1);
    setAsteroidMove(AsteroidSprite2);
    setAsteroidMove(AsteroidSprite3);
    setAsteroidMove(AsteroidSprite4);
    setAsteroidMove(AsteroidSprite5);
    setAsteroidMove(AsteroidSprite4);
    setAsteroidMove(AsteroidSprite6);
    setAsteroidMove(AsteroidSprite3);
}

void Obstacles::setAsteroidMove(sf::Sprite& asteroid) {
    float AsteroidX = asteroid.getPosition().x;
    float AsteroidY = asteroid.getPosition().y;
    asteroid.rotate(0.8);
    if(AsteroidX > -60){
        asteroid.move(-4, AsteroidAngleY[AsteroidRandomY] + 0.2);
    }
    else {
        float RandomY = (rand() % 740) -40;
        asteroid.setPosition(1100 + (rand() % 600), RandomY);
        asteroid.setScale(AsteroidAngleY[AsteroidRandomY] - 0.1, AsteroidAngleY[AsteroidRandomY] - 0.1);
        AsteroidSpeed = rand() % 3;
        AsteroidRandomY = rand() % 2;
    }
}

void Obstacles::setAsteroidTemplate(sf::Sprite &asteroid, sf::Texture &texture) {
    asteroid.setScale(AsteroidAngleY[AsteroidRandomY] - 0.1, AsteroidAngleY[AsteroidRandomY] - 0.1);
    asteroid.setOrigin((sf::Vector2f) texture.getSize() / 2.f);
    asteroid.setPosition(1100 + (rand() % 600) , (rand() % 750) - 40);
    AsteroidRandomY = (rand() % 2);
}
