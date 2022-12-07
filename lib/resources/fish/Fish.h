#ifndef FISH_H
#define FISH_H

#include"../Resource.h"

class Fish : public Resource
{
public:
    Fish();
    Fish(std::string name, int durability);
    Fish(Resource &fish);
    virtual ~Fish();
    //Getters
    virtual std::string className() const override;
};

#endif