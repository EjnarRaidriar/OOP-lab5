#include"Simulation.hpp"

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
    config.Initialize();
}

Simulation::~Simulation() {}

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
                    if (!forester(i)->collectResource //attention! if not
                        (forest( forest_num-1 )->getResource()))
                    {
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

void Simulation::EndWork()
{
    //placing the resources from worker into city
    for (int i = 0; i < forester_num; i++)
    {
        for (int j = 0; j < forester(i)->getResourceAmount(); j++)
        {
            config.getCity()->addRsource(forester(i)->getResource());
        }
    }
    for (int i = 0; i < miner_num; i++)
    {
        for (int j = 0; j < miner(i)->getResourceAmount(); j++)
        {
            config.getCity()->addRsource(miner(i)->getResource());
        }
    }
    for (int i = 0; i < fisher_num; i++)
    {
        for (int j = 0; j < fisher(i)->getResourceAmount(); j++)
        {
            config.getCity()->addRsource(fisher(i)->getResource());
        }
    }
    //TODO check for tools and add sharpening system
}

void Simulation::run()
{
    while (true)
    {
        CheckBiom();
        
        GoToWork();
        
        Work();

    }
}