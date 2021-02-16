#pragma once
#include <SFML/Graphics.hpp>
#include "Paddle.h"
#include "PaddleViewAI.h"
#include "PaddleViewHuman.h"
#include "Ball.h"
#include "Game.h"

class Game
{
public:
    Game(Paddle& paddle1, Paddle& paddle2, Ball& ball);
    ~Game();

    void setPlayers(bool isPlayer1AI, bool isPlayer2AI);
    // void resetGame();
    // void resetRound(float windowWidth, float windowHeight, float velocity);
    // void updateGame(sf::RenderWindow& app, float deltaTime);


private:
    Paddle paddle1;
    Paddle paddle2;
    Ball ball;

    PaddleView *player1;
    PaddleView *player2;

    sf::Font font;
    int score1;
    int score2;
    sf::Text displayScore;
};