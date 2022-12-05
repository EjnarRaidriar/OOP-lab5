#ifndef FORESTER_HPP
#define FORESTER_HPP
#include"../Worker.cpp"
#include"../axe/Axe.hpp"
#include"../wood/Wood.hpp"
#include"../IronToolUser.hpp"
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
    //Output Methods
    virtual void printData() override;
};

#endif