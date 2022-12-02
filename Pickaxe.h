#ifndef PICKAXE_H
#define PICKAXE_H
#include"Tool.h"
class Pickaxe : public Tool
{
private:
    /* data */
public:
    Pickaxe();
    Pickaxe(std::string name, int durability, int efficiency);
    virtual ~Pickaxe();
    //Methods
    virtual void Sharpen(Mineral &mineral) override;
};

Pickaxe::Pickaxe() : Tool()
{
    setName("Pickaxe");
}

Pickaxe::Pickaxe(std::string name, int durability, int efficiency) 
    : Tool(name, durability, efficiency)
{}

Pickaxe::~Pickaxe()
{}

//Methods
void Pickaxe::Sharpen(Mineral &mineral)
{
    mineral.~Mineral();
    if (getEfficiency() < 10) {//change according to efficiency
            setEfficiency(getEfficiency() + 1);
            std::cout<<GREEN<<"-> "<<getName()<<" sharpened succesfully!"<<std::endl;
    } else {
        std::cout<<RED<<"-> "<<getName()<<" can't be sharpened anymore!"<<std::endl;
    }
}

#endif