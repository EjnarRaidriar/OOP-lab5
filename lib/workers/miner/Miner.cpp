
#include"Miner.hpp"

Miner::Miner() : Worker()
{
    setName("Nameless Miner");
}

Miner::Miner(std::string name, int age, int cargo)
    : Worker(name, age, cargo) {}

Miner::~Miner() {}

//Methods
bool Miner::collectResource(Resource* resource)
{
    if (resource == NULL)
    {
        std::cout<<RED<<"-> No resource to collect!"<<std::endl;
        return false;
    }
    if (resources.size() < getCargo())
    {
        if (resource->getDurability() <= getTool()->getEfficiency()) {
                getTool()->Hit();
                resources.push_back(resource);
                //Resource* mineral = new Mineral(*resource);
                //resources.push_back(mineral);
                std::cout<<GREEN<<"-> "<<getName()<<" collected "<<resource->getName()<<std::endl;
                return true;
            } else {
                resource->setDurability(resource->getDurability() - getTool()->getEfficiency());
                getTool()->Hit();
                std::cout<<RESET<<"-> "<<getName()<<" strikes "<<resource->getName()<<std::endl;
                std::cout<<"   Resource durability: "<<resource->getDurability()<<std::endl;
                std::cout<<"   Tool efficiency: "<<getTool()->getEfficiency()<<std::endl;
                return false;
        }
    }
    else
    {
        std::cout<<RED<<"-> Miner "<<getName()<<"'s cargo is full\n   He can't collect more resources!"<<std::endl;
        return false;
    }
}

void Miner::createTool(Mineral &mineral, )
{
    Pickaxe* pickaxe = new Pickaxe("Pickaxe", 5, 10);
    addTool(pickaxe);
    std::cout<<YELLOW<<"-> "<<getName()<<" created a new "<<pickaxe->getName()<<std::endl;
    mineral.~Mineral();
}
//Output Methods
void Miner::printData()
{
    std::cout<<RESET<<"-> Miner's data:"<<std::endl;
    std::cout<<"   Job: "<<"Miner"<<std::endl;
    std::cout<<"   Name: "<<getName()<<std::endl;
    std::cout<<"   Age: "<<getAge()<<std::endl;
    std::cout<<"   Cargo: "<<getCargo()<<std::endl;
    std::cout<<"   Nr. of tools: "<<getToolAmount()<<std::endl;
}
