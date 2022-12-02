#include"Miner.h"
#include<memory>
#include<unistd.h>

int main()
{
    Miner* miner = new Miner("miner", 30, 20);
    Pickaxe* pickaxe = new Pickaxe("pickaxe", 100, 10);
    miner->addTool(*pickaxe);
    std::vector<Resource*> resources;
    for (int i = 0; i < 20; i++)
    {
        resources.push_back(new Mineral());
    }
    while (true)
    {
        for (int i = 0; i < 20; i++)
        {
            if (resources[i])
            {
                if (miner->getToolAmount() == 0)
                { 
                    miner->addNewTool();
                    miner->printTools();
                    usleep(250000);
                }
                while (true)
                {
                    if (resources[i])
                    {
                        if (miner->collectResource(resources[i]))
                        {
                            resources.pop_back();
                            break;
                        }
                        usleep(250000);
                    }
                    else 
                    {
                        break;
                    }
                }
            }
            else std::cout<<RED<<"-> No resources left!"<<std::endl;
        }
        miner->printData();
        miner->printResources();
        sleep(1);
        break;
    }
    return 0;
}