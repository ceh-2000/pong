#include "PaddleViewHuman.h"
#include <iostream>

/*
This class allows us to determine the view for the human's paddle
*/


/*
Move the paddle according to keyboard input
*/
void PaddleViewHuman::move(float windowHeight, float windowWidth, Ball ball, float deltaTime){
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up)){
        paddle.up(deltaTime);
    }
    else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Down)){
        paddle.down(windowHeight, deltaTime);
    }
}
