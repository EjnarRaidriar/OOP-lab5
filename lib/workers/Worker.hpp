#ifndef WORKER_HPP
#define WORKER_HPP

#include"../resources/Resource.hpp"
#include"../tools/Tool.hpp"
#include<iostream>
#include<vector>
#include<typeinfo>

class Worker
{
private:
    std::string name;
    int age;
    unsigned int cargo;
    std::string location;
    std::vector<Tool*> tools;

protected:
    std::vector<Resource*> resources;

public:
    Worker();
    Worker(std::string name, int age, int cargo);
    virtual ~Worker();
    
    //Getters and Setters
    std::string getName();
    void setName(std::string name);
    int getAge();
    void setAge(int age);
    int getCargo();
    void setCargo(int cargo);
    std::string getLocation();
    void setLocation(std::string location);
    Resource* getResource();
    int getResourceAmount();
    void removeResource();
    Tool* getTool();
    void addTool(Tool* tool);
    int getToolAmount() const;
    virtual std::string className() const = 0;

    //Methods
    virtual bool collectResource(Resource* resource) = 0;
    void removeTool(int index);
    void Hit();

    //Output Methods
    void printResources() const;
    void printTools() const;
    void printData() const;
};

#endif