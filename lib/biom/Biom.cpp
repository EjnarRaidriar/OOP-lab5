#include"Biom.hpp"

Biom::Biom()
{
    name = "Biom";
}

Biom::Biom(std::string name)
{
    this->name = name;
}

Biom::~Biom()
{
}

Resource* Biom::getResource()
{
    if (resources.size() > 0)
    {
        return resources.back().get();
    }
    else
    {
        return nullptr;
    }
}

void Biom::addResource(std::unique_ptr<Resource> resource)
{
    resources.push_back(std::move(resource));
}

void Biom::addResource(Resource* resource)
{
    resources.push_back(std::make_unique<Resource>(resource));
}

std::string Biom::getName()
{
    return name;
}

void Biom::setName(std::string name)
{
    this->name = name;
}

void Biom::removeResource()
{
    resources.pop_back();
}