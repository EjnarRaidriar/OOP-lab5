#ifndef MINER_HPP
#define MINER_HPP
#include"../workers/Worker.hpp"
#include"../pickaxe/Pickaxe.hpp"
#include"../resources/iron/Iron.hpp"
#include"../IronToolUser.hpp"
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
    //Output Methods
    virtual void printData() override;
};

#endif