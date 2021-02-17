#include "BallView.h"
#include <iostream>

/*
This class allows us to draw the paddles
*/

BallView::BallView(){}

BallView::~BallView(){}

void BallView::move(Ball& ball, float deltaTime){
    ball.move(deltaTime);
}

void BallView::draw(Ball& ball, sf::RenderWindow& app){
    std::cout << ball.getPosition().x << std::endl;

    sf::CircleShape shape(ball.getRadius());
    shape.setFillColor(sf::Color(150, 50, 250));
    shape.setPosition(ball.getPosition());
    app.draw(shape);
    // sf::CircleShape circle(ball.getRadius());
    // circle.setPosition(ball.getPosition());
    // app.draw(circle);
}




