#ifndef PICKAXE_H
#define PICKAXE_H
#include"../Tool.h"
class Pickaxe : public Tool
{
public:
    Pickaxe();
    Pickaxe(std::string name, int durability, int efficiency);
    virtual ~Pickaxe();
    //Getters
    virtual std::string className() const override;
};

#endif