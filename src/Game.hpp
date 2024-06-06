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
        // 
        sf::RenderWindow window; 
        sf::Clock clock;
        Bird bird;
        Floor floor;
        //
        sf::Text currentScoreText; 
        sf::Text bestScoreText;
};
#endif // GAME_H