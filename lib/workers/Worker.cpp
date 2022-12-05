#include"Worker.hpp"

//Change all cargo accurances
Worker::Worker()
{
    name = "Nameless worker";
    age = 14;
    cargo = 10;
    location = "City";
}

Worker::Worker(std::string name, int age, int cargo)
{
    this->name = name;
    this->age = age;
    this->cargo = cargo;
    location = "City";
}

Worker::~Worker() {}

std::string Worker::getName()
{
    return name;
}

void Worker::setName(std::string name)
{
    this->name = name;
}

int Worker::getAge()
{
    return age;
}

void Worker::setAge(int age)
{
    this->age = age;
}

int Worker::getCargo()
{
    return cargo;
}

void Worker::setCargo(int cargo)
{
    this->cargo = cargo;
}

std::string Worker::getLocation()
{
    return location;
}

void Worker::setLocation(std::string location)
{
    this->location = location;
}

Resource* Worker::getResource()
{
    if (resources.size() > 0)
    {
        return resources.back();
    }
    else
    {
        return NULL;
    }
}

int Worker::getResourceAmount()
{
    return resources.size();
}

void Worker::removeResource()
{
    resources.pop_back();
}

int Worker::getToolAmount() const
{
    return tools.size();
}

void Worker::addTool(Tool* tool)
{
    tools.push_back(tool);
}

//Methods
void Worker::removeTool(int index)
{
    tools.erase(tools.begin() + index);
}

void Worker::Hit()
{
    tools.back()->setHits(tools.back()->getHits() + 1);
    if (tools.back()->getDurability() <= 0)
    {
        std::cout<<"-> Tool is broken!"<<std::endl;
        tools.back()->~Tool();
        tools.pop_back();
    }
    if (tools.back()->getEfficiency() <= 0)
    {
        std::cout<<RED<<"-> Tool is damaged!"<<std::endl;
        tools.back()->setDurability(tools.back()->getDurability() - 1);
    }
    if (tools.back()->getHits() > tools.back()->getDurability())
    {
        tools.back()->setEfficiency(tools.back()->getEfficiency() - 1);
        std::cout<<RED<<"-> Efficiency redurced to "<<tools.back()->getEfficiency()<<std::endl;
        tools.back()->setHits(0);
    }

}

//Output Methods
void Worker::printResources() const
{
    std::cout<<RESET<<"-> Worker "<<name<<"'s resources:"<<std::endl;
    for (unsigned int i = 0; i < resources.size(); i++)
    {
        std::cout<<"   Resource nr. "<<i+1<<": "<<resources[i]->getName()<<std::endl;
    }
}

void Worker::printTools() const
{
    std::cout<<RESET<<"-> "<<name<<"'s tools:"<<std::endl;
    for (unsigned int i = 0; i < tools.size(); i++)
    {
        std::cout<<"   Tool nr. "<<i+1<<":"<<std::endl;
        tools[i]->printData();
    }
}