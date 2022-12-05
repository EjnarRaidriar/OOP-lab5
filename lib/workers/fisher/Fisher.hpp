#ifndef FISHER_HPP
#define FISHER_HPP
#include"../Worker.hpp"
#include"../rod/Rod.hpp"
class Fisher : public Worker
{
private:
    std::vector<Rod> tools;

public:
    Fisher();
    Fisher(std::string name, int age, int cargo);
    virtual ~Fisher();
    //Getters
    virtual std::string className() const override;
    //Methods
    virtual void createTool() override;
};

#endif