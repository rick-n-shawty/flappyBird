
g++ -std=c++17 main.cpp Game.cpp -I/opt/homebrew/Cellar/sfml/2.6.1/include -o game  -L/opt/homebrew/Cellar/sfml/2.6.1/lib -lsfml-graphics -lsfml-window -lsfml-system



TODO: 
Floor is moving but there is a small gap.
Try to resolve it using update() func that accepts (dt)
