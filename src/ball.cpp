#include "Ball.h"
#include <iostream>

Ball::Ball(float dX, float dY){
    this->dX = dX;
    this->dY = dY;

    ball.setRadius(10.0f);
    ball.setFillColor(sf::Color::Green);
}
 
Ball::~Ball(){

}

bool Ball::checkCollisionWall(sf::RenderWindow& app){
    // sf::FloatRect windowBoundingBox(0.0f, 0.0f, app.getSize().x, app.getSize().y);
    sf::Vector2f ballPosition =  getPosition();
    sf::Vector2f ballHalfSize = getHalfSize();

    if(ballPosition.y - ballHalfSize.y * 2.0f <= 0 || ballPosition.y + ballHalfSize.y * 2.0f >= app.getSize().y){
        dY = -dY;

        // Set the color of the ball to something random if there is a collision
        int r = rand() % 255 + 1; 
        int g = rand() % 255 + 1; 
        int b = rand() % 255 + 1; 
        ball.setFillColor(sf::Color(r, g, b));      

        return true;
    }
    return false;
}

bool Ball::checkCollision(Paddle& paddle){
    // Let's get the position and half the size for both the paddle and the ball
    sf::Vector2f paddlePosition = paddle.getPosition();
    sf::Vector2f paddleHalfSize = paddle.getHalfSize();
    sf::Vector2f ballPosition =  getPosition();
    sf::Vector2f ballHalfSize = getHalfSize();

    // Let's get the difference between the paddle and the ball
    float deltaX = paddlePosition.x - ballPosition.x;
    float deltaY = paddlePosition.y - ballPosition.y;

    // Let's see if we have an intersection between the bounds of the ball & the paddle
    float intersectX = abs(deltaX) - (paddleHalfSize.x + ballHalfSize.x);
    float intersectY = abs(deltaY) - (paddleHalfSize.y + ballHalfSize.y);

    if(intersectX < 0.0f && intersectY < 0.0f)
    {
        // Change the x direction
        dX = -dX;

        // Set the color of the ball to something random if there is a collision
        int r = rand() % 255 + 1; 
        int g = rand() % 255 + 1; 
        int b = rand() % 255 + 1; 
        ball.setFillColor(sf::Color(r, g, b));        

        // Notify the thread of a collision
        return true;
    }

    // Notify the thread of no collision
    return false;
}

void Ball::setPosition(float x, float y){
  ball.setPosition(x, y);
}

void Ball::update(float deltaTime)
{
    sf::Vector2f movement(0.0f, 0.0f);

    movement.x += dX * deltaTime; // x = v * t
    movement.y += dY * deltaTime; // x = v * t

    ball.move(movement);
}

void Ball::draw(sf::RenderWindow& app){
    app.draw(ball);
}