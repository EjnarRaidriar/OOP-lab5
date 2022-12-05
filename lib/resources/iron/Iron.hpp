#ifndef IRON_HPP
#define IRON_HPP

#include"../Resource.hpp"

class Iron : public Resource
{
public:
    Iron();
    Iron(std::string name, int durability);
    Iron(Resource &iron);
    virtual ~Iron();
    //Getters
    virtual std::string className() const override;
};

#endif