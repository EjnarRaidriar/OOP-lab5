#ifndef FORESTER_H
#define FORESTER_H
#include"../Worker.h"
#include"../../tools/axe/Axe.h"
#include"../IronToolUser.h"
class Forester : public Worker, public IronToolUser
{
public:
    Forester();
    Forester(std::string name, int age, int cargo);
    virtual ~Forester();
    //Getters
    virtual std::string className() const override;
    //Methods
    virtual void createTool() override;
    virtual void Sharpen(Tool* tool) override; //needs to have iron to work
};

#endif