#ifndef FISHER_H
#define FISHER_H
#include"../Worker.h"
#include"../../tools/rod/Rod.h"
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