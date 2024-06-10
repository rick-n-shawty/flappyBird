#include "Globals.hpp"
#include <SFML/Graphics.hpp>
#ifndef PIPE_HPP 
#define PIPE_HPP 
class Pipe{
    public: 
        bool isPassed;
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
            
            if(x + PIPE_WIDTH < 0){ // move pipe to the beginning
                x = WINDOW_WIDTH;
                isPassed = false;  
                downHeight = randomInt(70, WINDOW_HEIGHT - GROUND_HEIGHT - PIPE_GAP - 50);
                updateShapes();
            }
        }
    private: 
        sf::RectangleShape upperShape; 
        sf::RectangleShape bottomShape; 
        sf::Texture texture;
};
#endif