#ifndef MINER_HPP
#define MINER_HPP
#include"../workers/Worker.hpp"
#include"../pickaxe/Pickaxe.hpp"
#include"../resources/iron/Iron.hpp"
#include"../IronToolUser.hpp"
class Miner : public Worker, public IronToolUser
{
public:
    Miner();
    Miner(std::string name, int age, int cargo);
    virtual ~Miner();
    //Getters
    virtual std::string className() const override;
    //Methods
    bool collectResource(Resource* resource) override;
    void createTool(Iron &iron, Wood &wood) override;
    //Output Methods
    void printData();
};

#endif