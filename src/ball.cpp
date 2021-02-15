#include "Ball.h"
#include <iostream>
#include <cmath>

Ball::Ball(){
    this->dX = 0.0f;
    this->dY = 0.0f;

    ball.setRadius(10.0f);
    ball.setFillColor(sf::Color::Green);
}
 
Ball::~Ball(){

}

void Ball::setPosition(float x, float y){
  ball.setPosition(x, y);
}

void Ball::setVelocity(float speed){
    int dx = rand() % 150 + 50;
    int dy = sqrt(speed*speed - dx*dx);

    float positiveOrNegativeY = rand() % 2;

    dX = dx;
    dY = dy * pow(-1, positiveOrNegativeY);
}

void Ball::addRandomPerturbation(){
    // Randomize amount of perturbation
    float highestFloat = 5.0f;
    float xPerturbation = static_cast <float> (rand()) / (static_cast <float> (RAND_MAX/highestFloat));
    float yPerturbation = static_cast <float> (rand()) / (static_cast <float> (RAND_MAX/highestFloat));

    // Randomize sign of perturbation
    float positiveOrNegativeX = rand() % 2;
    float positiveOrNegativeY = rand() % 2;
    dX += pow(-1, positiveOrNegativeX) + xPerturbation;
    dY += pow(-1, positiveOrNegativeY) + yPerturbation;
}

void Ball::changeColor(){
    int r = rand() % 235 + 21; 
    int g = rand() % 235 + 21; 
    int b = rand() % 235 + 21; 
    ball.setFillColor(sf::Color(r, g, b));  
}

bool Ball::checkCollisionWall(sf::RenderWindow& app){
    sf::Vector2f ballPosition =  getPosition();
    sf::Vector2f ballHalfSize = getHalfSize();

    if(ballPosition.y <= 0 || ballPosition.y + ballHalfSize.y * 2.0f >= app.getSize().y){
        dY = -dY;
        // addRandomPerturbation();

        // Set the color of the ball to something random if there is a collision
        changeColor();

        return true;
    }
    return false;
}

bool Ball::checkCollision(Paddle& paddle){
    sf::FloatRect paddleBounds = paddle.getGlobalBounds();
    sf::FloatRect ballBounds = ball.getGlobalBounds();
    sf::FloatRect intersection;

    float ballWidth = ballBounds.width;
    float ballHeight = ballBounds.height;

    // If we intersect on the side of the paddle we want to change the x direction
    if(paddleBounds.intersects(ballBounds, intersection)){

        // If we intersect on the side of the paddle we want to change the x direction
        // We know that the height of our intersection rectangle will match the height of 
        // our ball if we have a hit on the side of the paddle
        if(abs(ballHeight - intersection.height) < 0.01f){
            dX = -dX;
        }
        
        // If we intersect on the top or bottom of the paddle, we want to change the y direction


        // If we intersect on the top/bottom and side of the paddle, we want to change both the x and y direction







        // addRandomPerturbation();

        // Set the color of the ball to something random if there is a collision
        changeColor();

        // Notify the that we have a collision
        return true;
    }



    // Notify the that we have no collision
    return false;
}

int Ball::checkWin(sf::RenderWindow& app){
    sf::Vector2f ballPosition =  getPosition();
    sf::Vector2f ballHalfSize = getHalfSize();

    if(ballPosition.x + ballHalfSize.x * 2.0f <= 0){
        return 2;
    } 
    if(ballPosition.x - ballHalfSize.x * 4.0f >= app.getSize().x){    
        return 1;
    }
    return 0;
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
