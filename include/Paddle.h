#pragma once
#include <SFML/Graphics.hpp>

class Paddle
{
public:
    Paddle(sf::Vector2f position, float speed, float width, float height);
    ~Paddle();

    void up(float deltaTime);
    void down(float windowHeight, float deltaTime);

    void setPosition(float x, float y){ position.x = x; position.y = y; };
    void setSpeed(float s){ speed = s; };
    void setWidth(float w){ width = w; };
    void setHeight(float h){ height = h; };

    sf::Vector2f getPosition(){ return position; };
    float getSpeed(){ return speed; };
    float getWidth(){ return width; };
    float getHeight(){ return height; };

    // sf::Vector2f getHalfSize();
    // sf::FloatRect getGlobalBounds(){return paddle.getGlobalBounds();};

private:
    sf::Vector2f position;
    float speed;
    float width;
    float height;
};