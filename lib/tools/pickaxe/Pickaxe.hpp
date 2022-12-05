#ifndef PICKAXE_HPP
#define PICKAXE_HPP
#include"../Tool.hpp"
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