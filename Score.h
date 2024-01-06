#pragma once

#include<SFML/Graphics.hpp>
#include<iostream>
#include <SFML/System/Clock.hpp>

class Score{
public:
    Score(){
        getScoreText();
    }
    void setScoreText(sf::RenderWindow& window , bool& status , bool start);
    sf::Clock clock;
private:
    sf::Text ScoreText;
    sf::Font font;
    void getScoreText();

};

void Score::getScoreText() {
    font.loadFromFile(R"(C:\GamesCpp\TetrisGame\Fonts\Font.ttf)");
    ScoreText.setFont(font);
    ScoreText.setFillColor(sf::Color::White);
    ScoreText.setCharacterSize(30);
    ScoreText.setPosition(sf::Vector2f(20.f , 15.f));
}

void Score::setScoreText(sf::RenderWindow &window , bool& status , bool start) {
    window.draw(ScoreText);
    if(status && !start){
        sf::Time elapsed = clock.getElapsedTime();
        ScoreText.setString(std::to_string(elapsed.asSeconds()));
    }
    else{
        clock.restart();
    }

}