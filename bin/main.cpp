#include <SFML/Graphics.hpp>
#include <iostream>
#include "Paddle.h"
#include "Ball.h"
#include "Game.h"

int main(int argc, char** argv)
{
  // create main window
  sf::RenderWindow App(sf::VideoMode(800,600,32), "Pong", sf::Style::Titlebar | sf::Style::Close);//, sf::Style::Titlebar || sf::Style::Close);

  float initialVelocity = 400.0f;

  // Instantiate the paddle for the human to control
  Paddle paddleHuman(initialVelocity);

  // Instantiate the paddle for the AI to control
  Paddle paddleAI(initialVelocity);

  // Instantiate the ball that will bounce between the paddles
  Ball ball;

  // Instantiate the font we want to use for text
  sf::Font font;
  if (!font.loadFromFile("../data/Newsreader_18pt-Regular.ttf"))
  {
    std::cout << "Could not load font." << std::endl;
  }

  // Instantiate a new game object that will track most game play
  Game game(paddleAI, paddleHuman, ball, font);
  game.resetRound(App.getSize().x, App.getSize().y, initialVelocity); 

  // Set up variables that will allow us to get the elapsed time
  float deltaTime = 0.0f;
  sf::Clock clock;

    // // Let's add a texture to our paddle
    // sf::Texture texture;
    // if (!texture.loadFromFile("../data/dog.png"))
    // {
    //     std::cout << "No texture found." << std::endl;
    // }
    // sf::Sprite sprite;
    // sprite.setTexture(texture);


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