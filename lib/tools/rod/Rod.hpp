#ifndef ROD_HPP
#define ROD_HPP
#include"../Tool.hpp"
class Rod : public Tool
{
public:
    Rod();
    Rod(std::string name, int durability, int efficiency);
    virtual ~Rod();
    //Getters
    virtual std::string className() const override;
};

#endif