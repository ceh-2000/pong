#include <SFML/Graphics.hpp>
#include "PaddleView.h"
#include <iostream>

/*
This class allows us to draw the paddles
*/

void PaddleView::draw(sf::RenderWindow& app){
    sf::RectangleShape rectangle(sf::Vector2f(paddle.getWidth(), paddle.getHeight()));
    rectangle.setPosition(paddle.getPosition());
    app.draw(rectangle);
}
