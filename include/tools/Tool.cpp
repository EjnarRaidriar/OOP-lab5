#include"Tool.h"

//Construnctor and Destructors
Tool::Tool()
{
    name = "Tool";
    durability = 5;
    efficiency = 10;
    hits = 0;
}

Tool::Tool(std::string name, int durability, int efficiency)
{
    this->name = name;
    this->durability = durability;
    this->efficiency = efficiency;
    this->hits = 0;}

Tool::~Tool() {}

//Getters and Setters
void Tool::setName(std::string name)
{
    this->name = name;
}

void Tool::setDurability(int durability)
{
    this->durability = durability;
}

void Tool::setEfficiency(int efficiency)
{
    this->efficiency = efficiency;
}

void Tool::setHits(int hits)
{
    this->hits = hits;
}

std::string Tool::getName()
{
    return this->name;
}

int Tool::getDurability()
{
    return this->durability;
}

int Tool::getEfficiency()
{
    return this->efficiency;
}

int Tool::getHits()
{
    return this->hits;
}

//Methods
bool Tool::checkBroken()
{
    hits++;
    if (hits > durability)
    {
        efficiency--;
        hits = 0;
        return false;
    }
    if (efficiency <= 0)
    {
        durability--;
        return false;
    }
    if (durability <= 0)
    {
        return true;
    }
    return false;
}

//Output Methods
void Tool::printData() const
{
    std::cout<<RESET<<"   Tool name: "<<name<<std::endl;
    std::cout<<"   Tool durability: "<<durability<<std::endl;
    std::cout<<"   Tool efficiency: "<<efficiency<<std::endl;
    std::cout<<"   Tool's hit number: "<<hits<<std::endl;
}
