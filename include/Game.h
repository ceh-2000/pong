#pragma once
#include <SFML/Graphics.hpp>
#include "Paddle.h"
#include "PaddleView.h"
#include "BallView.h"
#include "Ball.h"

class Game
{
public:
    Game(Paddle& paddle1, Paddle& paddle2, Ball& ball, PaddleView& paddle1View, PaddleView& paddle2View, BallView& ballView);
    ~Game();

    void updateGame(sf::RenderWindow& app, float deltaTime);
    void resetRound(float windowWidth, float windowHeight, float velocity);

    // void resetGame();


private:
    Paddle paddle1;
    Paddle paddle2;
    Ball ball;

    PaddleView paddle1View;
    PaddleView paddle2View;  
    BallView ballView;  

    sf::Font font;
    int score1;
    int score2;
    sf::Text displayScore;
};