#include <SFML/Graphics.hpp>
#include"ScreenTemplate.h"
const float screen_width = 700;
const float screen_height = 900;
const float block_size = 50;
const float block_final = 500;
int main()
{
    sf::RenderWindow window(sf::VideoMode(screen_width , screen_height) , "TETRIS");
    ScreenTemplate temp;
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear(sf::Color::White);
        temp.setBlockField(window , block_size , screen_height , block_final);
        window.display();
    }

    return 0;
}