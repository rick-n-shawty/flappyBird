#include <iostream>
#include <SFML/Graphics.hpp>
#ifndef BIRD_HPP
#define BIRD_HPP 

class Bird{
    public:
        float x,y,velocity_y, velocity_x, fallingTime, jumpStrength; 
        int r; 
        Bird(float x, float y, int r){ 
            this->x = x;
            this->y = y;
            this->velocity_y = 0; 
            this->velocity_x = 0; 
            this->jumpStrength = -5;
            this->r = r;

            this->body.setPosition(sf::Vector2f(x,y));
            this->body.setRadius(r); 
            this->body.setOrigin(r, r);

            if(!this->texture.loadFromFile("../assets/images/flappy.png")){
                throw  std::runtime_error("Failed to load texture");
            };
            this->body.setTexture(&this->texture);
        };
        ~Bird(){

        };  
        sf::CircleShape getBody(){
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
            float currentRotation = this->body.getRotation();
            float dTheta = velocity_y / 2;
            if(currentRotation + dTheta <= 85 || currentRotation + dTheta >= 280){
                this->body.rotate(dTheta);
            }
        }
    private:
        sf::CircleShape body;
        sf::Texture texture;
};


#endif 