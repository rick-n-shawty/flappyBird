#include "Globals.hpp"
#include <SFML/Graphics.hpp>
#ifndef PIPE_HPP 
#define PIPE_HPP 
class Pipe{
    // keep track of one x-var coz it is the same for both parts of the pipe
    // did not include upperPipeY coz it must always be zero 
    public: 

        float x, topY, downY, velocity_x;
        int topHeight, downHeight;
        Pipe(float x=WINDOW_WIDTH, int downHeight=100);        
        ~Pipe(); 
        void updateShapes(){
            topHeight = WINDOW_HEIGHT - GROUND_HEIGHT - downHeight - PIPE_GAP; 
            downY = WINDOW_HEIGHT - GROUND_HEIGHT - downHeight;
            this->bottomShape.setPosition(sf::Vector2f(x,downY));
            this->bottomShape.setSize(sf::Vector2f(PIPE_WIDTH, downHeight));
            this->upperShape.setPosition(sf::Vector2f(x,topY));
            this->upperShape.setSize(sf::Vector2f(PIPE_WIDTH, topHeight));
        }
        void draw(sf::RenderWindow& window){
            window.draw(upperShape);
            window.draw(bottomShape);
        };
        void move(){
            this->upperShape.move(velocity_x,0);
            this->bottomShape.move(velocity_x, 0);
            this->x += velocity_x; 
            if(x + PIPE_WIDTH < -10){ // move pipe to the beginning
                x = WINDOW_WIDTH; 
                downHeight = randomInt(70,600);
                updateShapes();
            }
        }
    private: 
        sf::RectangleShape upperShape; 
        sf::RectangleShape bottomShape; 
};
#endif