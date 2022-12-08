#include"Simulation.h"

//I'm even using marcros (×_×)

//workers getter macros
#define forester config.getForester
#define miner config.getMiner
#define fisher config.getFisher
//nr of workers
#define forester_num config.getForestersNum()
#define miner_num config.getMinersNum()
#define fisher_num config.getFishersNum()

//bioms getter macros
#define forest config.getForest
#define mine config.getMine
#define lake config.getLake
//nr of bioms
#define forest_num config.getForestsNum()
#define mine_num config.getMinesNum()
#define lake_num config.getLakesNum()

Simulation::Simulation() 
{
    this->config = ConfigBuilder().build();
}

Simulation::Simulation(Config &config)
{
    this->config = config;
}

void Simulation::CheckBiom()
{
    if (forest_num > 1)
    {
        for (int i = 0; i < forest_num; i++)
        {
            if (!forest(i)->getResource()) config.deleteForest(i);
        }
    }
    else if(forest_num == 1)
    {
        if (!forest(0)->getResource()) config.deleteForest(0);
    }
    if (mine_num > 1)
    {
        for (int i = 0; i < mine_num; i++)
        {
            if (!mine(i)->getResource()) config.deleteMine(i);
        }
    }
    else if(mine_num == 1)
    {
        if (!mine(0)->getResource()) config.deleteMine(0);
    }
    if (lake_num > 1)
    {
        for (int i = 0; i < lake_num; i++)
        {
            if (!lake(i)->getResource()) config.deleteLake(i);
        }
    }
    else if(lake_num == 1)
    {
        if (!lake(0)->getResource()) config.deleteLake(0);
    }
}

void Simulation::PrepareForWork()
{

}

void Simulation::GoToWork()
{
    if (forest_num > 0)
    {
        for (int i = 0; i < forester_num; i++)
        {
            if (forester(i)->getLocation() == "City")
            {
                forester(i)->setLocation("Forest");
            }
        }
    }
    if (mine_num > 0)
    {
        for (int i = 0; i < miner_num; i++)
        {
            if (miner(i)->getLocation() == "City")
            {
                miner(i)->setLocation("Mine");
            }
        }
    }
    if (lake_num > 0)
    {
        for (int i = 0; i < fisher_num; i++)
        {
            if (fisher(i)->getLocation() == "City")
            {
                fisher(i)->setLocation("Lake");
            }
        }
    }
}

void Simulation::Work()
{
    if (forest(forest_num-1)) //Work if forest exists
    {
        for (int i = 0; i < forester_num; i++)
        {
            if (forester(i)->getLocation() == "Forest")
            {
                bool stillWorking = true;
                while(stillWorking)
                {
                    //if worker can't collect more resources we exit loop
                    if (!forester(i)->collectResource(forest( forest_num-1 )->getResource()))
                    {
                        //TODO doesn't reach this place
                        stillWorking = false;
                    }
                }
            }
        }
    }
    else
    {   //Go home if there is no work anymore
        for (int i = 0; i < forester_num; i++)
        {
            if (forester(i)->getLocation() == "Forest")
            {
                forester(i)->setLocation("City");
            }
        }
    }
    //basically the same but for miners
    if (mine(mine_num-1)) //Work if mine exists
    {
        for (int i = 0; i < miner_num; i++)
        {
            if (miner(i)->getLocation() == "Mine")
            {
                bool stillWorking = true;
                while(stillWorking)
                {
                    if (!miner(i)->collectResource
                        (mine( mine_num-1 )->getResource()))
                    {
                        stillWorking = false;
                    }
                }
            }
        }
    }
    else 
    {   //Go home if there is no work anymore
        for (int i = 0; i < miner_num; i++)
        {
            if (miner(i)->getLocation() == "Mine")
            {
                miner(i)->setLocation("City");
            }
        }
    }
    //basically the same but for fishers
    if (lake(lake_num-1)) //Work if lake exists
    {
        for (int i = 0; i < fisher_num; i++)
        {
            if (fisher(i)->getLocation() == "Lake")
            {
                bool stillWorking = true;
                while(stillWorking)
                {
                    if (!fisher(i)->collectResource
                        (lake( lake_num-1 )->getResource()))
                    {
                        stillWorking = false;
                    }
                }
            }
        }
    }
    else 
    {   //Go home if there is no work anymore
        for (int i = 0; i < fisher_num; i++)
        {
            if (fisher(i)->getLocation() == "Lake")
            {
                fisher(i)->setLocation("City");
            }
        }
    }
}

void Simulation::PlaceResources()
{
    //placing the resources from worker into city
    for (int i = 0; i < forester_num; i++)
    {
        //Go home in case forester is not there
        if (forester(i)->getLocation() != "City")
        {
            forester(i)->setLocation("City");
        }
        //adding resources to city
        for (int j = 0; j < forester(i)->getResourceAmount(); j++)
        {
            config.getCity()->addRsource(config.getForester(i)->getResource());
        }
    }
    for (int i = 0; i < miner_num; i++)
    {
        //Go home in case miner is not there
        if (miner(i)->getLocation() != "City")
        {
            miner(i)->setLocation("City");
        }
        //adding resources to city
        for (int j = 0; j < miner(i)->getResourceAmount(); j++)
        {
            config.getCity()->addRsource(miner(i)->getResource());
        }
    }
    for (int i = 0; i < fisher_num; i++)
    {
        //Go home in case fisher is not there
        if (fisher(i)->getLocation() != "City")
        {
            fisher(i)->setLocation("City");
        }
        //adding resources to city
        for (int j = 0; j < fisher(i)->getResourceAmount(); j++)
        {
            config.getCity()->addRsource(fisher(i)->getResource());
        }
    }
}

void Simulation::addWorkers()
{
    //adding workers if there are enough resources for them
    if (config.getCity()->getWoodAmount() >= 10 &&
        config.getCity()->getFishAmount() >= 20)
    {
        config.addNewFisher();
    }
    if (config.getCity()->getWoodAmount() >= 10 &&
        config.getCity()->getIronAmount() >= 10 &&
        config.getCity()->getFishAmount() >= 20)
    {
        config.addNewForester();
    }
    if (config.getCity()->getWoodAmount() >= 10 &&
        config.getCity()->getIronAmount() >= 10 &&
        config.getCity()->getFishAmount() >= 20)
    {
        config.addNewMiner();
    }
}

void Simulation::CheckWorkers()
{
    //checking if workers are too old to work
    for (int i = 0; i < forester_num; i++)
    {
        if (forester(i)->getAge() >= 60)
        {
            config.deleteForester(i);
            config.setForestersNum(forester_num - 1);
        }
    }
    for (int i = 0; i < miner_num; i++)
    {
        if (miner(i)->getAge() >= 60)
        {
            config.deleteMiner(i);
            config.setMinersNum(miner_num - 1);
        }
    }
    for (int i = 0; i < fisher_num; i++)
    {
        if (fisher(i)->getAge() >= 60)
        {
            config.deleteFisher(i);
            config.setFishersNum(fisher_num - 1);
        }
    }

    addWorkers();
}

void Simulation::CheckTools()
{
    //If worker has a tool then we will sharpen it
    //if he does not then we will create one
    for (int i = 0; i < forester_num; i++)
    {
        if (forester(i)->getToolAmount() > 0)
        {
            for (int j = 0; j < forester(i)->getToolAmount(); j++)
            {
                forester(i)->addResource(config.getCity()->getIron());
                ((IronToolUser*)forester(i))->Sharpen(forester(i)->getTool(j));
            }
        }
        else
        {  
            forester(i)->addResource(config.getCity()->getWood());
            forester(i)->createTool();
        }
    }
    for (int i = 0; i < miner_num; i++)
    {
        if (miner(i)->getToolAmount() > 0)
        {
            for (int j = 0; j < miner(i)->getToolAmount(); j++)
            {
                miner(i)->addResource(config.getCity()->getIron());
                ((IronToolUser*)miner(i))->Sharpen(miner(i)->getTool(j));
            }
        }
        else
        {  
            miner(i)->addResource(config.getCity()->getWood());
            miner(i)->createTool();
        }
    }
    for (int i = 0; i < fisher_num; i++)
    {
        if (fisher(i)->getToolAmount() > 0)
        {
            //Fisher can't sharpen his tools
        }
        else
        {  
            fisher(i)->addResource(config.getCity()->getWood());
            fisher(i)->addResource(config.getCity()->getIron());
            fisher(i)->createTool();
        }
    }
    //put wood and iron back into city
    PlaceResources();
}

void Simulation::EndTurn()
{
    //adding 5 years to workers age
    for (int i = 0; i < forester_num; i++)
    {
        forester(i)->setAge(forester(i)->getAge() + 5);
    }
    for (int i = 0; i < miner_num; i++)
    {
        miner(i)->setAge(miner(i)->getAge() + 5);
    }
    for (int i = 0; i < fisher_num; i++)
    {
        fisher(i)->setAge(fisher(i)->getAge() + 5);
    }
    config.printData();
    sleep(3);
}

void Simulation::run()
{
    while (true)
    {
        CheckBiom();
        std::cout<<RESET<<"CheckBiom()"<<std::endl;
        GoToWork();
        std::cout<<"GoToWork()"<<std::endl;
        Work();
        std::cout<<"Work()"<<std::endl;
        PlaceResources();
        std::cout<<"PlaceResources()"<<std::endl;
        CheckWorkers();
        std::cout<<"CheckWorkers()"<<std::endl;
        CheckTools();
        std::cout<<"CheckTools()"<<std::endl;
        EndTurn();
        std::cout<<"EndTurn()"<<std::endl;
    }
}