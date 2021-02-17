#include "Ball.h"
#include <iostream>
#include <cmath>

/*
Private variables for reference:
sf::Vector2f position;
sf::Vector2f velocity;
float radius;
sf::Color color;

Balls know about their position, velocity, radius, and color.

They can also move at a random velocity at the start of a round, 
detect collisions when asked, and add random angle perturbations.

*/

/*
Constructors for the ball class
*/
Ball::Ball(sf::Vector2f pos, sf::Vector2f vel, float rad){
    this->position = pos;
    this->velocity = vel;
    this->radius = rad;
    this->color = randomColor();
} 
Ball::~Ball(){

}

/*
For each new round, we want to start the ball with a random velocity
*/
void Ball::setRandomVelocity(float speed){
    int range_min = 50;
    if(speed < range_min){
        speed += range_min;
    }
    int range_max = speed - range_min;
    int dx = rand() % range_max + range_min;
    int dy = sqrt(speed*speed - dx*dx);

    float positiveOrNegativeY = rand() % 2;

    velocity.x = dx;
    velocity.y = dy * pow(-1, positiveOrNegativeY);
}

/*
Allow the ball bounce off of a surface somewhat randomly
*/
void Ball::addRandomPerturbation(){
    // TODO: Only apply perterbation to the direction that changed

    // Randomize amount of perturbation
    float highestFloat = 5.0f;
    float xPerturbation = static_cast <float> (rand()) / (static_cast <float> (RAND_MAX/highestFloat));
    float yPerturbation = static_cast <float> (rand()) / (static_cast <float> (RAND_MAX/highestFloat));

    // Randomize sign of perturbation
    float positiveOrNegativeX = rand() % 2;
    float positiveOrNegativeY = rand() % 2;
    velocity.x += pow(-1, positiveOrNegativeX) * xPerturbation;
    velocity.y += pow(-1, positiveOrNegativeY) * yPerturbation;

}

/*
Change the ball to a new random color

Good for tracking when collisions happen
*/
sf::Color Ball::randomColor(){
    int r = rand() % 235 + 21; 
    int g = rand() % 235 + 21; 
    int b = rand() % 235 + 21; 
    return sf::Color(r, g, b);  
}

/*
Check for a collision with the wall
*/
bool Ball::checkCollisionWall(float windowHeight, bool resolve){
    if(position.y <= 0 || position.y + radius * 2.0f >= windowHeight){
        if(resolve == true){
            velocity.y = -velocity.y;

            // Allow our angle to be slightly different
            addRandomPerturbation();

            // Set the color of the ball to something random if there is a collision
            color = randomColor();
        }
        return true;
    }
    return false;
}

/*
Check for a collision with a side wall (i.e. a win)
*/
int Ball::checkWin(float windowWidth){
    if(position.x + radius * 2.0f <= 0){
        return 2;
    } 
    if(position.x - radius * 4.0f >= windowWidth){    
        return 1;
    }
    return 0;
}

/*
Update the ball's position given the time elapsed and current velocity of the ball
*/
void Ball::move(float deltaTime)
{
    position.x += velocity.x * deltaTime; // x = v * t
    position.y += velocity.y * deltaTime; // x = v * t
}

/*
Checks for (and can even resolve) collisions with paddle 1
*/
bool Ball::checkCollisionPaddle1(Paddle& paddle, bool resolve){
    sf::FloatRect paddleRect(paddle.getPosition().x, paddle.getPosition().y, paddle.getWidth(), paddle.getHeight());

    sf::Vector2f ballTopLeft = position;

    float ballTopRightX = position.x + radius * 2.0f;
    float ballTopRightY = position.y;
    sf::Vector2f ballTopRight(ballTopRightX, ballTopRightY);

    float ballBottomLeftX = position.x;
    float ballBottomLeftY = position.y + radius * 2.0f;
    sf::Vector2f ballBottomLeft(ballBottomLeftX, ballBottomLeftY);

    float ballBottomRightX = position.x + radius * 2.0f;
    float ballBottomRightY = position.y + radius * 2.0f;
    sf::Vector2f ballBottomRight(ballBottomRightX, ballBottomRightY);


    // If we intersect on the side of the paddle we want to change the x direction
    if(paddleRect.contains(ballTopLeft) && paddleRect.contains(ballBottomLeft) ){
        if(resolve == true){
            velocity.x = -velocity.x;

            // Allow our angle to be slightly different
            addRandomPerturbation();

            // Set the color of the ball to something random if there is a collision
            color = randomColor();
        }

        return true;
    }
    else if(paddleRect.contains(ballTopLeft) || paddleRect.contains(ballBottomLeft)){
        if(resolve == true){
            velocity.x = -velocity.x;
            velocity.y = -velocity.y;

            // Allow our angle to be slightly different
            addRandomPerturbation();

            // Set the color of the ball to something random if there is a collision
            color = randomColor();
        }

        return true;
    }

    return false;
}

/*
Checks for (and can even resolve) collisions with paddle 2
*/
bool Ball::checkCollisionPaddle2(Paddle& paddle, bool resolve){
    sf::FloatRect paddleRect(paddle.getPosition().x, paddle.getPosition().y, paddle.getWidth(), paddle.getHeight());

    sf::Vector2f ballTopLeft = position;

    float ballTopRightX = position.x + radius * 2.0f;
    float ballTopRightY = position.y;
    sf::Vector2f ballTopRight(ballTopRightX, ballTopRightY);

    float ballBottomLeftX = position.x;
    float ballBottomLeftY = position.y + radius * 2.0f;
    sf::Vector2f ballBottomLeft(ballBottomLeftX, ballBottomLeftY);

    float ballBottomRightX = position.x + radius * 2.0f;
    float ballBottomRightY = position.y + radius * 2.0f;
    sf::Vector2f ballBottomRight(ballBottomRightX, ballBottomRightY);


    // If we intersect on the side of the paddle we want to change the x direction
    if(paddleRect.contains(ballTopRight) && paddleRect.contains(ballBottomRight) ){
        if(resolve == true){
            velocity.x = -velocity.x;

            // Allow our angle to be slightly different
            addRandomPerturbation();

            // Set the color of the ball to something random if there is a collision
            color = randomColor();
        }

        return true;
    }
    else if(paddleRect.contains(ballTopRight) || paddleRect.contains(ballBottomRight)){
        if(resolve == true){
            velocity.x = -velocity.x;
            velocity.y = -velocity.y;

            // Allow our angle to be slightly different
            addRandomPerturbation();

            // Set the color of the ball to something random if there is a collision
            color = randomColor();
        }

        return true;
    }

    return false;
}



