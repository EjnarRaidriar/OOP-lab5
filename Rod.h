#ifndef ROD_H
#define ROD_H
#include"Tool.h"
class Rod : public Tool
{
private:
    /* data */
public:
    Rod();
    Rod(std::string name, int durability, int efficiency);
    virtual ~Rod();
    //Methods
    virtual void Sharpen(Mineral &mineral) override;
};

Rod::Rod() : Tool()
{
    setName("Rod");
    std::cout<<MAGENTA<<"-> Rod default constructor called!"<<std::endl;
}

Rod::Rod(std::string name, int durability, int efficiency) 
    : Tool(name, durability, efficiency)
{
    std::cout<<MAGENTA<<"-> Rod custom constructor called!"<<std::endl;
}

Rod::~Rod()
{
    std::cout<<MAGENTA<<"-> Rod destructor called!"<<std::endl;
}

//Methods
void Rod::Sharpen(Mineral &mineral)
{
    std::cout<<RED<<"-> "<<getName()<<" can't be sharpened!"<<std::endl;
}


#endif