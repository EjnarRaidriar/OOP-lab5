#ifndef FISHER_HPP
#define FISHER_HPP
#include"Worker.h"
#include"Rod.h"
#include"Fish.h"
#include<vector>
class Fisher : public Worker
{
private:
    std::vector<Rod> tools;

public:
    Fisher();
    Fisher(std::string name, int age, int cargo);
    virtual ~Fisher();
    //Getters
    int getToolAmount() const;
    //Methods
    bool collectResource(Resource* resource) override;
    void addTool(Rod &rod);
    void addNewTool();
    void removeTool(int index);
    //Output Methods
    void printResources() override;
    void printTools();
    void printData();
};

#endif