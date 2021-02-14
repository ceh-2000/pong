#include <SFML/Graphics.hpp>
#include <iostream>
#include "Paddle.h"
#include "Ball.h"

int main(int argc, char** argv)
{
  // create main window
  sf::RenderWindow App(sf::VideoMode(800,600,32), "Pong", sf::Style::Titlebar || sf::Style::Close);

  // Instantiate the paddle for the human to control
  Paddle paddleHuman(200.0f);
  paddleHuman.setPosition(700.0f, 100.0f);

  // Instantiate the paddle for the AI to control
  Paddle paddleAI(200.0f);
  paddleAI.setPosition(100.0f, 100.0f);

  // Instantiate the ball that will bounce between the paddles
  Ball ball(100.0f);
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
        std::cout << "Hello there" << std::endl;
      }
    }

    // Draw the new position of our paddle given keyboard input
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up)){
      paddleHuman.update(deltaTime, true);
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Down)){
      paddleHuman.update(deltaTime, false);
    }

    paddleAI.update(deltaTime, false);
    ball.update(deltaTime);

    // clear screen and fill with blue
    App.clear(sf::Color(30,144,255));

    paddleHuman.draw(App);
    paddleAI.draw(App);
    ball.draw(App);

    // display
    App.display();
  }

  // Done.
  return 0;
}
