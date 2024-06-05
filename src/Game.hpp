#include <iostream>
#include <SFML/Graphics.hpp>
#include "Bird.hpp"

#ifndef GAME_H
#define GAME_H
class Game{
    public: 
        int WINDOW_WIDTH;
        int WINDOW_HEIGHT;
        Game(); 
        ~Game();
        void run(); 

    private:
        void handleEvents(); 
        void update(); 
        void render(); 
        sf::RenderWindow window; 
        Bird bird;
};
#endif // GAME_H