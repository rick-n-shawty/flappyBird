#include "Globals.hpp"
#include "Pipe.hpp"
#include <iostream> 

Pipe::Pipe(float x, int downHeight) : x(x), downHeight(downHeight){

    this->velocity_x = -1;
    topY = 0; 
    downY = WINDOW_HEIGHT - GROUND_HEIGHT - downHeight; 


    topHeight = WINDOW_HEIGHT - GROUND_HEIGHT - downHeight - PIPE_GAP; 

    bottomShape.setPosition(sf::Vector2f(x, downY));
    bottomShape.setSize(sf::Vector2f(PIPE_WIDTH, downHeight));

    upperShape.setPosition(sf::Vector2f(x,topY)); 
    upperShape.setSize(sf::Vector2f(PIPE_WIDTH, topHeight));
    

    bottomShape.setFillColor(sf::Color::Red);
    upperShape.setFillColor(sf::Color::Red);

}
Pipe::~Pipe(){

}