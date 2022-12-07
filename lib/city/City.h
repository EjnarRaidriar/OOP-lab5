#ifndef CITY_H
#define CITY_H

#include<vector>
#include<memory>
#include"../resources/Resource.h"

class City
{
private:
    std::string name;
    int maxWorkers;
    std::vector<std::unique_ptr<Resource>> warehouse;
public:
    City();
    City(std::string name, int maxWorkers);
    virtual ~City();
    //Getters
    std::string getName();
    int getMaxWorkers();
    int getWoodAmount();
    int getIronAmount();
    int getFishAmount();
    //Setters
    void setName(std::string name);
    void setMaxWorkers(int maxWorkers);
    //Output Methods
    void printWarehouse();
    //Checkers
    bool hasIron();
    bool hasFish();
    bool hasWood();
    //Methods
    void addRsource(Resource* resource);
    Resource* getWood();
    Resource* getIron();
    Resource* getFish();
};

#endif