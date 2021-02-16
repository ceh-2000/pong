#include "PaddleViewAI.h"
#include <iostream>

/*
This class allows us to determine the view for the AI's paddle
*/

/*
Find the best place to put the paddle and have the AI track that best position for the paddle
*/
void PaddleViewAI::AIFindY(float windowHeight, float windowWidth, Ball ball){
    sf::Vector2f paddlePosition = paddle.getPosition();
    sf::Vector2f ballPosition = ball.getPosition();

    // The ball is in range; move the paddle to be in line witht he ball
    if(abs(paddlePosition.x - ballPosition.x) < windowWidth / 2.0f){
        // Line the middle of the paddle up with the ball
        desiredY = ball.getPosition().y - paddle.getHeight() / 2.0f + ball.getRadius();
    }
    
    // Put the paddle back in the middle
    else{
        desiredY = windowHeight / 2.0f - paddle.getHeight() / 2.0f;
    }
}

/*
Determine the best move for the paddle given the best position for the paddle determined in the PaddleViewAI function
and MOVE
*/
void PaddleViewAI::move(float windowHeight, float windowWidth, Ball ball, float deltaTime){
    float desiredY = AIFindY(windowHeight, windowWidth, ball)

    if(paddle.getPosition().y < desiredY){
        paddle.up(deltaTime);
    }
    else if(paddleAI.getPosition().y > desiredY){
        paddle.down(deltaTime);
    }
}