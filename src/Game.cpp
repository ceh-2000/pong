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
  if (!backgroundTexture.loadFromFile("../data/faces.png"))
  {
    std::cout << "Could not load image from file." << std::endl;
  }

  displayScore.setFont(font); 

  this->gameHappening = false;
  this->level = 4;
}

Game::~Game(){}


void Game::resetGame(sf::RenderWindow& app, int winner){
  gameHappening = false;

  // Set the text on this screen
  displayScore.setCharacterSize(40); 
  displayScore.setPosition(0, 0); 
  sf::String myText = "Press Space Bar to start\n"
                      "or exit to quit.\n\n"
                      "Press up to set player 1 as AI.\n"
                      "Press down to set player 1 as human.\n"
                      "Press left to set player 2 as AI.\n"
                      "Press right to set player 2 as human.\n\n"
                      "Press a number between 1 and 9\n"
                      "to set difficulty\n";
  if(winner == 2){
    myText = "Player 2 Wins!\n"+myText;
  }
  else if(winner == 1){
    myText = "Player 1 Wins!\n"+myText;
  }
  else{
    myText = "Stop coronavirus\nby moving the mask up and down.\n\n"+myText;
  }
  displayScore.setString(myText);

  app.clear(sf::Color::Blue);

  displayScore.setFillColor(sf::Color::White); 
  app.draw(displayScore);

  app.display();


  // Keyboard inputs for user to select players, difficulty, and game start
  if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up)){
    paddle1View.setAI(true);
  }
  if(sf::Keyboard::isKeyPressed(sf::Keyboard::Down)){
    paddle1View.setAI(false);
  }
  if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left)){
    paddle2View.setAI(true);
  }
  if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right)){
    paddle2View.setAI(false);
  }

  if(sf::Keyboard::isKeyPressed(sf::Keyboard::Num1)){
    level = 1;
  }
  if(sf::Keyboard::isKeyPressed(sf::Keyboard::Num2)){
    level = 2;
  }
  if(sf::Keyboard::isKeyPressed(sf::Keyboard::Num3)){
    level = 3;
  }
  if(sf::Keyboard::isKeyPressed(sf::Keyboard::Num4)){
    level = 4;
  }
  if(sf::Keyboard::isKeyPressed(sf::Keyboard::Num5)){
    level = 5;
  }
  if(sf::Keyboard::isKeyPressed(sf::Keyboard::Num6)){
    level = 6;
  }
  if(sf::Keyboard::isKeyPressed(sf::Keyboard::Num7)){
    level = 7;
  }
  if(sf::Keyboard::isKeyPressed(sf::Keyboard::Num8)){
    level = 8;
  }
  if(sf::Keyboard::isKeyPressed(sf::Keyboard::Num9)){
    level = 9;
  }

  if(sf::Keyboard::isKeyPressed(sf::Keyboard::Space)){
    this->score1 = 0;
    this->score2 = 0;
    gameHappening = true;
    resetRound(app, app.getSize().x, app.getSize().y);
  }
}

void Game::resetRound(sf::RenderWindow& app, float windowWidth, float windowHeight){
  // Check for a game win
  if(score1 == 11){
    // Set to default players
    paddle1View.setAI(true);
    paddle2View.setAI(false);
    this->level = 4;
    resetGame(app, 1);    
  }
  else if(score2 == 11){
    // Set to default players
    paddle1View.setAI(true);
    paddle2View.setAI(false);
    this->level = 4;
    resetGame(app, 2);
  }

  // Update the text that shows the score
  displayScore.setString("Player 1: "+std::to_string(score1)+" | Player 2: "+std::to_string(score2));
  displayScore.setPosition(windowWidth / 2.0f -  130.0f, 0); 
  displayScore.setCharacterSize(30); 

  // Reposition the paddles and ball
  float paddleDistanceFromEdge = 100.0f;
  paddle1.setPosition(paddleDistanceFromEdge - paddle1.getWidth(), windowHeight / 2.0f - paddle1.getHeight() / 2.0f);
  paddle2.setPosition(windowWidth - paddleDistanceFromEdge, windowHeight / 2.0f - paddle2.getHeight() / 2.0f);
  ball.setPosition(windowWidth / 2.0f - ball.getRadius(), windowHeight / 2.0f - ball.getRadius());

  // Scale the ball's velocity based on how far the player has come
  float ballVelocity = level * 100 + score1 * 20 + score2 * 20;
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
        resetRound(app, windowWidth, windowHeight);
      }
      else if(win == 1){
        score1 += 1;
        resetRound(app, windowWidth, windowHeight);
      }

      // Update the ball according to collisions
      ball.checkCollisionWall(windowHeight, true);
      ball.checkCollisionPaddle1(paddle1, true);
      ball.checkCollisionPaddle2(paddle2, true);

      // Resolve any lingering intersections using the new trajectory (velocity) of the ball
      while(ball.checkCollisionWall(windowHeight, false) | ball.checkCollisionPaddle1(paddle1, false) | ball.checkCollisionPaddle2(paddle2, false))
      {
          ball.move(deltaTime); // another option is to move ball immediately outside and then continue game
      }

      // Clear screen and fill with white
      app.clear(sf::Color::White);

      sf::RectangleShape background(sf::Vector2f(windowWidth, windowHeight));
      const sf::Texture *pBackgroundTexture = &backgroundTexture;
      background.setTexture(pBackgroundTexture);
      app.draw(background);

      displayScore.setFillColor(sf::Color::Black); 
      app.draw(displayScore);

      paddle1View.draw(paddle1, app);
      paddle2View.draw(paddle2, app);
      ballView.draw(ball, app);

      // Display
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