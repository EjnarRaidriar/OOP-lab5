#ifndef ROD_H
#define ROD_H
#include"../Tool.h"
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