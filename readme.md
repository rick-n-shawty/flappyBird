build command: g++ -std=c++17 main.cpp Game.cpp -I/opt/homebrew/Cellar/sfml/2.6.1/include -o game  -L/opt/homebrew/Cellar/sfml/2.6.1/lib -lsfml-graphics -lsfml-window -lsfml-system


g++ -std=c++17 main.cpp Game.cpp -I/opt/homebrew/Cellar/sfml/2.6.1/include -o game  -L/opt/homebrew/Cellar/sfml/2.6.1/lib -lsfml-graphics -lsfml-window -lsfml-system



TODO: 
1 - Work on pipes  
2 - Moving ground with two sprites 
3 - implement proper collision detection: Early Detection for mast moving objects, see if objects intersect in advance
