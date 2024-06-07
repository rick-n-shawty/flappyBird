#include "Globals.hpp"
#include <SFML/Graphics.hpp>
#ifndef PIPE_HPP 
#define PIPE_HPP 
class Pipe{
    // keep track of one x-var coz it is the same for both parts of the pipe
    // did not include upperPipeY coz it must always be zero 
    public: 
        float bottomPipeY, x;
        int upperHeight, bottomHeight; 
        Pipe(float x, int bottomHeight){
            this->bottomHeight = bottomHeight;
            this->x = x; 
            bottomPipeY = WINDOW_HEIGHT - GROUND_HEIGHT - bottomHeight; 


            bottomShape.setPosition(sf::Vector2f(x, bottomPipeY));
            bottomShape.setSize(sf::Vector2f(PIPE_WIDTH, bottomHeight));

            this->upperHeight =  WINDOW_HEIGHT - GROUND_HEIGHT - bottomHeight - PIPE_GAP;
            upperShape.setPosition(sf::Vector2f(x,0)); 
            upperShape.setSize(sf::Vector2f(PIPE_WIDTH, upperHeight));
            

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