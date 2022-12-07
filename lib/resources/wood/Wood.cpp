#include"Wood.h"

Wood::Wood() : Resource("Wood", 100) {}

Wood::Wood(std::string name, int durability) 
    : Resource(name, durability) {}

Wood::Wood(Resource &wood) 
    : Resource(wood.getName(), wood.getDurability()) {}
    
Wood::~Wood() {}

//Getters
std::string className()
{
    return "Wood";
}