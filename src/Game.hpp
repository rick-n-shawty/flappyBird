#include <iostream>
#include <SFML/Graphics.hpp>
#include "Bird.hpp"

#ifndef GAME_H
#define GAME_H
class Game{
    public: 
        int WINDOW_WIDTH;
        int WINDOW_HEIGHT;
        float GRAVITY;
        Game(); 
        ~Game();
        void run(); 

    private:
        void handleEvents(); 
        void update(); 
        void render(); 
        sf::RenderWindow window; 
        sf::Clock clock;
        sf::Time frameTime;
        Bird bird;
};
#endif // GAME_H