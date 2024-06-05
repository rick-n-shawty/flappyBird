#include "Game.hpp"
#include "Bird.hpp"
Game::Game(){
    sf::ContextSettings settings; 
    settings.antialiasingLevel = 10; 
    window.create(sf::VideoMode(1024,1024), "Flappy", sf::Style::Titlebar | sf::Style::Close, settings);
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
            std::cout << "Key pressed \n";
        }
    }

}
void Game::update(){

}
void Game::render(){
    window.clear(); 

    window.display(); 
}