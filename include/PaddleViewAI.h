#pragma once
#include <SFML/Graphics.hpp>
#include "Ball.h"
#include "PaddleView.h"

class PaddleViewAI: public PaddleView
{
public:
    PaddleViewAI(Paddle& paddle):PaddleView(paddle){};
    ~PaddleViewAI(){};

    void move(float windowHeight, float windowWidth, Ball ball, float deltaTime);
private:    
    void AIFindY(float windowHeight, float windowWidth, Ball ball);
};