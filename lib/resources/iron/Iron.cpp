#include"Iron.h"

Iron::Iron() : Resource("Iron", 100) {}

Iron::Iron(std::string name, int durability) 
    : Resource(name, durability) {}
    
Iron::Iron(Resource &iron) 
    : Resource(iron.getName(), iron.getDurability()) {}

Iron::~Iron() {}

//Getters
std::string className()
{
    return "Iron";
}