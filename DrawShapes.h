#include<SFML/Graphics.hpp>
#include <chrono>
#include <thread>
#include <functional>
#include"Shapes.h"
#include<iostream>

class DrawShapes: protected StyleComponents , protected Shapes{
public:
    void ShapeMove(sf::RenderWindow& screen);
    void event(sf::Event& event);
    static void setTimeout(int milli);
private:
    sf::RectangleShape block;
    int startX = 200 , startY = 0;
    int VerticalMove = 0;
    int HorizontalMove = 200;
};

void DrawShapes::event(sf::Event &event) {
    if(event.type == sf::Event::KeyPressed){
        std::cout << event.text.unicode << "\n";
        if(event.text.unicode == 58){
           VerticalMove += 20;
        }
        else if(event.text.unicode == 71){  //move shape to left
            if(HorizontalMove > 0){
                HorizontalMove -= 50;
            }
        }
        else if(event.text.unicode == 72){ //move shape to right
            if(HorizontalMove < 400){
                HorizontalMove += 50;
            }
        }
    }

}

void DrawShapes::ShapeMove(sf::RenderWindow &screen ) {
    if(VerticalMove < 750){
        VerticalMove += 2;
    }
    startX = HorizontalMove , startY = VerticalMove;
    for(int i = 0; i < 3;++i){
       for(int j = 0 ; j < 3;++j){
           if(shapeModel[i][j] == 1){
               BodyBlockStyle(block , 50 , 50 , startX, startY);
               screen.draw(block);
               if(shapeModel[i][j + 1]) startX += 50;
           }
       }
       startY += 50;
    }

}

void DrawShapes::setTimeout(int milli) {
    std::this_thread::sleep_for(std::chrono::milliseconds(milli));
}