#pragma once
#include<SFML/Graphics.hpp>
#include<SFML/Audio/SoundBuffer.hpp>
#include<SFML/Audio/Sound.hpp>
#include<SFML/Audio/Music.hpp>
#include"Score.h"
class Bird:public Score{
public:
    Bird(){
        getBirdImage();
        getSound();
        getThunderImage();
        getRestertButton();
        DarkMusic.openFromFile(R"(C:\GamesCpp\TetrisGame\audio\dark.wav)");
        DarkMusic.setVolume(15);
        DarkMusic.play();
        ThunderBuffer.loadFromFile(R"(C:\GamesCpp\TetrisGame\audio\thunder.wav)");
        ThunderSound.setBuffer(ThunderBuffer);
        ThunderSound.setVolume(20);
    }
    void setBirdImage(sf::RenderWindow& window , bool& start);
    void setBirdTransition(sf::Event& event , bool start);
    void setThunderImage(sf::RenderWindow& window);
    void setRestartButton(sf::RenderWindow& window);
    void setRestartEvent(sf::Event& event){
        if(event.type == sf::Event::MouseButtonPressed){
            if(event.mouseButton.button == sf::Mouse::Left){
                int mouseX = event.mouseButton.x;
                int mouseY = event.mouseButton.y;
                if((mouseX >= 450 && mouseX <= 600) && (mouseY >= 350 && mouseY <= 410)){
                    BirdSprite.setPosition(BirdPosX , BirdPosX);
                    Status = true;
                }
            }
        }
    }
    bool Status = true;
    sf::Sprite BirdSprite;
    void setBirdNpcMode(sf::Sprite& ImageComponent , float MoveUp , float MoveDown , float& pos , float& CompX , bool& TDown , bool& TUp , float& BirdPos);

private:
    sf::Texture BirdImage;
    sf::Texture ThunderImage;
    sf::Sprite ThunderSprite;
    sf::SoundBuffer JumpBuffer;
    sf::SoundBuffer ThunderBuffer;
    sf::Sound ThunderSound;
    sf::Sound JumpSound;
    sf::Music DarkMusic;
    sf::Font font;
    sf::Text RestartText;
    sf::RectangleShape RestartButton;
    void getThunderImage();
    void getBirdImage();
    void setBirdGravity();
    void setBirdJump();
    void getSound();
    void getRestertButton();
    float BirdY = 0;
    float GravityPower = 4.3  , RotationAngle = 15;
    bool TransitionDown = true , TransitionUp = false;
    bool KeyPressed = true , KeyReleased = false;
    float BirdPosX = 470,  BirdPosY = 320;
protected:
};

void Bird::getBirdImage() {
    BirdImage.loadFromFile(R"(C:\GamesCpp\TetrisGame\images\birdDown.png)");
    BirdSprite.setTexture(BirdImage);
    BirdSprite.setScale(0.2 , 0.2);
    BirdSprite.setPosition(BirdPosX , BirdPosY);
    BirdSprite.rotate(2);
}

void Bird::setBirdImage(sf::RenderWindow &window , bool& start) {
    window.draw(BirdSprite);
    float BirdPy = BirdSprite.getPosition().y;
    if(Status){
        if(KeyPressed) {
            if(!start) {
                setBirdGravity();
                setBirdNpcMode(BirdSprite , 5 , 4 , BirdY , BirdPosX , TransitionDown , TransitionUp , BirdPy);

            }
            else{
                setBirdNpcMode(BirdSprite , 8 , 8 , BirdY , BirdPosX , TransitionDown , TransitionUp , BirdPy);
            }
        }
        else if(KeyReleased){
            if(!start)setBirdJump();
        }
    }
}

void Bird::setBirdTransition(sf::Event &event , bool start) {
    if(event.type == sf::Event::KeyPressed){
        if(event.text.unicode == 57){
            if(KeyPressed && !start){
                BirdImage.loadFromFile(R"(C:\GamesCpp\TetrisGame\images\birdUp.png)");
                BirdSprite.rotate(-RotationAngle);
                KeyPressed = false;
                KeyReleased = true;
                JumpSound.play();
            }
        }
    }
    if(event.type == sf::Event::KeyReleased){
        if(event.text.unicode == 57){
           if(KeyReleased && !start){
               BirdImage.loadFromFile(R"(C:\GamesCpp\TetrisGame\images\birdDown.png)");
               BirdSprite.rotate(RotationAngle);
               KeyPressed = true;
               KeyReleased = false;
           }
        }
    }
}

void Bird::setBirdNpcMode(sf::Sprite& ImageComponent , float MoveUp , float MoveDown , float& pos , float& CompX , bool& TDown , bool& TUp , float& BirdPos) {
    float CurrentBirdY = BirdSprite.getPosition().y;
   if(TDown){
      ImageComponent.setPosition(CompX , CurrentBirdY + pos);
      pos++;
   }
   else if(TUp){
       ImageComponent.setPosition(CompX , CurrentBirdY + pos);
       pos--;
   }
   if(pos == MoveUp){
       TUp = true;
       TDown = false;
   }
   else if(pos == -MoveDown){
       TDown = true;
       TUp = false;
   }
}

void Bird::setBirdGravity() {
    float CurrentBirdY = BirdSprite.getPosition().y;
    if(CurrentBirdY < 710){
        BirdSprite.move(0 , GravityPower);
    }
    else{
        Status = false;
        ThunderSound.play();
    }
}

void Bird::setBirdJump() {
    float CurrentBirdY = BirdSprite.getPosition().y;
    if(CurrentBirdY > -5){
        BirdSprite.move(0 , -GravityPower - 3);
    }
    else{
        Status = false;
        ThunderSound.play();
        KeyReleased = false; KeyPressed = true;
        BirdSprite.rotate(RotationAngle);
    }
}

void Bird::getSound() {
    JumpBuffer.loadFromFile(R"(C:\GamesCpp\TetrisGame\audio\jump.wav)");
    JumpSound.setBuffer(JumpBuffer);
}

void Bird::getThunderImage() {
    ThunderImage.loadFromFile(R"(C:\GamesCpp\TetrisGame\images\thunder.png)");
    ThunderSprite.setTexture(ThunderImage);
    ThunderSprite.setScale(0.4 , 0.4);
    ThunderSprite.setPosition(100 , 490);
}

void Bird::setThunderImage(sf::RenderWindow &window) {
    window.draw(ThunderSprite);
    float ThunderX = ThunderSprite.getPosition().x;
    if(ThunderX < -100){
        ThunderSprite.setPosition(1050 , 490);
    }
    else{
        if(Status) ThunderSprite.move(-3 , 0);
    }
}

void Bird::getRestertButton() {

    RestartButton.setSize(sf::Vector2f(150.f , 60.f));
    RestartButton.setPosition(450 , 350);
    font.loadFromFile(R"(C:\GamesCpp\TetrisGame\Fonts\Font.ttf)");
    RestartText.setFont(font);
    RestartText.setCharacterSize(40);
    RestartText.setPosition(456 , 354);
    RestartText.setString("Restart");
}

void Bird::setRestartButton(sf::RenderWindow &window) {
    window.draw(RestartButton);
    window.draw(RestartText);
    Status ? RestartText.setFillColor(sf::Color::Transparent) : RestartText.setFillColor(sf::Color::White);
    Status ? RestartButton.setFillColor(sf::Color::Transparent) : RestartButton.setFillColor(sf::Color(64 , 64 , 63));
}