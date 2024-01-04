#include<SFML/Graphics.hpp>
#include<SFML/Audio/SoundBuffer.hpp>
#include<SFML/Audio/Sound.hpp>
#include<SFML/Audio/Music.hpp>

class Bird{
public:
    Bird(){
        getBirdImage();
        getSound();
        getThunderImage();
        getRestartButton();
        DarkMusic.openFromFile(R"(C:\GamesCpp\TetrisGame\audio\dark.wav)");
        DarkMusic.setVolume(15);
        DarkMusic.play();
        ThunderBuffer.loadFromFile(R"(C:\GamesCpp\TetrisGame\audio\thunder.wav)");
        ThunderSound.setBuffer(ThunderBuffer);
        ThunderSound.setVolume(20);
    }
    void setBirdImage(sf::RenderWindow& window);
    void setBirdTransition(sf::Event& event);
    void setThunderImage(sf::RenderWindow& window);
    void setRestartButton(sf::RenderWindow& window);
    bool Status = true;
    sf::Sprite BirdSprite;
private:
    sf::Texture BirdImage;
    sf::Texture ThunderImage;
    sf::Sprite ThunderSprite;
    sf::SoundBuffer JumpBuffer;
    sf::SoundBuffer ThunderBuffer;
    sf::Sound ThunderSound;
    sf::Sound JumpSound;
    sf::Music DarkMusic;
    sf::Text RestartText;
    sf::RectangleShape RestartButton;
    sf::Font font;
    void getThunderImage();
    void getBirdImage();
    void setBirdNpcMode();
    void setBirdGravity();
    void setBirdJump();
    void getSound();
    void getRestartButton();
    float BirdY = 0;
    float GravityPower = 4.3  , RotationAngle = 15;
    bool TransitionDown = true , TransitionUp = false;
    bool KeyPressed = true , KeyReleased = false;
    const float BirdPosX = 450,  BirdPosY = 320;
protected:
};

void Bird::getBirdImage() {
    BirdImage.loadFromFile(R"(C:\GamesCpp\TetrisGame\images\birdDown.png)");
    BirdSprite.setTexture(BirdImage);
    BirdSprite.setScale(0.2 , 0.2);
    BirdSprite.setPosition(BirdPosX , BirdPosY);
    BirdSprite.rotate(2);
}

void Bird::setBirdImage(sf::RenderWindow &window) {
    window.draw(BirdSprite);
    if(Status){
        if(KeyPressed) {
            setBirdGravity();
            setBirdNpcMode();
        }
        else if(KeyReleased){
            setBirdJump();
        }
    }
}

void Bird::setBirdTransition(sf::Event &event) {
    if(event.type == sf::Event::KeyPressed){
        if(event.text.unicode == 57){
            if(KeyPressed){
                BirdImage.loadFromFile(R"(C:\GamesCpp\TetrisGame\images\birdUp.png)");
                BirdSprite.rotate(-RotationAngle);
                KeyPressed = false;
                KeyReleased = true;
                GravityPower -= float(800.f / 1500);
                JumpSound.play();
            }
        }
    }
    if(event.type == sf::Event::KeyReleased){
        if(event.text.unicode == 57){
           if(KeyReleased){
               BirdImage.loadFromFile(R"(C:\GamesCpp\TetrisGame\images\birdDown.png)");
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
   if(BirdY == 5){
       TransitionUp = true;
       TransitionDown = false;
   }
   else if(BirdY == -4){
       TransitionDown = true;
       TransitionUp = false;
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
    if(CurrentBirdY > 0){
        BirdSprite.move(0 , -GravityPower - 3);
    }
    else{
        Status = false;
        ThunderSound.play();
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
        ThunderSprite.move(-3 , 0);
    }
}

void Bird::getRestartButton() {
    RestartButton.setSize(sf::Vector2f(150.f , 60.f));
    RestartButton.setPosition(450 , 350);
    font.loadFromFile(R"(C:\GamesCpp\TetrisGame\Fonts\Font.ttf)");
    RestartText.setFont(font);
    RestartText.setCharacterSize(40);
    RestartText.setPosition(456 , 354);
    RestartText.setString("Restart");
}

void Bird::setRestartButton(sf::RenderWindow &window) {
    Status ? RestartButton.setFillColor(sf::Color::Transparent) : RestartButton.setFillColor(sf::Color::Black);
    Status ? RestartText.setFillColor(sf::Color::Transparent) : RestartText.setFillColor(sf::Color::White);
    window.draw(RestartButton);
    window.draw(RestartText);
}