#include "Globals.hpp"
#include <iostream>

float getClosestPoint(float value, float min, float max){
    if(value > max) return max; 
    else if(value < min) return min; 
    return value;
}