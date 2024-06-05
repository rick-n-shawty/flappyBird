#include <iostream>
#include <SFML/Graphics.hpp>
#ifndef BIRD_HPP
#define BIRD_HPP 

class Bird{
    public:
        float x,y; 
        int w,h;
        Bird();
        ~Bird();  

        void draw(sf::RenderWindow& window){
            window.draw(this->body);
        }
    private:
        sf::RectangleShape body; 
};


#endif 