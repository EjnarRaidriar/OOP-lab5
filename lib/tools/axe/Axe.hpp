#ifndef AXE_HPP
#define AXE_HPP
#include"../Tool.hpp"
class Axe : public Tool
{
public:
    Axe();
    Axe(std::string name, int durability, int efficiency);
    virtual ~Axe();
    //Getters
    std::string className() const override;
};

#endif