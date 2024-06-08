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
                std::string s = "Best score: "; 
                s.append(std::to_string(bestScore));
                bestScoreText.setString(s);
                bestScoreText.setCharacterSize(40);
                textBounds = bestScoreText.getLocalBounds(); 
                bestScoreText.setOrigin((textBounds.left + textBounds.width) / 2.0f, textBounds.top + textBounds.height / 2.0f);
                bestScoreText.setPosition(sf::Vector2f(WINDOW_WIDTH / 2, 300));
                window.draw(bestScoreText);
            }else{
                window.draw(currentScoreText); 
            }
        }
        void drawPipes(){
            for(auto& pipe : pipes){
                pipe.draw(window);
            }
        }
        void incrementScore(){
            currentScore++; 
            currentScoreText.setString( std::to_string(currentScore));
            if(currentScore > bestScore){
                bestScore = currentScore;
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
        void restart();
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