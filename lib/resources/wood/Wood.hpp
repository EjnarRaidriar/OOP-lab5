#ifndef WOOD_HPP
#define WOOD_HPP

#include"../Resource.hpp"

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