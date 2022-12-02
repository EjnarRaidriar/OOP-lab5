#include"Fisher.h"
#include<memory>
#include<unistd.h>

int main()
{
    Fisher* fisher = new Fisher("fisher", 30, 10);
    Rod* rod = new Rod("Rod", 100, 10);
    fisher->addTool(*rod);
    std::vector<Resource*> resources;
    for (int i = 0; i < 2; i++)
    {
        resources.push_back(new Fish());
    }
    while (true)
    {
        for (int i = 0; i < 2; i++)
        {
            if (resources[i])
            {
                if (fisher->getToolAmount() == 0)
                { 
                    fisher->addNewTool();
                    fisher->printTools();
                    usleep(500000);
                }
                while (true)
                {
                    if (resources[i])
                    {
                        if (fisher->collectResource(resources[i]))
                        {
                            resources.pop_back();
                            break;
                        }
                        usleep(500000);
                    }
                    else 
                    {
                        break;
                    }
                }
            }
            else std::cout<<"-> No resources left!"<<std::endl;
        }
        fisher->printData();
        fisher->printResources();
        sleep(1);
        break;
    }
    return 0;
}