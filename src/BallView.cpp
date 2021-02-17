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
    sf::CircleShape circle(ball.getRadius());
    circle.setFillColor(sf::Color(150, 50, 250));
    circle.setPosition(ball.getPosition());
    app.draw(circle);
}




