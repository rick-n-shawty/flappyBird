#include <iostream>
#include <cmath>
#include <SFML/Graphics.hpp>
#include "Floor.hpp"
#include "Pipe.hpp"
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

            if(!this->texture.loadFromFile("../assets/images/birdSketch.png")){
                throw  std::runtime_error("Failed to load texture");
            };
            this->body.setTexture(&this->texture);
            // this->body.setOutlineThickness(1); 
            // this->body.setOutlineColor(sf::Color::White);
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
        bool collide(Floor& floor){
            return (y + r >= floor.y);
        }
        bool collide(Pipe& pipe){
            // upper pipe collisions 
            float closestX = getClosestPoint(x,pipe.x, pipe.x + PIPE_WIDTH);
            float closestY = getClosestPoint(y,pipe.topY, pipe.topY + pipe.topHeight); 
            float dist = pow(x-closestX,2) + pow(y-closestY,2);
            if(dist < r * r) return true; 
            // check bottom pipe
            closestY = getClosestPoint(y, pipe.downY, pipe.downY + pipe.downHeight); 
            dist = pow(x-closestX,2) + pow(y-closestY,2);
            if(dist < r * r) return true;
            return false;
        }
        void setXY(float x, float y){
            this->x = x; 
            this->y = y; 
            this->body.setPosition(sf::Vector2f(x,y));
        }
        void reset(float x, float y){
            this->x = x;
            this->y = y; 
            velocity_y = 0; 
            velocity_x = 0; 
            fallingTime = 0; 
            this->body.setRotation(0);
            this->body.setPosition(sf::Vector2f(x,y));
        }
    private:
        sf::CircleShape body;
        sf::Texture texture;
};


#endif 