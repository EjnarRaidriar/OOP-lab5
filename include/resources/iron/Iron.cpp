#include"Iron.h"

Iron::Iron() : Resource("Iron", 100) {}

Iron::Iron(std::string name, int durability) 
    : Resource(name, durability) {}

Iron::~Iron() {}

//Getters
std::string Iron::className()
{
    return "Iron";
}