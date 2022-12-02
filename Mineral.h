#ifndef MINERAL_H
#define MINERAL_H

#include"Resource.h"

class Mineral : public Resource
{
private:
    /* data */
public:
    Mineral();
    Mineral(std::string name, int durability);
    Mineral(Resource &mineral);
    ~Mineral();
    //Methods
    void makeAbstarct() override;
};

Mineral::Mineral() : Resource("Mineral", 100)
{}

Mineral::Mineral(std::string name, int durability) : Resource(name, durability)
{}

Mineral::Mineral(Resource &mineral) : Resource(mineral.getName(), mineral.getDurability()) {}

Mineral::~Mineral()
{}

//Methods
void Mineral::makeAbstarct()
{}

#endif