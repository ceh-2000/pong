#include <SFML/Graphics.hpp>
#include <iostream>
#include "Paddle.h"
#include "Ball.h"
#include "Game.h"

int main(int argc, char** argv)
{
  // Create main window
  sf::RenderWindow App(sf::VideoMode(800,600,32), "Pong", sf::Style::Titlebar | sf::Style::Close);

  float initialVelocity = 400.0f;
  float paddleDistanceFromEdge = 100.0f;
  float paddleWidth = 20.0f;
  float paddleHeight = 100.0f;
  float ballRadius = 20.0f;

  // Create the paddles and balls
  Paddle paddle1(sf::Vector2f(paddleDistanceFromEdge, App.getSize().y / 2.0f - paddleHeight / 2.0f), initialVelocity, paddleWidth, paddleHeight);
  Paddle paddle2(sf::Vector2f(App.getSize().x - paddleDistanceFromEdge, App.getSize().y / 2.0f - paddleHeight / 2.0f), initialVelocity, paddleWidth, paddleHeight);
  Ball ball(sf::Vector2f(App.getSize().x - ballRadius, App.getSize().y - ballRadius), sf::Vector2f(initialVelocity, 0), ballRadius);

  // Instantiate a new game object that will track most game play
  Game game(paddle1, paddle2, ball);

  game.setPlayers(true, false);

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

    // game.updateGame(App, deltaTime);
  }

  // Done.
  return 0;
}