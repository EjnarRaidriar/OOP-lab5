#ifndef CITY_H
#define CITY_H

#include<vector>
#include<memory>
#include"./resources/Resource.hpp"

class City
{
private:
    std::string name;
    int maxWorkers;
public:
    std::vector<std::unique_ptr<Resource>> warehouse;
    City();
    City(std::string name, int maxWorkers);
    virtual ~City();
    //Getters
    std::string getName();
    int getMaxWorkers();
    //Setters
    void setName(std::string name);
    void setMaxWorkers(int maxWorkers);
    //Output Methods
    void printWarehouse();
    //Checkers
    bool hasMinerals();
    bool hasMinerals(int num);
    bool hasFish();
    bool hasFish(int num);
    bool hasWood();
    bool hasWood(int num);
    //Methods
    Resource* getWood();
    Resource* getMineral();
    Resource* getFish();
};

#endif