#ifndef FORESTER_HPP
#define FORESTER_HPP
#include"Worker.h"
#include"Axe.h"
#include"Wood.h"
#include<vector>
class Forester : public Worker
{
private:
    std::vector<Axe> tools;

public:
    Forester();
    Forester(std::string name, int age, int cargo);
    virtual ~Forester();
    //Getters
    int getToolAmount() const;
    //Methods
    bool collectResource(Resource* resource) override;
    void addTool(Axe &axe);
    void addNewTool();
    void removeTool(int index);
    //Output Methods
    void printResources() override;
    void printTools();
    void printData();
};

#endif