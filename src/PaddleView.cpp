#include "PaddleView.h"
#include <iostream>

/*
This class allows us to draw the paddles
*/


/*
PaddleView constructors
*/
PaddleView::PaddleView(bool isAI){
    this->isAI = isAI;

    if (!texture.loadFromFile("../data/mask_vert.png"))
    {
        std::cout << "Could not load image from file." << std::endl;
    }
}

PaddleView::~PaddleView(){}

/*
AI determines the best position to move the paddle and then moves
*/
void PaddleView::moveAI(Paddle& paddle, float windowHeight, float windowWidth, Ball ball, float deltaTime){
    float desiredY = AIFindY(paddle, windowHeight, windowWidth, ball);

    if(paddle.getPosition().y > desiredY){
        paddle.up(deltaTime);
    }
    else if(paddle.getPosition().y < desiredY){
        paddle.down(windowHeight, deltaTime);
    }
}

/*
Human uses arrow keys to move paddle up and down
*/
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

/*
Determine which moving schema to use depending on if our paddle is controlled by AI or human
*/
void PaddleView::move(Paddle& paddle, float windowHeight, float windowWidth, Ball ball, float deltaTime){
    if(isAI == true){
        moveAI(paddle, windowHeight, windowWidth, ball, deltaTime);
    }
    else{
        moveHuman(paddle, windowHeight, windowWidth, ball, deltaTime);
    }
}

/*
AI uses this method to find the best position for its paddle along the Y-axis
*/
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

/*
Draw the paddle given the position, width, and height
*/
void PaddleView::draw(Paddle& paddle, sf::RenderWindow& app){
    sf::RectangleShape rectangle(sf::Vector2f(paddle.getWidth(), paddle.getHeight()));
    const sf::Texture *pTexture = &texture;
    rectangle.setTexture(pTexture);
    rectangle.setPosition(paddle.getPosition());
    app.draw(rectangle);
}