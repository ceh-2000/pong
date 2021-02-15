#include <SFML/Graphics.hpp>
#include <iostream>
#include "Paddle.h"
#include "Ball.h"
#include "Game.h"

int main(int argc, char** argv)
{
  // create main window
  sf::RenderWindow App(sf::VideoMode(800,600,32), "Pong", sf::Style::Titlebar | sf::Style::Close);//, sf::Style::Titlebar || sf::Style::Close);

  // Instantiate the paddle for the human to control
  Paddle paddleHuman(400.0f);

  // Instantiate the paddle for the AI to control
  Paddle paddleAI(400.0f);

  // Instantiate the ball that will bounce between the paddles
  Ball ball;

  // Instantiate a new game object that will track most game play
  Game game(paddleAI, paddleHuman, ball);
  game.resetRound(); 

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

    game.updateGame(App, deltaTime);
  }

  // Done.
  return 0;
}