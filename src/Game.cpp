#include <iostream>
#include "Game.hpp"
#include "Bird.hpp"
#include "Globals.hpp"
#include "Pipe.hpp"
using std::cout;


Game::Game() : floor(), bird(200,300,30){

    for(int i = 0; i < PIPE_NUMBER; i++){
        pipes[i] = Pipe(400 + (i * 400), randomInt(70,WINDOW_HEIGHT - GROUND_HEIGHT - PIPE_GAP - 50));   
    }

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

    bestScoreText.setFont(font);
    gameOverText.setFont(font);
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

void Game::restart(){
    for(int i = 0; i < PIPE_NUMBER; i++){
        pipes[i] = Pipe(400 + (i * 400), randomInt(70,WINDOW_HEIGHT - GROUND_HEIGHT - PIPE_GAP - 50));   
    }

    currentScore = 0; 
    currentScoreText.setString("0"); 
    isGameOver = false; 
    bird.reset(200,300);
}

bool Game::isCollisionOccurred(){
    if(bird.collide(floor)) return true;
    for(auto& pipe : pipes){
        if(bird.collide(pipe)) return true; 
    }
    return false;
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
                        bird.velocity_y = bird.y - bird.r > 0 ? bird.jumpStrength : 0; // prevents from going above pipes
                        bird.rotate();
                        bird.fallingTime = 0;
                    }else{
                        restart();
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


    if(bird.y + bird.r < WINDOW_HEIGHT - GROUND_HEIGHT){
        bird.fallingTime += dt;
        bird.velocity_y += GRAVITY * bird.fallingTime;
        bird.moveBody();
        bird.rotate(); 
    }
    for(auto& pipe : pipes){
        if(pipe.x < bird.x && !pipe.isPassed){
            incrementScore();
            pipe.isPassed = true;
        }
        pipe.move();
    }

    floor.move();

    // isGameOver = isCollisionOccurred();
}
void Game::render(){
    window.clear(sf::Color(255,249,240)); 

    bird.draw(window);
    floor.draw(window);
    drawPipes();
    drawText();

    window.display(); 
}