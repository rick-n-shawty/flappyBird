#include <iostream>
#include "Game.hpp"
#include "Bird.hpp"
using std::cout;
const int WINDOW_WIDTH = 1280; 
const int WINDOW_HEIGHT = 768;

Game::Game() : bird(200,300,30), floor(0, 768-100, 1280, 100){
    sf::ContextSettings settings; 
    settings.antialiasingLevel = 10; 
    GRAVITY = 0.6;
    isGameOver = false; 
    currentScore = 0;
    bestScore = 0;

    window.create(sf::VideoMode(WINDOW_WIDTH,WINDOW_HEIGHT), "Flappy", sf::Style::Titlebar | sf::Style::Close, settings);
    window.setFramerateLimit(60);

    if(!font.loadFromFile("../assets/fonts/PixelifySans-Regular.ttf")){
        cout << "Failed to load fonts \n"; 
        exit(1);
    }
    currentScoreText.setFont(font);
    currentScoreText.setCharacterSize(50);
    currentScoreText.setString(std::to_string(currentScore));
    textBounds = currentScoreText.getLocalBounds(); 
    currentScoreText.setOrigin(textBounds.left + textBounds.width / 2.0f, textBounds.top + textBounds.height / 2.0f);
    currentScoreText.setPosition(WINDOW_WIDTH / 2.0f, 100);

}; 

Game::~Game() {
    // Any necessary cleanup
}

void Game::run(){
  
    while(window.isOpen()){
        float dt = clock.restart().asSeconds(); 
        handleEvents(); 
        update(dt); 
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
                case sf::Keyboard::Space:  // handle jumping of the bird 
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
void Game::update(float& dt){
    bird.fallingTime += dt;
    bird.velocity_y += GRAVITY * bird.fallingTime;
    bird.moveBody();
    bird.rotate();
}
void Game::render(){
    window.clear(sf::Color(0,102,51)); 

    bird.draw(window);
    floor.draw(window);
    showText();

    window.display(); 
}