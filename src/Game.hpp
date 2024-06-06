#include <iostream>
#include <SFML/Graphics.hpp>
#include "Bird.hpp"
#include "Floor.hpp"

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
        void update(float& dt); 
        void render(); 
        sf::RenderWindow window; 
        sf::Clock clock;
        Bird bird;
        Floor floor;
};
#endif // GAME_H