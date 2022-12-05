#include"Fish.hpp"

Fish::Fish() : Resource("Fish", 100) {}

Fish::Fish(std::string name, int durability) 
    : Resource(name, durability) {}

Fish::Fish(Resource &fish) 
    : Resource(fish.getName(), fish.getDurability()) {}

Fish::~Fish() {}

//Getters
std::string className()
{
    return "Fish";
}
