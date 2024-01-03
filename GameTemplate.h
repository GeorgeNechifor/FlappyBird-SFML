#include<SFML/Graphics.hpp>
#include<iostream>
class GameTemplate{
public:
    GameTemplate(){
        getBackgroundImage();
        getDropImage();
        generateRandomPos();
    }
    void setBackgroundImage(sf::RenderWindow& window);
    void setDropImage(sf::RenderWindow& window);
private:
    sf::Sprite BackgroundImageSprite;
    sf::Sprite BackgroundImageSprite1;
    sf::Sprite BackgroundImageSprite2;
    sf::Sprite DropImageSprite;
    sf::Texture DropImage;
    sf::Texture BackgroundImage;
    void getBackgroundImage();
    void getDropImage();
    void setImagePosition();
    void generateRandomPos();
    const int DropsNumber = 10;
    bool startDrop = false;
    int MatrixPosition[101][101]{};
};

void GameTemplate::getBackgroundImage() {
    BackgroundImage.loadFromFile("C:\\GamesCpp\\TetrisGame\\images\\bkImage.png");
    BackgroundImageSprite.setTexture(BackgroundImage);
    BackgroundImageSprite1.setTexture(BackgroundImage);
    BackgroundImageSprite2.setTexture(BackgroundImage);
    float Image1X = BackgroundImageSprite.getPosition().x;
    float Image2X = BackgroundImageSprite1.getPosition().x;

    BackgroundImageSprite2.setPosition(2048 , 0);
    BackgroundImageSprite1.setPosition( 1024 , 0);
    setImagePosition();
}

void GameTemplate::setBackgroundImage(sf::RenderWindow& window) {
    window.draw(BackgroundImageSprite);
    window.draw(BackgroundImageSprite1);
    window.draw(BackgroundImageSprite2);
    setImagePosition();
}

void GameTemplate::setImagePosition() {

    if(BackgroundImageSprite.getPosition().x < -1022){
        BackgroundImageSprite.setPosition(2043, 0);
    }
    else BackgroundImageSprite.move(-3 , 0);

    if(BackgroundImageSprite1.getPosition().x < -1022){
        BackgroundImageSprite1.setPosition(2043 , 0);
    }
    else BackgroundImageSprite1.move(-3 , 0);

    if(BackgroundImageSprite2.getPosition().x < -1022){
        BackgroundImageSprite2.setPosition(2043 , 0);
    }
    else BackgroundImageSprite2.move(-3 , 0);

}

void GameTemplate::getDropImage() {
    DropImage.loadFromFile("C:\\GamesCpp\\TetrisGame\\images\\drop.png");
    DropImageSprite.setTexture(DropImage);

}

void GameTemplate::setDropImage(sf::RenderWindow &window) {
    for(int i = 0; i < DropsNumber;++i){
        if(i == 0){
            DropImageSprite.setPosition(float(rand() % 1024) , 0);
            if(!startDrop) startDrop = true;
        }

        window.draw(DropImageSprite);

    }
}

void GameTemplate::generateRandomPos() {

    for(int i = 0; i < DropsNumber;++i){
        for(int j = 0; j < 2;++j){
            if(j == 0){
                int RandomXStart = rand() % 2;
                MatrixPosition[i][j] = RandomXStart;
            }
            else if(j == 1){
                int RandomSpeed = rand() % 2;
                RandomSpeed++;
                MatrixPosition[i][j] = RandomSpeed;
            }
        }
    }
}