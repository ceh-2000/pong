#pragma once
#include <SFML/Graphics.hpp>
#include "Ball.h"
#include "Paddle.h"

class Game
{
public:
    Game(Paddle& paddleAI, Paddle& paddleHuman, Ball& ball, sf::Font& font);
    ~Game();

    void resetGame();
    void resetRound(float windowWidth, float windowHeight, float velocity);
    void AIFindY(float windowHeight);
    void updateGame(sf::RenderWindow& app, float deltaTime);


private:
    Paddle paddleAI;
    Paddle paddleHuman;
    Ball ball;
    sf::Text displayScore;
    sf::Font font;
    float desiredY;
    int score1;
    int score2;
};