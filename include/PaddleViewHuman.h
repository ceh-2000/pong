#pragma once
#include <SFML/Graphics.hpp>
#include "PaddleView.h"

class PaddleViewHuman: protected PaddleView
{
public:
    // PaddleViewHuman(Paddle& paddle);
    // ~PaddleViewHuman();

    void move(float windowHeight, float deltaTime);

};