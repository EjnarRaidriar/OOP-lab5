#ifndef FISH_HPP
#define FISH_HPP

#include"../Resource.hpp"

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