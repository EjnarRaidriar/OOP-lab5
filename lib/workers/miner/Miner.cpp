#include"Miner.h"

Miner::Miner() : Worker()
{
    setName("Nameless Miner");
}

Miner::Miner(std::string name, int age, int cargo)
    : Worker(name, age, cargo) {}

Miner::~Miner() {}

//Getters
std::string Miner::className() const
{
    return "Miner";
}

//Methods
void Miner::createTool()
{
    int w_index = -1;
    int i_index = -1;
    for (int i = 0; i < resources.size(); i++)
    {
        if (resources[i]->className() == "Iron")
        {
            i_index = i;
        }
        if (resources[i]->className() == "Wood")
        {
            w_index = i;
        }
    }
    if (i_index != -1 && w_index != -1)
    {
        Tool* pickaxe = new Pickaxe("Pickaxe", 5, 10);
        addTool(pickaxe);
        resources.erase(resources.begin() + i_index);
        resources.erase(resources.begin() + w_index);
    }
    else if (i_index == -1)
    {
        std::cout<<RED<<"-> Not enough iron to create an axe"<<std::endl;
    }
    else if (w_index == -1)
    {
        std::cout<<RED<<"-> Not enough wood to create an axe"<<std::endl;
    }
}

void Miner::Sharpen(Tool* tool)
{
    int iron = -1;
    for (int i = 0; i < resources.size(); i++)
    if (resources[i]->className() == "Iron")
        iron = i;
    if (iron != -1)
    {
        std::cout<<GREEN<<"-> "<<getName()<<" sharpened his "<<tool->getName()<<std::endl;
        tool->setEfficiency(10);
        resources.erase(resources.begin() + iron);
    }
}