#pragma once
#include<SFML/Graphics.hpp>

class StartGame{
public:
    StartGame(){
        getStartButton();
        getTitle();
    }
    void setStartButton(sf::RenderWindow& window){
        window.draw(StartText);
    }
    void setTitle(sf::RenderWindow& window){
        window.draw(Title);
    }
    void startGameEvent(sf::Event& event ,  bool& start){
        if(event.type == sf::Event::KeyPressed){
            if(event.text.unicode == 58){
                if(start){
                    start = false;
                }
            }
        }
    }
    bool Start = true;
private:
    sf::Text StartText;
    sf::Text Title;
    sf::Font font;
    void getStartButton(){

        font.loadFromFile(R"(C:\GamesCpp\TetrisGame\Fonts\Font.ttf)");
        StartText.setFont(font);
        StartText.setCharacterSize(40);
        StartText.setPosition(330 , 220);
        StartText.setString("Press enter to start");
    }
    void getTitle(){
        font.loadFromFile(R"(C:\GamesCpp\TetrisGame\Fonts\Font.ttf)");
        Title.setFont(font);
        Title.setCharacterSize(70);
        Title.setString("Flappy Bird - Sad Mode");
        Title.setFillColor(sf::Color::White);
        Title.setPosition(140 , 100);
    }
};