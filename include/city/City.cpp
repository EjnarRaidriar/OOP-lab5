#include"City.h"

City::City()
{
    name = "City";
    maxWorkers = 10;
}

City::City(std::string name, int maxWorkers)
{
    this->name = name;
    this->maxWorkers = maxWorkers;
}

City::~City()
{
}

//Getters
std::string City::getName()
{
    return name;
}

int City::getMaxWorkers()
{
    return maxWorkers;
}

int City::getWoodAmount()
{
    int count = 0;
    for (unsigned int i = 0; i < warehouse.size(); i++)
    {
        if (warehouse[i]->getName() == "Wood")
        {
            count++;
        }
    }
    return count;
}

int City::getIronAmount()
{
    int count = 0;
    for (unsigned int i = 0; i < warehouse.size(); i++)
    {
        if (warehouse[i]->getName() == "Iron")
        {
            count++;
        }
    }
    return count;
}

int City::getFishAmount()
{
    int count = 0;
    for (unsigned int i = 0; i < warehouse.size(); i++)
    {
        if (warehouse[i]->getName() == "Fish")
        {
            count++;
        }
    }
    return count;
}

void City::setName(std::string name)
{
    this->name = name;
}

void City::setMaxWorkers(int maxWorkers)
{
    this->maxWorkers = maxWorkers;
}

void City::printWarehouse()
{
    std::cout<<RESET<<"\t========Warehouse data========"<<std::endl;
    int resourceCount[3] = {0, 0, 0};
    for (unsigned int i = 0; i < warehouse.size(); i++)
    {
        if (warehouse[i]->getName() == "Wood")
        {
            resourceCount[0]++;
        }
        else if (warehouse[i]->getName() == "Iron")
        {
            resourceCount[1]++;
        }
        else if (warehouse[i]->getName() == "Fish")
        {
            resourceCount[2]++;
        }
    }
    std::cout<<"\t\tWood: "<<resourceCount[0]<<std::endl;
    std::cout<<"\t\tIron: "<<resourceCount[1]<<std::endl;
    std::cout<<"\t\tFish: "<<resourceCount[2]<<std::endl;
}

bool City::hasWood()
{
    for (unsigned int i = 0; i < warehouse.size(); i++)
    {
        if (warehouse[i]->getName() == "Wood")
        {
            return true;
        }
    }
    return false;
}

bool City::hasIron()
{
    for (unsigned int i = 0; i < warehouse.size(); i++)
    {
        if (warehouse[i]->getName() == "Iron")
        {
            return true;
        }
    }
    return false;
}

bool City::hasFish()
{
    for (unsigned int i = 0; i < warehouse.size(); i++)
    {
        if (warehouse[i]->getName() == "Fish")
        {
            return true;
        }
    }
    return false;
}

//Methods
void City::addRsource(Resource* resource)
{
    warehouse.push_back(std::unique_ptr<Resource>(resource));
}

Resource* City::getWood()
{
    for (unsigned int i = 0; i < warehouse.size(); i++)
    {
        if (warehouse[i]->getName() == "Wood")
        {
            return warehouse[i].get();
        }
    }
    return NULL;
}

Resource* City::getIron()
{
    for (unsigned int i = 0; i < warehouse.size(); i++)
    {
        if (warehouse[i]->getName() == "Iron")
        {
            return warehouse[i].get();
        }
    }
    return NULL;
}

Resource* City::getFish()
{
    for (unsigned int i = 0; i < warehouse.size(); i++)
    {
        if (warehouse[i]->getName() == "Fish")
        {
            return warehouse[i].get();
        }
    }
    return NULL;
}