#pragma once 
#include "Globals.hpp"
#include <SFML/Graphics.hpp>
class Pipe{
    // keep track of one x-var coz it is the same for both parts of the pipe
    // did not include upperPipeY coz it must always be zero 
    float bottomPipeY, x;
    public: 
        Pipe(float x, int bottomHeight){
            this->x = x; 
            bottomPipeY = WINDOW_HEIGHT - GROUND_HEIGHT - bottomHeight; 


            bottomShape.setPosition(sf::Vector2f(x, bottomPipeY));
            bottomShape.setSize(PIPE_WIDTH, bottomHeight);

            upperShape.setPosition(sf::Vector2f(x,0)); 
            upperShape.setSize(PIPE_WIDTH, WINDOW_HEIGHT - GROUND_HEIGHT - bottomHeight - PIPE_GAP);
            

            bottomShape.setFillColor(sf::Color::Red);
            upperShape.setFillColor(sf::Color::Red);

        }; 
        ~Pipe(){

        }; 

        void draw(sf::RenderWindow& window){
            window.draw(upperShape);
            window.draw(bottomShape);
        }
    private: 
        sf::RectangleShape upperShape; 
        sf::RectangleShape bottomShape; 
}