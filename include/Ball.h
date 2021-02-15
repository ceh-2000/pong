#pragma once
#include <SFML/Graphics.hpp>
#include "Paddle.h"

class Ball
{
public:
    Ball();
    ~Ball();

    void setPosition(float x, float y);
    void setVelocity(float speed);
    void addRandomPerturbation();
    void update(float deltaTime);
    void draw(sf::RenderWindow& app);
    bool checkIntersections(Paddle& paddle, sf::RenderWindow& app);
    bool checkCollision(Paddle& paddle);
    bool checkCollisionWall(sf::RenderWindow& app);
    int checkWin(sf::RenderWindow& app);
    void changeColor();

    sf::Vector2f getPosition() {return ball.getPosition();}
    sf::Vector2f getHalfSize() {return sf::Vector2f(ball.getRadius(), ball.getRadius()); }
    float getdX() { return dX; }
    float getdY() { return dY; }
    
private:
    // sf::Vector2f speed(0.0f, 0.0f);
    float dX;
    float dY;
    sf::CircleShape ball;
};