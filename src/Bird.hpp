#include <iostream>
#include <SFML/Graphics.hpp>
#ifndef BIRD_HPP
#define BIRD_HPP 

class Bird{
    public:
        float x,y; 
        int w,h;
        Bird(float x, float y, int w, int h){ 
            this->x = x;
            this->y = y;
            this->w = w; 
            this->h = h; 
            this->body.setPosition(sf::Vector2f(x,y));
            this->body.setSize(sf::Vector2f(w,h)); 
            this->body.setFillColor(sf::Color::Red);
        };
        ~Bird(){

        };  
        void createBody(){

        }
        sf::RectangleShape getBody(){
            return this->body; 
        }
        void draw(sf::RenderWindow& window){
            // window.draw(this->body);
            window.draw(body);
        }
    private:
        sf::RectangleShape body; 
};


#endif 