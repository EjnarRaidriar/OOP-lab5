#ifndef FISH_H
#define FISH_H

#include"Resource.h"

class Fish : public Resource
{
private:
    /* data */
public:
    Fish();
    Fish(std::string name, int durability);
    Fish(Resource &fish);
    ~Fish();
    //Methods
    void makeAbstarct() override;
};

Fish::Fish() : Resource("Fish", 100)
{}

Fish::Fish(std::string name, int durability) : Resource(name, durability)
{}

Fish::Fish(Resource &fish) : Resource(fish.getName(), fish.getDurability()) {}

Fish::~Fish()
{}

//Methods
void Fish::makeAbstarct()
{}

#endif