#include <SFML/Graphics.hpp>
#include <iostream>
#include "Game.h"

Game::Game(Paddle& paddle1, Paddle& paddle2, Ball& ball, PaddleView& paddle1View, PaddleView& paddle2View, BallView& ballView):
  paddle1(paddle1),
  paddle2(paddle2),
  ball(ball),
  paddle1View(paddle1View),
  paddle2View(paddle2View),
  ballView(ballView)
{
  // Set the initial scores
  this->score1 = 0;
  this->score2 = 0;

  // Set the font of our text
  if (!font.loadFromFile("../data/Newsreader_18pt-Regular.ttf"))
  {
    std::cout << "Could not load font." << std::endl;
  }

  displayScore.setFont(font); 
}

Game::~Game(){}


// void Game::resetGame(){
  
// }

// void Game::resetRound(float windowWidth, float windowHeight, float velocity){
//   if(score1 == 3){
//     std::cout << "Player 1 wins!" << std::endl;
//     score1 = 0;
//     score2 = 0;
//   }
//   else if(score2 == 3){
//     std::cout << "Player 2 wins!" << std::endl;
//     score1 = 0;
//     score2 = 0;
//   }

//   displayScore.setString("Player 1: "+std::to_string(score1)+" | Player 2: "+std::to_string(score2));
//   displayScore.setPosition(windowWidth / 2.0f -  130.0f, 0); 

//   paddle1.setPosition();
//   paddleHuman.setPosition(windowWidth - 100.0f, windowHeight / 2.0f - paddleHuman.getHalfSize().y);
//   ball.setPosition(windowWidth / 2.0f, windowHeight / 2.0f);
//   ball.setVelocity(velocity);
// }

void Game::updateGame(sf::RenderWindow& app, float deltaTime){
    float windowWidth = app.getSize().x;
    float windowHeight = app.getSize().y;

    // Update the paddles
    paddle1View.move(paddle1, windowHeight, windowWidth, ball, deltaTime); 
    paddle2View.move(paddle2, windowHeight, windowWidth, ball, deltaTime); 
    ballView.move(ball, deltaTime);

    // Check if either player has won the round
    // int win = ball.checkWin(app);
    // if(win == 2){
    //   score2 += 1;
    //   resetRound(app.getSize().x, app.getSize().y, 400.0f);
    // }
    // else if(win == 1){
    //   score1 += 1;
    //   resetRound(app.getSize().x, app.getSize().y, 400.0f);
    // }
    // else{
    //     ball.update(deltaTime);
    // }

    // // Update the ball according to collisions

    // ball.checkCollision(paddleAI);
    // ball.checkCollision(paddleHuman);
    // ball.checkCollisionWall(app);

    // // Resolve any lingering intersections using the new trajectory (velocity) of the ball
    // while(ball.checkIntersections(paddleAI, app) || ball.checkIntersections(paddleHuman, app))
    // {
    //     ball.update(deltaTime); //another option is to move ball immediately outside and then continue game
    // }

    // clear screen and fill with blue
    app.clear(sf::Color::Red);

    app.draw(displayScore);
    paddle1View.draw(paddle1, app);
    paddle2View.draw(paddle2, app);
    ballView.draw(ball, app);

    // display
    app.display();
}