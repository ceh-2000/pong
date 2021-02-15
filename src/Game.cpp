#include <SFML/Graphics.hpp>
#include <iostream>
#include "Paddle.h"
#include "Ball.h"
#include "Game.h"

Game::Game(Paddle& paddleAI, Paddle& paddleHuman, Ball& ball):
    paddleAI(paddleAI),
    paddleHuman(paddleHuman),
    ball(ball)
{
    this->desiredY = 0.0f;
}

Game::~Game(){

}

void Game::resetGame(){
  
}

void Game::resetRound(){
  paddleAI.setPosition(100.0f, 400.0f);
  paddleHuman.setPosition(700.0f, 400.0f);
  ball.setPosition(400.0f, 300.0f);
  ball.setVelocity(200.0f);
  desiredY = 400.0f;
}

void Game::AIFindY(float dX, float dY, sf::Vector2f pos){
    desiredY = pos.y;
    // float x = pos.x;
    // float y = pos.y;

    // if(dY < 0){
    //     dX = abs(dX);
    //     dY = abs(dY);
    //     desiredY = dX/dY*(dY/dX*y-100);
    // }
    // else{
    //     dX = abs(dX);
    //     dY = abs(dY);
    //     desiredY = dX/dY*(dY/dX*(600-y)-100);
    // }
}

void Game::updateGame(sf::RenderWindow& app, float deltaTime){
    // Update the AI's paddle
    if(paddleAI.getPosition().y < desiredY){
        paddleAI.update(deltaTime, false);
    }
    else if(paddleAI.getPosition().y > desiredY){
        paddleAI.update(deltaTime, true);
    }

    // Draw the new position of our paddle given keyboard input
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up)){
        paddleHuman.update(deltaTime, true);
    }
    else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Down)){
      paddleHuman.update(deltaTime, false);
    }
    
    AIFindY(ball.getdX(), ball.getdY(), ball.getPosition());

    // Update the ball
    ball.checkCollision(paddleAI);
    ball.checkCollision(paddleHuman);
    // if(ball.checkCollision(paddleHuman)==true){
    //     AIFindY(ball.getdX(), ball.getdY(), ball.getPosition());
    // }
    ball.checkCollisionWall(app);
    int win = ball.checkWin(app);
    if(win == 0){
      ball.update(deltaTime);
    }
    else{
      resetRound();
    }

    // clear screen and fill with blue
    app.clear(sf::Color(30,144,255));

    paddleAI.draw(app);
    paddleHuman.draw(app);
    ball.draw(app);

    // display
    app.display();
}