#include <iostream>
#include <SFML/Graphics.hpp>
#ifndef BIRD_HPP
#define BIRD_HPP 

class Bird{
    public:
        float x,y,velocity_y, velocity_x, fallingTime, jumpStrength; 
        int w,h;
        Bird(float x, float y, int w, int h){ 
            this->x = x;
            this->y = y;
            this->w = w; 
            this->h = h; 
            this->velocity_y = 0; 
            this->velocity_x = 0; 
            this->jumpStrength = -5;
            this->body.setPosition(sf::Vector2f(x,y));
            this->body.setSize(sf::Vector2f(w,h)); 
            this->body.setFillColor(sf::Color::Red);
            this->body.setOrigin(w / 2, h /2);
        };
        ~Bird(){

        };  
        sf::RectangleShape getBody(){
            return this->body; 
        }
        void draw(sf::RenderWindow& window){
            window.draw(this->body);
        }
        void moveBody(){
            this->x += velocity_x; 
            this->y += velocity_y;
            this->body.move(velocity_x, velocity_y);
        }
        void rotate(){
            this->body.rotate(25);
        }
    private:
        sf::RectangleShape body; 
};


#endif 