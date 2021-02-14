#include "Ball.h"
#include <iostream>

Ball::Ball(float speed){
    this->speed = speed;

    ball.setRadius(10.0f);
    ball.setFillColor(sf::Color::Green);
}
 
Ball::~Ball(){
}

bool Ball::checkCollision(Paddle& paddle, float reaction){
    // Let's get the position and half the size for both the paddle and the ball
    sf::Vector2f paddlePosition = paddle.getPosition();
    sf::Vector2f paddleHalfSize = paddle.getHalfSize();
    sf::Vector2f ballPosition =  getPosition();
    sf::Vector2f ballHalfSize = getHalfSize();

    // Let's get the difference between the paddle and the ball
    float deltaX = paddlePosition.x - ballPosition.x;
    float deltaY = paddlePosition.y - ballPosition.y;

}

void Ball::setPosition(float x, float y){
  ball.setPosition(x, y);
}

void Ball::update(float deltaTime)
{
    sf::Vector2f movement(0.0f, 0.0f);

    movement.x += speed * deltaTime; // x = v * t

    ball.move(movement);
}

void Ball::draw(sf::RenderWindow& app){
    app.draw(ball);
}