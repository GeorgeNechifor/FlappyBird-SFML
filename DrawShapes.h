#include<SFML/Graphics.hpp>
#include <chrono>
#include <thread>
#include <functional>
#include"Shapes.h"
#include<iostream>
#include<vector>

class DrawShapes: protected StyleComponents , protected Shapes{
public:
    DrawShapes()= default;
    void ShapeMove(sf::RenderWindow& screen);
    void ShapeEvent(sf::Event& event);
    int GetShapeWidth();
    int GetShapeHeight();
    static void setTimeout(int milli);
private:
    sf::RectangleShape block;
    int startX = 200 , startY = 0;
    int VerticalMove = 0;
    int HorizontalMove = 200;
    int ShapeWidth = GetShapeWidth() , ShapeHeight = GetShapeHeight();
};

int DrawShapes::GetShapeWidth() {
    int maxWidth = 0;
    for(int i = 0; i < 3;++i){
        int localLength = 0;
        for(int j = 0; j < 3;++j){
            if(shapeModel[i][j]) localLength++;
        }
        if(localLength > maxWidth) maxWidth = localLength;
    }
    return maxWidth;//maximum width of the current shape
}

int DrawShapes::GetShapeHeight() {
    int maxHeight = 0;
    for(int i = 0; i < 3;++i){
        int localLength = 0;
        for(int j = 0; j < 3;++j){
            if(shapeModel[j][i]) localLength++;
        }
        if(localLength > maxHeight) maxHeight = localLength;
    }
    return maxHeight; //maximum height of the current shape
}

void DrawShapes::ShapeEvent(sf::Event &event) {
    if(event.type == sf::Event::KeyPressed){
        if(event.text.unicode == 74){
            if(VerticalMove < 900 - (50 * ShapeHeight) - 20) VerticalMove += 20;
        }
        else if(event.text.unicode == 71){  //move shape to left
            if(HorizontalMove > 0){
                HorizontalMove -= 50;
            }
        }
        else if(event.text.unicode == 72){ //move shape to right
            if(HorizontalMove < 450 - (50 * ShapeWidth)){
                HorizontalMove += 50;
            }
        }
    }
}

void DrawShapes::ShapeMove(sf::RenderWindow &screen ) {
    if(VerticalMove < 900 - (50 * ShapeHeight)){
        VerticalMove += 2;
    }
    startX = HorizontalMove , startY = VerticalMove;
    for(int i = 0; i < 3;++i){
        int times = 0;
       for(int j = 0 ; j < 3;++j){
           if(shapeModel[i][j] == 1){
               BodyBlockStyle(block , 50 , 50 , startX, startY);
               screen.draw(block);
               if(j < 2){
                   if(shapeModel[i][j + 1]) {
                       startX += 50;
                       times++;
                   }
               }
           }
       }
       if(i < 2 && shapeModel[i + 1][0]) startX -= times * 50;
       startY += 50;
    }
}

void DrawShapes::setTimeout(int milli) {
    std::this_thread::sleep_for(std::chrono::milliseconds(milli));
}
