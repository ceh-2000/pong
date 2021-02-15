#include <SFML/Graphics.hpp>
#include <iostream>
#include "Paddle.h"
#include "Ball.h"

void resetGame(Paddle& paddle1, Paddle& paddle2, Ball& ball){
  
}

void resetRound(Paddle& paddle1, Paddle& paddle2, Ball& ball){
  paddle1.setPosition(100.0f, 100.0f);
  paddle2.setPosition(700.0f, 100.0f);
  ball.setPosition(400.0f, 300.0f);
  ball.setVelocity(200.0f);
}

void updateGame(Paddle& paddle1, Paddle& paddle2, Ball& ball, sf::RenderWindow& app, float deltaTime){
    // Update the first paddle
    paddle1.update(deltaTime, false);

    // Draw the new position of our paddle given keyboard input
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up)){
      paddle2.update(deltaTime, true);
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Down)){
      paddle2.update(deltaTime, false);
    }

    // Update the ball
    ball.checkCollision(paddle1);
    ball.checkCollision(paddle2);
    ball.checkCollisionWall(app);
    int win = ball.checkWin(app);
    if(win == 0){
      ball.update(deltaTime);
    }
    else{
      resetRound(paddle1, paddle2, ball);
    }

    // clear screen and fill with blue
    app.clear(sf::Color(30,144,255));

    paddle1.draw(app);
    paddle2.draw(app);
    ball.draw(app);

    // display
    app.display();
}

int main(int argc, char** argv)
{
  // create main window
  sf::RenderWindow App(sf::VideoMode(800,600,32), "Pong", sf::Style::Titlebar | sf::Style::Close);//, sf::Style::Titlebar || sf::Style::Close);

  // Instantiate the paddle for the human to control
  Paddle paddleHuman(400.0f);
  paddleHuman.setPosition(700.0f, 300.0f);

  // Instantiate the paddle for the AI to control
  Paddle paddleAI(400.0f);
  paddleAI.setPosition(100.0f, 300.0f);

  // Instantiate the ball that will bounce between the paddles
  Ball ball;
  ball.setVelocity(300.0f);
  ball.setPosition(400.0f, 300.0f);

  // Set up variables that will allow us to get the elapsed time
  float deltaTime = 0.0f;
  sf::Clock clock;

  // start main loop
  while(App.isOpen())
  {
    // Get how much time has passed
    deltaTime = clock.restart().asSeconds();

    // process events
    sf::Event Event;
    while(App.pollEvent(Event))
    {
      // Exit
      if(Event.type == sf::Event::Closed){
        App.close();
      }
    }

    updateGame(paddleAI, paddleHuman, ball, App, deltaTime);
  }

  // Done.
  return 0;
}