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
    setName("Rod");}

Rod::Rod(std::string name, int durability, int efficiency) 
    : Tool(name, durability, efficiency)
{}

Rod::~Rod()
{}

//Methods
void Rod::Sharpen(Mineral &mineral)
{
    std::cout<<RED<<"-> "<<getName()<<" can't be sharpened!"<<std::endl;
}


#endif