#pragma once
#include <SFML/Graphics.hpp>
#include "Ball.h"
#include "PaddleView.h"

class PaddleViewHuman: public PaddleView
{
public:
    PaddleViewHuman(Paddle& paddle):PaddleView(paddle){};
    ~PaddleViewHuman(){};

    void move(float windowHeight, float windowWidth, Ball ball, float deltaTime);

};