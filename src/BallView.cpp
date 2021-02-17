#include "BallView.h"
#include <iostream>

/*
This class allows us to draw the paddles
*/

BallView::BallView(){
    if (!texture.loadFromFile("../data/ball.png"))
    {
        std::cout << "Could not load image from file." << std::endl;
    }
}

BallView::~BallView(){}

void BallView::move(Ball& ball, float deltaTime){
    ball.move(deltaTime);
}

void BallView::draw(Ball& ball, sf::RenderWindow& app){
    sf::CircleShape circle(ball.getRadius());
    circle.setFillColor(ball.getColor());
    const sf::Texture *pTexture = &texture;
    circle.setTexture(pTexture);
    circle.setPosition(ball.getPosition());
    app.draw(circle);
}




