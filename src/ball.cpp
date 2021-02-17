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
    std::cout << std::to_string(velocity.x) << std::endl;
    std::cout << std::to_string(velocity.y) << std::endl;
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
    
    std::cout << std::to_string(velocity.x) << std::endl;
    std::cout << std::to_string(velocity.y) << std::endl;
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
bool Ball::checkCollisionWall(float windowHeight){
    if(position.y <= 0 || position.y + radius * 2.0f >= windowHeight){
        velocity.y = -velocity.y;

        std::cout << "Collide with wall" << std::endl;

        // Allow our angle to be slightly different
        addRandomPerturbation();

        // Set the color of the ball to something random if there is a collision
        randomColor();

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

// bool Ball::checkIntersections(Paddle& paddle, sf::RenderWindow& app){
//     sf::Vector2f ballPosition = getPosition();
//     sf::Vector2f ballHalfSize = getHalfSize();

//     if(ballPosition.y <= 0 || windowHeight + ballHalfSize.y * 2.0f >= windowHeight){
//         return true;
//     }

//     if(paddleBounds.intersects(ballBounds, intersection)){
//         return true;
//     }
//     return false;
// }


// bool Ball::checkCollision(Paddle& paddle){
//     sf::FloatRect paddleBounds = paddle.getGlobalBounds();
//     sf::FloatRect ballBounds = ball.getGlobalBounds();
//     sf::FloatRect intersection;

//     float ballWidth = ballBounds.width;
//     float ballHeight = ballBounds.height;

//     float paddleWidth = paddleBounds.width;
//     float paddleHeight = paddleBounds.height;

//     // If we intersect on the side of the paddle we want to change the x direction
//     if(paddleBounds.intersects(ballBounds, intersection)){

//         // If we intersect on the side of the paddle we want to change the x direction
//         // We know that the height of our intersection rectangle will match the height of 
//         // our ball if we have a hit on the side of the paddle
//         if(abs(ballHeight - intersection.height) < 0.01f){

//             dX = -dX;
//             std::cout << "Collide with side of paddle" << std::endl;

//         }
//         // If we intersect on the top or bottom of the paddle, we want to change the y direction
//         // If we intersect on the top/bottom and side of the paddle, we want to change both the x and y direction
//         else{
//             dX = -dX;
//             dY = -dY;

//             std::cout << "Collide with bottom of paddle" << std::endl;

//         }

//         // Allow our angle to be slightly different
//         addRandomPerturbation();

//         // Set the color of the ball to something random if there is a collision
//         changeColor();

//         // Notify the that we have a collision
//         return true;
//     }
//     // Notify the that we have no collision
//     return false;
// }


