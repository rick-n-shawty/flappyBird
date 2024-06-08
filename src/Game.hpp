#include <iostream>
#include <SFML/Graphics.hpp>
#include "Globals.hpp"
#include "Bird.hpp"
#include "Floor.hpp"
#include "Pipe.hpp"

#ifndef GAME_H
#define GAME_H
class Game{
    public: 
        Game(); 
        ~Game();
        void run(); 
        void drawText(){
            if(isGameOver){

            }else{
                window.draw(currentScoreText); 
            }
        }
        void drawPipes(){
            for(auto& pipe : pipes){
                pipe.draw(window);
            }
        }
    private:
        bool isGameOver;
        int bestScore;
        int currentScore;
        float GRAVITY;
        //
        void handleEvents(); 
        void update(float& dt); 
        void render();
        // 

        bool isCollisionOccurred();
        sf::RenderWindow window; 
        sf::Clock clock;
        sf::Font font;
        sf::Text currentScoreText; 
        sf::Text bestScoreText;
        sf::FloatRect textBounds;
        Pipe pipes[PIPE_NUMBER];
        Bird bird;
        Floor floor;
        //
};
#endif // GAME_H