#pragma once
#include <SFML/Graphics.hpp>
#include "Paddle.h"

class PaddleView
{
public:
    PaddleView(Paddle& paddle):paddle(paddle){}
    ~PaddleView(){}

    void draw(sf::RenderWindow& app);
protected:
    Paddle& paddle;
};