#ifndef MINER_H
#define MINER_H
#include"../Worker.h"
#include"../../tools/pickaxe/Pickaxe.h"
#include"../IronToolUser.h"
class Miner : public Worker, public IronToolUser
{
public:
    Miner();
    Miner(std::string name, int age, int cargo);
    virtual ~Miner();
    //Getters
    virtual std::string className() const override;
    //Methods
    virtual void createTool() override;
    virtual void Sharpen(Tool* tool) override; //needs to have iron to work
};

#endif