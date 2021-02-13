#include "Paddle.h"
#include <iostream>

Paddle::Paddle(float speed){
    this->speed = speed;

    // Vector2f is a float vector that we use to make our paddle
    paddle.setSize(sf::Vector2f(30.0, 100.0));
    paddle.setFillColor(sf::Color::White);

    // Let's add a texture to our paddle
    sf::Texture paddleTexture;
    // TODO: Fix this file path to work as a relative path
    
    paddleTexture.loadFromFile("/Users/clareheinbaugh/Desktop/game-design/pong/src/leaves.jpg");
    paddle.setTexture(&paddleTexture);

}
 
Paddle::~Paddle(){
}

void Paddle::setPosition(float x, float y){
  paddle.setPosition(x, y);
}

void Paddle::update(float deltaTime, bool isUp)
{
    sf::Vector2f movement(0.0f, 0.0f);

    // Move up
    if(isUp == true){
      movement.y -= speed * deltaTime; // x = v * t
    }
    // Move down
    else{
      movement.y += speed * deltaTime; // x = v * t
    }

    paddle.move(movement);
}

void Paddle::draw(sf::RenderWindow& app){
    app.draw(paddle);
}