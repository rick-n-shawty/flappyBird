#include <SFML/Graphics.hpp> 

#ifndef FLOOR_HPP
#define FLOOR_HPP

class Floor{
    public: 
        float x,y;
        int w,h; 
        Floor(float x, float y, int w, int h){
            this->w = w; 
            this->h = h;
            this->x = x;
            this->y = y; 
            shape.setFillColor(sf::Color(102,0,0));
            shape.setSize(sf::Vector2f(w,h));
            shape.setPosition(sf::Vector2f(x,y));
        }
        ~Floor(){

        }
        void draw(sf::RenderWindow& window){
            window.draw(shape);
        }
    private:
        sf::Sprite sprite1;
        sf::Sprite sprite2; 
        sf::Texture texture; 
        sf::RectangleShape shape;
};
#endif