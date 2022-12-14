#ifndef TOOL_H
#define TOOL_H

#include"../colors.h"
#include"../resources/iron/Iron.h"

class Tool
{
private:
    std::string name;
    int durability;
    int efficiency;
    int hits;
public:
    //Construnctors and Destructors
    Tool();
    Tool(std::string name, int durability, int efficiency);
    virtual ~Tool();
    //Getters and Setters
    void setName(std::string name);
    void setDurability(int durability);
    void setEfficiency(int efficiency);
    void setHits(int hits);
    std::string getName();
    int getDurability();
    int getEfficiency();
    int getHits();
    //Methods
    virtual std::string className() const = 0;
    bool checkBroken(); //return true if broken
    //Output Methods
    void printData() const;
};

#endif