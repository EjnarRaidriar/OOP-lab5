#ifndef BIOM_H
#define BIOM_H

#include<vector>
#include<memory>
#include"./resources/Resource.hpp"

class Biom
{
private:
    std::string name;
    std::vector<std::unique_ptr<Resource>> resources;
public:
    Biom();
    Biom(std::string name);
    virtual ~Biom();
    Resource* getResource();
    void addResource(Resource* resource);
    std::string getName();
    void setName(std::string name);
    void removeResource();
};

#endif