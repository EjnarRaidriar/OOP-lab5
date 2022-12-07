#ifndef WORKER_HPP
#define WORKER_HPP

#include"../resources/Resource.hpp"
#include"../tools/Tool.hpp"
#include<iostream>
#include<vector>
#include<memory>

class Worker
{
private:
    std::string name;
    int age;
    unsigned int cargo;
    std::string location;

protected:
    std::vector<std::unique_ptr<Resource>> resources;
    std::vector<std::unique_ptr<Tool>> tools;

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
    void addResource(Resource* resource);
    int getResourceAmount();
    void removeResource();
    Tool* getTool(int index);
    void addTool(Tool* tool);
    int getToolAmount() const;
    virtual std::string className() const = 0;

    //Methods
    virtual void createTool() = 0;
    bool Hit(Resource* resource);
    bool collectResource(Resource* resource);
    void removeTool(int index);

    //Output Methods
    void printData() const;
    void printResources() const;
    void printTools() const;
};

#endif