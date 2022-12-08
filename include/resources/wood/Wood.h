#ifndef WOOD_H
#define WOOD_H

#include"../Resource.h"

class Wood : public Resource
{
public:
    Wood();
    Wood(std::string name, int durability);
    virtual ~Wood();
    //Getters
    virtual std::string className() override;
};

#endif