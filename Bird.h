#include<SFML/Graphics.hpp>

class Bird{
public:
    Bird(){
        getBirdImage();
    }
    void setBirdImage(sf::RenderWindow& window);
    void setBirdTransition(sf::Event& event);

private:
    sf::Texture BirdImage;
    sf::Sprite BirdSprite;
    void getBirdImage();
    void setBirdNpcMode();
    void setBirdGravity();
    void setBirdJump();
    float BirdY = 0;
    float GravityPower = 3.5 , RotationAngle = 13;
    bool TransitionDown = true , TransitionUp = false;
    bool KeyPressed = true , KeyReleased = false;
    const float BirdPosX = 450,  BirdPosY = 320;
};

void Bird::getBirdImage() {
    BirdImage.loadFromFile("C:\\GamesCpp\\TetrisGame\\images\\birdDown.png");
    BirdSprite.setTexture(BirdImage);
    BirdSprite.setScale(0.3 , 0.3);
    BirdSprite.setPosition(BirdPosX , BirdPosY);
    BirdSprite.rotate(2);
}

void Bird::setBirdImage(sf::RenderWindow &window) {
    window.draw(BirdSprite);

    if(KeyPressed) {
        setBirdGravity();
        setBirdNpcMode();

    }
    else if(KeyReleased) setBirdJump();
}

void Bird::setBirdTransition(sf::Event &event) {
    if(event.type == sf::Event::KeyPressed){
        if(event.text.unicode == 57){
            if(KeyPressed){
                BirdImage.loadFromFile("C:\\GamesCpp\\TetrisGame\\images\\birdUp.png");
                BirdSprite.rotate(-RotationAngle);
                KeyPressed = false;
                KeyReleased = true;
                GravityPower -= float(800.f / 1500);

            }


        }
    }
    if(event.type == sf::Event::KeyReleased){
        if(event.text.unicode == 57){
           if(KeyReleased){
               BirdImage.loadFromFile("C:\\GamesCpp\\TetrisGame\\images\\birdDown.png");
               BirdSprite.rotate(RotationAngle);
               KeyPressed = true;
               KeyReleased = false;
           }
            GravityPower += float(800.f / 1500);



        }
    }
}

void Bird::setBirdNpcMode() {
    float CurrentBirdY = BirdSprite.getPosition().y;
   if(TransitionDown){
      BirdSprite.setPosition(BirdPosX , CurrentBirdY + BirdY);
      BirdY++;
   }
   else if(TransitionUp){
       BirdSprite.setPosition(BirdPosX , CurrentBirdY + BirdY);
       BirdY--;
   }
   if(BirdY == 4){
       TransitionUp = true;
       TransitionDown = false;
   }
   else if(BirdY == -5){
       TransitionDown = true;
       TransitionUp = false;
   }
}

void Bird::setBirdGravity() {
    float CurrentBirdY = BirdSprite.getPosition().y;
    if(CurrentBirdY < 660){
        BirdSprite.move(0 , GravityPower);
    }
}

void Bird::setBirdJump() {
    float CurrentBirdY = BirdSprite.getPosition().y;
    if(CurrentBirdY > 0){
        BirdSprite.move(0 , -GravityPower - 3);
    }
}