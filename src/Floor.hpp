#include <SFML/Graphics.hpp> 

#ifndef FLOOR_HPP
#define FLOOR_HPP

class Floor{
    int h,w; 
    public: 
        Floor(int w, int h){
            this->w = w; 
            this->h = h;
        }
        ~Floor(){

        }

        void draw(sf::RenderWindow& window){

        }
    private:
}
#endif