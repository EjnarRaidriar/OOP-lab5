#ifndef WOOD_H
#define WOOD_H

#include"../Resource.h"

class Wood : public Resource
{
public:
    Wood();
    Wood(std::string name, int durability);
    Wood(Resource &wood);
    virtual ~Wood();
    //Getters
    virtual std::string className() const override;
};

#endif