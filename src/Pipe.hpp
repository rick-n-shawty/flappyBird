#include "Globals.hpp"
#include <SFML/Graphics.hpp>
#ifndef PIPE_HPP 
#define PIPE_HPP 
class Pipe{
    // keep track of one x-var coz it is the same for both parts of the pipe
    // did not include upperPipeY coz it must always be zero 
    public: 

        float x, topY, downY;
        int topHeight, downHeight;
        Pipe(float x, int downHeight){
            this->x = x; 
            this->topY = topY; 
            this->downY = downY;
            this->downHeight = downHeight; 

            topY = 0; 
            downY = WINDOW_HEIGHT - GROUND_HEIGHT - downHeight; 


            topHeight = WINDOW_HEIGHT - GROUND_HEIGHT - downHeight - PIPE_GAP; 

            bottomShape.setPosition(sf::Vector2f(x, downY));
            bottomShape.setSize(sf::Vector2f(PIPE_WIDTH, downHeight));

            upperShape.setPosition(sf::Vector2f(x,topY)); 
            upperShape.setSize(sf::Vector2f(PIPE_WIDTH, topHeight));
            

            bottomShape.setFillColor(sf::Color::Red);
            upperShape.setFillColor(sf::Color::Red);

        }; 
        ~Pipe(){

        }; 

        void draw(sf::RenderWindow& window){
            window.draw(upperShape);
            window.draw(bottomShape);
        };
    private: 
        sf::RectangleShape upperShape; 
        sf::RectangleShape bottomShape; 
};
#endif