#ifndef RESOURCE_HPP
#define RESOURCE_HPP

#include<iostream>
#include<string>
#include"../colors.h"
class Resource
{
private:
    std::string name;
    int durability;
public:
    //Construncotrs and Destructors
    Resource();
    Resource(std::string name, int durability);
    virtual ~Resource();
    //Getters and Setters
    void setName(std::string name);
    void setDurability(int durability);
    std::string getName();
    int getDurability();
    virtual std::string className() const = 0;
};


#endif