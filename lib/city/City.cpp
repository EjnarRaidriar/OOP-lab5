#include"City.hpp"

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

std::string City::getName()
{
    return name;
}

int City::getMaxWorkers()
{
    return maxWorkers;
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
    std::cout<<RESET<<"Warehouse data:"<<std::endl;
    int resourceCount[3] = {0, 0, 0};
    for (int i = 0; i < warehouse.size(); i++)
    {
        if (warehouse[i]->getName() == "Wood")
        {
            resourceCount[0]++;
        }
        else if (warehouse[i]->getName() == "Mineral")
        {
            resourceCount[1]++;
        }
        else if (warehouse[i]->getName() == "Fish")
        {
            resourceCount[2]++;
        }
    }
    std::cout<<"      Wood: "<<resourceCount[0]<<std::endl;
    std::cout<<"   Mineral: "<<resourceCount[1]<<std::endl;
    std::cout<<"      Fish: "<<resourceCount[2]<<std::endl;
}

bool City::hasWood()
{
    for (int i = 0; i < warehouse.size(); i++)
    {
        if (warehouse[i]->getName() == "Wood")
        {
            return true;
        }
    }
    return false;
}

bool City::hasWood(int num)
{
    int count = 0;
    for (int i = 0; i < warehouse.size(); i++)
    {
        if (warehouse[i]->getName() == "Wood")
        {
            count++;
        }
    }
    if (count >= num)
    {
        return true;
    }
    return false;
}

bool City::hasMinerals()
{
    for (int i = 0; i < warehouse.size(); i++)
    {
        if (warehouse[i]->getName() == "Mineral")
        {
            return true;
        }
    }
    return false;
}

bool City::hasMinerals(int num)
{
    int count = 0;
    for (int i = 0; i < warehouse.size(); i++)
    {
        if (warehouse[i]->getName() == "Mineral")
        {
            count++;
        }
    }
    if (count >= num)
    {
        return true;
    }
    return false;
}

bool City::hasFish()
{
    for (int i = 0; i < warehouse.size(); i++)
    {
        if (warehouse[i]->getName() == "Fish")
        {
            return true;
        }
    }
    return false;
}

bool City::hasFish(int num)
{
    int count = 0;
    for (int i = 0; i < warehouse.size(); i++)
    {
        if (warehouse[i]->getName() == "Fish")
        {
            count++;
        }
    }
    if (count >= num)
    {
        return true;
    }
    return false;
}

Resource* City::getWood()
{
    for (int i = 0; i < warehouse.size(); i++)
    {
        if (warehouse[i]->getName() == "Wood")
        {
            return warehouse[i].get();
        }
    }
    return NULL;
}

Resource* City::getMineral()
{
    for (int i = 0; i < warehouse.size(); i++)
    {
        if (warehouse[i]->getName() == "Mineral")
        {
            return warehouse[i].get();
        }
    }
    return NULL;
}

Resource* City::getFish()
{
    for (int i = 0; i < warehouse.size(); i++)
    {
        if (warehouse[i]->getName() == "Fish")
        {
            return warehouse[i].get();
        }
    }
    return NULL;
}