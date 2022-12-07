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
        return resources.back().get();
    }
    else
    {
        return NULL;
    }
}

void Worker::addResource(Resource* resource)
{
    resources.push_back(std::unique_ptr<Resource>(resource));
}

int Worker::getResourceAmount()
{
    return resources.size();
}

void Worker::removeResource()
{
    resources.pop_back();
}

Tool* Worker::getTool(int index)
{
    return tools[index].get();
}

void Worker::addTool(Tool* tool)
{
    tools.push_back(std::unique_ptr<Tool>(tool));
}

int Worker::getToolAmount() const
{
    return tools.size();
}

//Methods
void Worker::removeTool(int index)
{
    tools[index]->~Tool();
    tools.erase(tools.begin() + index);
}

bool Worker::hasTool()
{
    if (tools.size() > 0)
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool Worker::Hit(Resource *resource)
{
    if (tools.back()->checkBroken())
    {
        std::cout<<RED<<"-> "<<name<<" broke "<<tools.back()->getName()<<"!"<<std::endl;
        tools.back()->~Tool();
        tools.pop_back();
        return false;
    }
    else
    {
        std::cout<<RESET<<"-> "<<name<<" hits the "<<resource->getName()<<" with his "<<tools.back()->getName()<<std::endl;
        return true;
    }
}

bool Worker::collectResource(Resource* resource)
{
    //Don't stop collecting until you can't do it anymore
    if (resource == NULL)
    {
        std::cout<<RED<<"-> No resource to collect!"<<std::endl;
        return false;
    }
    if (resources.size() >= getCargo())
    {
        std::cout<<RED<<"-> Forester "<<getName()<<"'s cargo is full"<<std::endl;
        std::cout<<"   He can't collect more resources!"<<std::endl;
        return false;
    }
    if (getToolAmount() == 0)
    {
        std::cout<<RED<<"-> Worker "<<getName()<<" has no tools!"<<std::endl;
        return false;
    }

    if (resource->getDurability() <= tools[tools.size()-1]->getEfficiency()) {
            if(Hit(resource))
            {
                resources.push_back(std::unique_ptr<Resource>(resource));
                std::cout<<GREEN<<"   "<<getName()<<" collected "<<resource->getName()<<std::endl;
                return true;
            }
    }
    else 
    {
        if (Hit(resource))
        {
            resource->setDurability(resource->getDurability() - tools[tools.size()-1]->getEfficiency());
            std::cout<<RESET<<"   Resource durability: "<<resource->getDurability()<<std::endl;
            std::cout<<"   Tool efficiency: "<<tools[tools.size()-1]->getEfficiency()<<std::endl;
            return true;
        }
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

void Worker::printData() const
{
    std::cout<<RESET<<"-> "<<className()<<"'s data:"<<std::endl;
    std::cout<<"   Name: "<<name<<std::endl;
    std::cout<<"   Age: "<<age<<std::endl;
    std::cout<<"   Cargo: "<<cargo<<std::endl;
    std::cout<<"   Nr. of tools: "<<tools.size()<<std::endl;
}