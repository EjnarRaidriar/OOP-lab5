#include"Fisher.h"

Fisher::Fisher() : Worker()
{
    setName("Nameless Fisher");
    Tool* rod = new Rod("Rod", 5, 10);
    addTool(rod);
}

Fisher::Fisher(std::string name, int age, int cargo)
    : Worker(name, age, cargo) {}

Fisher::~Fisher() {}

//Getters
std::string Fisher::className() const
{
    return "Fisher";
}

//Methods
void Fisher::createTool()
{
    int w_index = -1;
    for (unsigned int i = 0; i < resources.size(); i++)
    {
        if (resources[i]->className() == "Wood")
        {
            w_index = i;
        }
    }
    if (w_index != -1)
    {
        Tool* rod = new Rod("Rod", 5, 10);
        addTool(rod);
        resources.erase(resources.begin() + w_index);
    }
    else if (w_index == -1)
    {
        std::cout<<RED<<"-> Not enough wood to create an axe"<<std::endl;
    }
}