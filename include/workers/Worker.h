#ifndef WORKER_H
#define WORKER_H

#include"../resources/Resource.h"
#include"../tools/Tool.h"

class Worker
{
private:
    std::string name;
    int age;
    unsigned int cargo;
    std::string location;

protected:
    std::vector<Resource*> resources;
    std::vector<std::unique_ptr<Tool>> tools;

public:
    Worker();
    Worker(std::string name, int age, int cargo);
    virtual ~Worker();
    //deleted constructors
    Worker(const Worker&) = delete;
    Worker& operator=(const Worker&) = delete;
    
    //Getters and Setters
    std::string getName();
    void setName(std::string name);
    int getAge();
    void setAge(int age);
    unsigned int getCargo();
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