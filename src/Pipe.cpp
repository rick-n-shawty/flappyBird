#include "Globals.hpp"
#include "Pipe.hpp"
#include <iostream> 



Pipe::Pipe(float x, int downHeight) : x(x), downHeight(downHeight){
    isPassed = false; 
    this->velocity_x = -1;
    topY = 0; 
    downY = WINDOW_HEIGHT - GROUND_HEIGHT - downHeight; 


    topHeight = WINDOW_HEIGHT - GROUND_HEIGHT - downHeight - PIPE_GAP; 

    bottomShape.setPosition(sf::Vector2f(x, downY));
    bottomShape.setSize(sf::Vector2f(PIPE_WIDTH, downHeight));

    upperShape.setPosition(sf::Vector2f(x,topY)); 
    upperShape.setSize(sf::Vector2f(PIPE_WIDTH, topHeight));
    

    bottomShape.setFillColor(sf::Color(115, 147, 179));
    upperShape.setFillColor(sf::Color(115, 147, 179));

    if(!texture.loadFromFile("../assets/images/pipeUp.png")){
        std::cout << "Failed to load texture \n"; 
    }
    texture.setRepeated(true);
    upperShape.setTexture(&texture); 
    upperShape.setTextureRect(sf::IntRect(x,topY, PIPE_WIDTH, topHeight));
}
Pipe::~Pipe(){

}