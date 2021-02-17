#pragma once
#include <SFML/Graphics.hpp>
#include "Paddle.h"

class Ball
{
public:
    Ball(sf::Vector2f pos, sf::Vector2f vel, float rad);
    ~Ball();

    void setRandomVelocity(float speed);
    void addRandomPerturbation();
    sf::Color randomColor();
    bool checkCollisionPaddle1(Paddle& paddle, bool resolve);
    bool checkCollisionPaddle2(Paddle& paddle, bool resolve);
    bool checkCollisionWall(float windowHeight, bool resolve);
    int checkWin(float windowWidth);
    void move(float deltaTime);

    // bool checkCollision(Paddle& paddle);
    // void update(float deltaTime);
    // bool checkIntersections(Paddle& paddle, sf::RenderWindow& app);


    void setPosition(float x, float y){ position.x = x; position.y = y; };
    void setVelocity(float dx, float dy){ velocity.x = dx; velocity.y = dy; };
    void setRadius(float r){ radius = r; };
    void setColor(sf::Color c){ color = c; };
    sf::Vector2f getPosition() { return position; }
    sf::Vector2f getVelocity() { return velocity; }
    float getRadius() { return radius; }
    sf::Color getColor() { return color; }

private:
    sf::Vector2f position;
    sf::Vector2f velocity;
    float radius;
    sf::Color color;
};