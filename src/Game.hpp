#include <iostream>
#include <SFML/Graphics.hpp>
#include "Bird.hpp"
#include "Floor.hpp"

#ifndef GAME_H
#define GAME_H
class Game{
    public: 
        Game(); 
        ~Game();
        void run(); 
    private:
        bool isGameOver;
        int bestScore;
        int currentScore;
        float GRAVITY;
        //
        void handleEvents(); 
        void update(float& dt); 
        void render();
        bool loadFonts(){
            sf::Font font;
            return false;
        };
        // 
        sf::RenderWindow window; 
        sf::Clock clock;
        sf::Text currentScoreText; 
        sf::Text bestScoreText;

        Bird bird;
        Floor floor;
        //
};
#endif // GAME_H