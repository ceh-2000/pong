#include "Paddle.h"
#include <iostream>

/*
Paddle constructors
*/
Paddle::Paddle(sf::Vector2f position, float speed, float width, float height){
  this->position = position;
  this->speed = speed;
  this->width = width;
  this->height = height;
}
 
Paddle::~Paddle(){}

/*
Move the paddle up at a fixed speed given the time input
*/
void Paddle::up(float deltaTime)
{
  // Make sure we're not moving the paddle out of bounds
  if(position.y - speed * deltaTime >= 0.0f){
    position.y -= speed * deltaTime; // x = v * t
  }
}

/*
Move the paddle down at a fixed speed given the time input
*/
void Paddle::down(float windowHeight, float deltaTime)
{
  // Make sure we're not moving the paddle out of bounds
  if(position.y + height + speed * deltaTime <= windowHeight){
    position.y += speed * deltaTime; // x = v * t
  }
}


    // // Let's add a texture to our paddle
    // sf::Texture texture;
    // if (!texture.loadFromFile("../data/dog.png"))
    // {
    //     std::cout << "No texture found." << std::endl;
    // }
    // sf::Sprite sprite;
    // sprite.setTexture(texture);
