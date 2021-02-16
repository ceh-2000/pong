#include "PaddleViewHuman.h"
#include <iostream>

/*
This class allows us to determine the view for the human's paddle
*/

/*
PaddleViewHuman constructors
*/
// PaddleViewHuman::PaddleViewHuman(Paddle& paddle):
//     paddle(paddle)
// {}
// PaddleViewHuman::~PaddleViewHuman(){}

/*
Move the paddle according to keyboard input
*/
void PaddleViewHuman::move(float windowHeight, float deltaTime){
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up)){
        paddle.up(deltaTime);
    }
    else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Down)){
        paddle.down(windowHeight, deltaTime);
    }
}
