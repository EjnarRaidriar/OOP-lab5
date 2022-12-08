#include"Wood.h"

Wood::Wood() : Resource("Wood", 100) {}

Wood::Wood(std::string name, int durability) 
    : Resource(name, durability) {}
  
Wood::~Wood() {}

//Getters
std::string Wood::className()
{
    return "Wood";
}