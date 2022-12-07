#include"Pickaxe.h"

Pickaxe::Pickaxe() : Tool()
{
    setName("Pickaxe");
}

Pickaxe::Pickaxe(std::string name, int durability, int efficiency) 
    : Tool(name, durability, efficiency) {}

Pickaxe::~Pickaxe() {}

//Getters
std::string Pickaxe::className() const
{
    return "Pickaxe";
}