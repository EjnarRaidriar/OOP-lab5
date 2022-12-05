#include"Rod.hpp"

Rod::Rod() : Tool()
{
    setName("Rod");}

Rod::Rod(std::string name, int durability, int efficiency) 
    : Tool(name, durability, efficiency) {}

Rod::~Rod() {}

//Getters
std::string Rod::className() const
{
    return "Rod";
}
