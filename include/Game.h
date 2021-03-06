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

    void resetGame(sf::RenderWindow& app, int winner);
    void updateGame(sf::RenderWindow& app, float deltaTime);
    void resetRound(sf::RenderWindow& app, float windowWidth, float windowHeight);

    // void resetGame();


private:
    Paddle paddle1;
    Paddle paddle2;
    Ball ball;

    PaddleView paddle1View;
    PaddleView paddle2View;  
    BallView ballView;  

    sf::Font font;
    sf::Texture backgroundTexture;
    int score1;
    int score2;
    sf::Text displayScore;

    int level;
    bool gameHappening;
};