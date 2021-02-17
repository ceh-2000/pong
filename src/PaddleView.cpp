#include "PaddleView.h"
#include <iostream>

/*
This class allows us to draw the paddles
*/

PaddleView::PaddleView(bool isAI){
    this->isAI = isAI;
}

PaddleView::~PaddleView(){}

void PaddleView::draw(Paddle& paddle, sf::RenderWindow& app){
    sf::RectangleShape rectangle(sf::Vector2f(paddle.getWidth(), paddle.getHeight()));
    rectangle.setPosition(paddle.getPosition());
    app.draw(rectangle);
}

void PaddleView::moveAI(Paddle& paddle, float windowHeight, float windowWidth, Ball ball, float deltaTime){
    float desiredY = AIFindY(paddle, windowHeight, windowWidth, ball);

    if(paddle.getPosition().y > desiredY){
        paddle.up(deltaTime);
    }
    else if(paddle.getPosition().y < desiredY){
        paddle.down(windowHeight, deltaTime);
    }
}

void PaddleView::moveHuman(Paddle& paddle, float windowHeight, float windowWidth, Ball ball, float deltaTime){
    // Move up given up arrow key input
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up)){
        paddle.up(deltaTime);
    }

    // Move down given up arrow key input
    else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Down)){
        paddle.down(windowHeight, deltaTime);
    }
}

void PaddleView::move(Paddle& paddle, float windowHeight, float windowWidth, Ball ball, float deltaTime){
    if(isAI == true){
        moveAI(paddle, windowHeight, windowWidth, ball, deltaTime);
    }
    else{
        moveHuman(paddle, windowHeight, windowWidth, ball, deltaTime);
    }
}

float PaddleView::AIFindY(Paddle& paddle, float windowHeight, float windowWidth, Ball ball){
    sf::Vector2f paddlePosition = paddle.getPosition();
    sf::Vector2f ballPosition = ball.getPosition();

    // The ball is in range; move the paddle to be in line witht he ball
    if(abs(paddlePosition.x - ballPosition.x) < windowWidth / 2.0f){
        // Line the middle of the paddle up with the ball
        return ball.getPosition().y - paddle.getHeight() / 2.0f + ball.getRadius();
    }
        
    // Put the paddle back in the middle
    return windowHeight / 2.0f - paddle.getHeight() / 2.0f;
}

