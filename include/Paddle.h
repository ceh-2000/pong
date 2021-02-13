#pragma once
#include <SFML/Graphics.hpp>

class Paddle
{
public:
    Paddle(float speed);
    ~Paddle();

    void setPosition(float x, float y);
    void update(float deltaTime, bool isUp);
    void draw(sf::RenderWindow& app);

private:
    sf::RectangleShape paddle;
    float speed;
};