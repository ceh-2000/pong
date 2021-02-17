#pragma once
#include <SFML/Graphics.hpp>
#include "Ball.h"

class BallView
{
public:
    BallView();
    ~BallView();

    void move(Ball& ball, float deltaTime);
    void draw(Ball& ball, sf::RenderWindow& app);
};