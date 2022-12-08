#include"Fish.h"

Fish::Fish() : Resource("Fish", 100) {}

Fish::Fish(std::string name, int durability) 
    : Resource(name, durability) {}

Fish::~Fish() {}

//Getters
std::string Fish::className()
{
    return "Fish";
}
