#pragma once
#include <SFML/Graphics.hpp>
#include "Paddle.h"

class Ball
{
public:
    Ball(float speed);
    ~Ball();

    void setPosition(float x, float y);
    void update(float deltaTime);
    void draw(sf::RenderWindow& app);
    bool checkCollision(Paddle& paddle, float reaction);
    sf::Vector2f getPosition() {return ball.getPosition();}
    sf::Vector2f getHalfSize() {return sf::Vector2f(ball.getRadius(), ball.getRadius()); }
    void move(float dx, float dy){ ball.move(dx, dy); }

private:
    sf::CircleShape ball;
    float speed;
};