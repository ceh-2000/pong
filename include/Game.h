#pragma once
#include <SFML/Graphics.hpp>
#include "Ball.h"
#include "Paddle.h"

class Game
{
public:
    Game(Paddle& paddleAI, Paddle& paddleHuman, Ball& ball);
    ~Game();

    void resetGame();
    void resetRound();
    void AIFindY(float dX, float dY, sf::Vector2f pos);
    void updateGame(sf::RenderWindow& app, float deltaTime);


private:
    Paddle paddleAI;
    Paddle paddleHuman;
    Ball ball;
    float desiredY;
};