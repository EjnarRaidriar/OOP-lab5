#include"Resource.h"

Resource::Resource(std::string name, int durability)
{
    this->name = name;
    this->durability = durability;
}

Resource::Resource() {}

Resource::~Resource() {}

//Getters and Setters
void Resource::setName(std::string name)
{
    this->name = name;
}

void Resource::setDurability(int durability)
{
    this->durability = durability;
}

int Resource::getDurability()
{
    return this->durability;
}

std::string Resource::getName()
{
    return this->name;
}