#include "Globals.hpp"
#include <iostream>
#include <cmath> 
float getClosestPoint(float value, float min, float max){
    if(value > max) return max; 
    else if(value < min) return min; 
    return value;
}

int randomInt(int min, int max){
    return (rand() % max) + min;
}