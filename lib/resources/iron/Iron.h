#ifndef IRON_H
#define IRON_H

#include"../Resource.h"

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