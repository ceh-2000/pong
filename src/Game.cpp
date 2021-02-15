#include <SFML/Graphics.hpp>
#include <iostream>
#include "Paddle.h"
#include "Ball.h"
#include "Game.h"

Game::Game(Paddle& paddleAI, Paddle& paddleHuman, Ball& ball, sf::Font& font):
    paddleAI(paddleAI),
    paddleHuman(paddleHuman),
    ball(ball),
    font(font)
{
    this->desiredY = 0.0f;
    this->score1 = 0;
    this->score2 = 0;

    // Set the font of our text
    displayScore.setFont(font); 
}

Game::~Game(){

}

void Game::resetGame(){
  
}

void Game::resetRound(float windowWidth, float windowHeight, float velocity){
  displayScore.setString("Player 1: "+score1);
  
  paddleAI.setPosition(100.0f, windowHeight / 2.0f - paddleAI.getHalfSize().y);
  paddleHuman.setPosition(windowWidth - 100.0f, windowHeight / 2.0f - paddleHuman.getHalfSize().y);
  ball.setPosition(windowWidth / 2.0f, windowHeight / 2.0f);
  ball.setVelocity(velocity);
  desiredY = windowHeight / 2.0f;

  if(score1 == 3){
    std::cout << "Player 1 wins!" << std::endl;
    score1 = 0;
    score2 = 0;
  }
  else if(score2 == 3){
    std::cout << "Player 2 wins!" << std::endl;
    score1 = 0;
    score2 = 0;
  }
}

void Game::AIFindY(float windowHeight){
    if(ball.getdX() < 0){
        desiredY = ball.getPosition().y - paddleAI.getHalfSize().y + ball.getHalfSize().y;
    }
    else{
        desiredY = windowHeight / 2.0f - paddleAI.getHalfSize().y;
    }
}

void Game::updateGame(sf::RenderWindow& app, float deltaTime){
    // Update the AI's paddle
    AIFindY(app.getSize().y);
    if(paddleAI.getPosition().y < desiredY && ball.getPosition().x < app.getSize().x / 2.0f){
        paddleAI.update(deltaTime, false);
    }
    else if(paddleAI.getPosition().y > desiredY && ball.getPosition().x < app.getSize().x / 2.0f){
        paddleAI.update(deltaTime, true);
    }

    // Draw the new position of our paddle given keyboard input
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up)){
        paddleHuman.update(deltaTime, true);
    }
    else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Down)){
      paddleHuman.update(deltaTime, false);
    }

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
    else if(win == 1){
      score1 += 1;
      resetRound(app.getSize().x, app.getSize().y, 400.0f);
    }
    else{
      score2 += 1;
      resetRound(app.getSize().x, app.getSize().y, 400.0f);
    }



    // clear screen and fill with blue
    app.clear(sf::Color::Black);

    paddleAI.draw(app);
    paddleHuman.draw(app);
    ball.draw(app);

    // display
    app.display();
}