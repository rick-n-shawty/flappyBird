#include <SFML/Graphics.hpp> 
#include "Globals.hpp" 
#ifndef FLOOR_HPP
#define FLOOR_HPP

class Floor{
    public: 
        float x1,x2,y, velocity_x;
        int w,h; 
        Floor(){
            x1 = 0;
            x2 = WINDOW_WIDTH; 
            w = WINDOW_WIDTH; 
            h = GROUND_HEIGHT; 
            y = WINDOW_HEIGHT - GROUND_HEIGHT; 

            shape1.setSize(sf::Vector2f(w,h));
            shape1.setPosition(sf::Vector2f(x1,y));

            shape2.setSize(sf::Vector2f(w,h));
            shape2.setPosition(sf::Vector2f(x2,y));

            if(!texture.loadFromFile("../assets/images/grassBlock.png")){
                std::cout << "Grass block error \n";
            }
            texture.setRepeated(true); 
            shape1.setTexture(&texture);
            shape1.setTextureRect(sf::IntRect(x1,y, WINDOW_WIDTH, GROUND_HEIGHT));

            shape2.setTexture(&texture);
            shape2.setTextureRect(sf::IntRect(x2,y, WINDOW_WIDTH, GROUND_HEIGHT));

            velocity_x = -1;
        }
        ~Floor(){

        }
        void draw(sf::RenderWindow& window){
            window.draw(shape1);
            window.draw(shape2); 
        }
        void move(){
            x1 += velocity_x; 
            x2 += velocity_x;

            shape1.move(velocity_x,0);
            shape2.move(velocity_x,0);
        }
    private:
        sf::Texture texture; 
        sf::RectangleShape shape1;
        sf::RectangleShape shape2; 
};
#endif