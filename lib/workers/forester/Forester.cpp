#include"Forester.hpp"

Forester::Forester() : Worker()
{
    setName("Nameless forester");
    Tool* axe = new Axe("Axe", 5, 10);
    addTool(axe);
}

Forester::Forester(std::string name, int age, int cargo)
    : Worker(name, age, cargo) {}

Forester::~Forester() {}

//Methods
void Forester::createTool()
{
    int w_index = -1;
    int i_index = -1;
    for (int i = 0; i < resources.size(); i++)
    {
        if (resources[i]->className() == "Iron")
        {
            i_index = i;
        }
        if (resources[i]->className() == "Wood")
        {
            w_index = i;
        }
    }
    if (i_index != -1 && w_index != -1)
    {
        Tool* axe = new Axe("Axe", 5, 10);
        addTool(axe);
        resources.erase(resources.begin() + i_index);
        resources.erase(resources.begin() + w_index);
    }
}
//Output Methods
void Forester::printData()
{
    std::cout<<RESET<<"-> Forester's data:"<<std::endl;
    std::cout<<"   Name: "<<getName()<<std::endl;
    std::cout<<"   Age: "<<getAge()<<std::endl;
    std::cout<<"   Cargo: "<<getCargo()<<std::endl;
    std::cout<<"   Nr. of tools: "<<getToolAmount()<<std::endl;
}
