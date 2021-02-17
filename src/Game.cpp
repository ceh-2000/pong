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

  this->gameHappening = false;
}

Game::~Game(){}


void Game::resetGame(sf::RenderWindow& app, int winner){
  gameHappening = false;
  displayScore.setCharacterSize(50); 
  displayScore.setPosition(0, 0); 
  if(winner == 2){
    displayScore.setString("Player 2 Wins!\nPress Space Bar to start\nor exit to quit.");
  }
  else if(winner == 1){
    displayScore.setString("Player 1 Wins!\nPress Space Bar to start\nor exit to quit.");
  }
  else{
    displayScore.setString("Press Space Bar to start\nor exit to quit.");
  }



  app.clear(sf::Color::Blue);
  
  app.draw(displayScore);

  app.display();


  if(sf::Keyboard::isKeyPressed(sf::Keyboard::Space)){
    this->score1 = 0;
    this->score2 = 0;
    gameHappening = true;
    resetRound(app, app.getSize().x, app.getSize().y, 400.0f);
    
  }
}

void Game::resetRound(sf::RenderWindow& app, float windowWidth, float windowHeight, float velocity){
  // Check for a game win
  if(score1 == 11){
    resetGame(app, 1);    
  }
  else if(score2 == 11){
    resetGame(app, 2);
  }

  // Update the text that shows the score
  displayScore.setString("Player 1: "+std::to_string(score1)+" | Player 2: "+std::to_string(score2));
  displayScore.setPosition(windowWidth / 2.0f -  130.0f, 0); 
  displayScore.setCharacterSize(30); 

  // Reposition the paddles and ball
  float paddleDistanceFromEdge = 100.0f;
  paddle1.setPosition(paddleDistanceFromEdge, windowHeight / 2.0f - paddle1.getHeight() / 2.0f);
  paddle2.setPosition(windowWidth - paddleDistanceFromEdge, windowHeight / 2.0f - paddle2.getHeight() / 2.0f);
  ball.setPosition(windowWidth / 2.0f - ball.getRadius(), windowHeight / 2.0f - ball.getRadius());

  // Scale the ball's velocity based on how far the player has come
  float ballVelocity = velocity + score1*20 + score2*20;
  ball.setRandomVelocity(ballVelocity);
}

void Game::updateGame(sf::RenderWindow& app, float deltaTime){
    if(gameHappening == true){
      float windowWidth = app.getSize().x;
      float windowHeight = app.getSize().y;

      // Check to see if we resize and move the paddle and text
      if(abs(windowWidth - 100.0f - paddle2.getPosition().x) > 0.01f  ){
        paddle2.setPosition(windowWidth - 100.0f, paddle2.getPosition().y);
        displayScore.setPosition(windowWidth / 2.0f -  130.0f, 0); 
      }

      // Update the paddles
      paddle1View.move(paddle1, windowHeight, windowWidth, ball, deltaTime); 
      paddle2View.move(paddle2, windowHeight, windowWidth, ball, deltaTime); 
      ballView.move(ball, deltaTime);

      //Check if either player has won the round
      int win = ball.checkWin(windowWidth);
      if(win == 2){
        score2 += 1;
        resetRound(app, windowWidth, windowHeight, 400.0f);
      }
      else if(win == 1){
        score1 += 1;
        resetRound(app, windowWidth, windowHeight, 400.0f);
      }

      // Update the ball according to collisions
      ball.checkCollisionWall(windowHeight, true);
      ball.checkCollisionPaddle1(paddle1, true);
      ball.checkCollisionPaddle2(paddle2, true);

      // Resolve any lingering intersections using the new trajectory (velocity) of the ball
      while(ball.checkCollisionWall(windowHeight, false) | ball.checkCollisionPaddle1(paddle1, false) | ball.checkCollisionPaddle2(paddle2, false))
      {
          ball.move(deltaTime); //another option is to move ball immediately outside and then continue game
      }

      // clear screen and fill with blue
      app.clear(sf::Color::Red);

      app.draw(displayScore);
      paddle1View.draw(paddle1, app);
      paddle2View.draw(paddle2, app);
      ballView.draw(ball, app);

      // display
      app.display();
    }
    else{
      if(score1 == 11){
        resetGame(app, 1);
        
      }
      else if(score2 == 11){
        resetGame(app, 2);
        
      }
      else{
        resetGame(app, 0);
      }
    }
}