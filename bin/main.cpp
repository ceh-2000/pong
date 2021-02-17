#include <SFML/Graphics.hpp>
#include <iostream>
#include "Paddle.h"
#include "Ball.h"
#include "Game.h"
#include "PaddleView.h"
#include "BallView.h"

int main(int argc, char** argv)
{
  // Create main window
  sf::RenderWindow App(sf::VideoMode(800,600,32), "Covid-19 Pong", sf::Style::Titlebar | sf::Style::Close | sf::Style::Resize);

  float initialVelocity = 500.0f;
  float paddleDistanceFromEdge = 100.0f;
  float paddleWidth = 30.0f;
  float paddleHeight = 150.0f;
  float ballRadius = 20.0f;

  // Create the paddles and balls
  Paddle paddle1(sf::Vector2f(paddleDistanceFromEdge - paddleWidth, App.getSize().y / 2.0f - paddleHeight / 2.0f), initialVelocity, paddleWidth, paddleHeight);
  Paddle paddle2(sf::Vector2f(App.getSize().x - paddleDistanceFromEdge, App.getSize().y / 2.0f - paddleHeight / 2.0f), initialVelocity, paddleWidth, paddleHeight);
  Ball ball(sf::Vector2f(App.getSize().x / 2.0f - ballRadius, App.getSize().y / 2.0f - ballRadius), sf::Vector2f(150.0f, 0), ballRadius);
  PaddleView p1v(true);
  PaddleView p2v(false);
  BallView bv;

  // Instantiate a new game object that will track most game play
  Game game(paddle1, paddle2, ball, p1v, p2v, bv);

  // Set up variables that will allow us to get the elapsed time
  float deltaTime = 0.0f;
  sf::Clock clock;

  bool paused = false;

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
      // Catch the resize events
      if (Event.type == sf::Event::Resized)
      {
          // Update the view to the new size of the window
          sf::FloatRect visibleArea(0, 0, Event.size.width, Event.size.height);
          App.setView(sf::View(visibleArea));
      }
      // Pause and unpause the game
      if (Event.type == sf::Event::LostFocus){
        paused = true;
      }
      if (Event.type == sf::Event::GainedFocus){
        paused = false;
      }

    }

    if(paused == false){
      game.updateGame(App, deltaTime);
    }
  }

  // Done.
  return 0;
}