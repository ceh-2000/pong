#pragma once
#include <SFML/Graphics.hpp>
#include "Ball.h"
#include "Paddle.h"

class PaddleView
{
public:
    PaddleView(bool isAI);
    ~PaddleView();

    void move(Paddle& paddle, float windowHeight, float windowWidth, Ball ball, float deltaTime);
    void moveAI(Paddle& paddle, float windowHeight, float windowWidth, Ball ball, float deltaTime);
    void moveHuman(Paddle& paddle, float windowHeight, float windowWidth, Ball ball, float deltaTime);
    void draw(Paddle& paddle, sf::RenderWindow& app);
    
private:
    bool isAI;
    float AIFindY(Paddle& paddle, float windowHeight, float windowWidth, Ball ball);
};