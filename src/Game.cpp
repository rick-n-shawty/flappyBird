#include <iostream>
#include "Game.hpp"
#include "Bird.hpp"
#include "Globals.hpp"
#include "Pipe.hpp"
using std::cout;


Game::Game() : floor(0, WINDOW_HEIGHT-GROUND_HEIGHT, WINDOW_WIDTH, GROUND_HEIGHT), pipe(400,400), bird(200,300,30){
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
                    if(!isGameOver){
                        bird.velocity_y = bird.jumpStrength;
                        bird.rotate();
                        bird.fallingTime = 0;
                    }
                break;
                default: 
                break;
            }
        }
    }

}

void Game::update(float& dt){
    if(isGameOver) return;


    if(bird.y + bird.r + 3 < WINDOW_HEIGHT - GROUND_HEIGHT){
        bird.fallingTime += dt;
        bird.velocity_y += GRAVITY * bird.fallingTime;
        bird.moveBody();
        bird.rotate(); 
    }
    pipe.velocity_x += -0.01; 
    pipe.moveBody();


    if(bird.collide(pipe)){
        cout << "Pipe collision!!! \n"; 
        isGameOver = true; 
    }
    // if(bird.collide(floor)){
    //     isGameOver = true; 
    // }


}
void Game::render(){
    window.clear(sf::Color(0,102,51)); 

    bird.draw(window);
    floor.draw(window);
    pipe.draw(window);
    drawText();

    window.display(); 
}