#include"Axe.h"

Axe::Axe() : Tool()
{
    setName("Axe");
}

Axe::Axe(std::string name, int durability, int efficiency) 
    : Tool(name, durability, efficiency) {}

Axe::~Axe() {}

//Getters
std::string Axe::className() const
{
    return "Axe";
}