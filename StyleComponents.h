#include<SFML/Graphics.hpp>

class StyleComponents{
protected:
    static void BodyBlockStyle(sf::RectangleShape& component , float width , float height , int x , int y);
    static void MarginBlockStyle(sf::RectangleShape& component);
    static void TextStyle(sf::Text& text);
};

void StyleComponents::TextStyle(sf::Text &text) {
    sf::Font font;
    font.loadFromFile("C:\\sfmlFonts\\CascadiaMono.ttf");
    text.setFont(font);
}
void StyleComponents::BodyBlockStyle(sf::RectangleShape &component, float width, float height, int x, int y) {
    component.setSize(sf::Vector2f(width , height));
    component.setFillColor(sf::Color::Green);
    component.setPosition(x , y);
    component.setOutlineThickness(1);
    component.setOutlineColor(sf::Color::Black);
}

void StyleComponents::MarginBlockStyle(sf::RectangleShape &component) {

}