#ifndef AXE_H
#define AXE_H
#include"../Tool.h"
class Axe : public Tool
{
public:
    Axe();
    Axe(std::string name, int durability, int efficiency);
    virtual ~Axe();
    //Getters
    std::string className() const override;
};

#endif