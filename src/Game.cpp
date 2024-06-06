#include <iostream>
#include "Game.hpp"
#include "Bird.hpp"
using std::cout;



Game::Game() : bird(200,300,100,100){
    sf::ContextSettings settings; 
    settings.antialiasingLevel = 10; 
    GRAVITY = 0.6;

    window.create(sf::VideoMode(1128,700), "Flappy", sf::Style::Titlebar | sf::Style::Close, settings);
    window.setFramerateLimit(60);
}; 

Game::~Game() {
    // Any necessary cleanup
}

void Game::run(){
    while(window.isOpen()){
        handleEvents(); 
        update(); 
        render();
    }
}

void Game::handleEvents(){
    sf::Event event; 
    while(window.pollEvent(event)){
        if(event.type == sf::Event::Closed){
            window.close(); 
        }
        if(event.type == sf::Event::KeyPressed){
            switch (event.key.code){
                case sf::Keyboard::Space: 
                    //jump
                    bird.velocity_y = bird.jumpStrength;
                    bird.rotate();
                    bird.fallingTime = 0;
                break;
                default: 
                break;
            }
        }
    }

}
void Game::update(){
    frameTime = clock.restart();
    float dt = frameTime.asSeconds();
    bird.fallingTime += dt;
    bird.velocity_y += GRAVITY * bird.fallingTime;
    bird.moveBody();
}
void Game::render(){
    window.clear(); 
    bird.draw(window);
    window.display(); 
}