#include<SFML/Graphics.hpp>
#include"StyleComponents.h"
#include<string>

class ScreenTemplate:protected StyleComponents{
public:
    void static setBlockField(sf::RenderWindow& screen , float block_size , float screen_height , float block_final);
    void setPanelField(sf::RenderWindow& screen , float block_final);
};

void ScreenTemplate::setBlockField(sf::RenderWindow& screen , float block_size ,float screen_height, float block_final) {
    float local_block_size = block_size;

    //draw vertical lines
    while(local_block_size < block_final){
        sf::Vertex VerticalLine[] =
                {
                        sf::Vertex(sf::Vector2f(local_block_size, 0) , sf::Color::Black),
                        sf::Vertex(sf::Vector2f(local_block_size, screen_height) , sf::Color::Black)
                };

        screen.draw(VerticalLine , 2 , sf::Lines);
        local_block_size += block_size;
    }

    local_block_size = block_size;

    //draw horizontal lines
    while(local_block_size < screen_height){
        sf::Vertex HorizontalLine[] =
                {
                        sf::Vertex(sf::Vector2f(0, local_block_size) , sf::Color::Black),
                        sf::Vertex(sf::Vector2f(block_final - block_size, local_block_size) , sf::Color::Black)
                };
        screen.draw(HorizontalLine , 2 , sf::Lines);
        local_block_size += block_size;
    }

}

void ScreenTemplate::setPanelField(sf::RenderWindow &screen, float block_final) {

}

