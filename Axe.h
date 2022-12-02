#ifndef AXE_H
#define AXE_H
#include"Tool.h"
class Axe : public Tool
{
private:
    /* data */
public:
    Axe();
    Axe(std::string name, int durability, int efficiency);
    virtual ~Axe();
    //Methods
    virtual void Sharpen(Mineral &mineral) override;
};

Axe::Axe() : Tool()
{
    setName("Axe");
    std::cout<<MAGENTA<<"-> Axe default constructor called!"<<std::endl;
}

Axe::Axe(std::string name, int durability, int efficiency) 
    : Tool(name, durability, efficiency)
{
    std::cout<<MAGENTA<<"-> Axe custom constructor called!"<<std::endl;
}

Axe::~Axe()
{
    std::cout<<MAGENTA<<"-> Axe destructor called!"<<std::endl;
}

//Methods
void Axe::Sharpen(Mineral &mineral)
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