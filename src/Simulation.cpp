#include"Biom.h"
#include"City.h"
#include"Forester.h"
#include"Fisher.h"
#include"Miner.h"

int main()
{
    int forester_num;
    int miner_num;
    int fisher_num;
    int forest_num;
    int mines_num;
    int river_num;
    std::cout<<"Forester workers num: ";
    std::cin>>forester_num;
    std::cout<<"Miner workers num: ";
    std::cin>>miner_num;
    std::cout<<"Fisher workers num: ";
    std::cin>>fisher_num;
    std::cout<<"Forest biom num: ";
    std::cin>>forest_num;
    std::cout<<"Mine biom num: ";
    std::cin>>mines_num;
    std::cout<<"River biom num: ";
    std::cin>>river_num;

    int maxWorkers;
    if (forester_num > miner_num && forester_num > fisher_num)
        maxWorkers = forester_num;
    else if (miner_num > forester_num && miner_num > fisher_num)
        maxWorkers = miner_num;
    else
        maxWorkers = fisher_num;

    int maxBioms;
    if (forest_num > mines_num && forest_num > river_num)
        maxBioms = forest_num;
    else if (mines_num > forest_num && mines_num > river_num)
        maxBioms = mines_num;
    else
        maxBioms = river_num;

    //initialization
    City* city = new City("City", forest_num+miner_num+fisher_num);
    std::vector<Forester*> forester;
    for (int i = 0; i < forest_num; i++)
    {
        forester.push_back(new Forester("Forester", 30, 10));
    }
    std::vector<Miner*> miner;
    for (int i = 0; i < miner_num; i++)
    {
        miner.push_back(new Miner("Miner", 30, 10));
    }
    std::vector<Fisher*> fisher;
    for (int i = 0; i < fisher_num; i++)
    {
        fisher.push_back(new Fisher("Fisher", 30, 10));
    }
    std::vector<Biom*> forest;
    for (int i = 0; i < forest_num; i++)
    {
        forest.push_back(new Biom("Forest"));
        for (int j = 0; j < 50; j++)
        {
            forest[i]->addResource(new Wood("Wood", 100));
        }
    }
    std::vector<Biom*> mine;
    for (int i = 0; i < mines_num; i++)
    {
        mine.push_back(new Biom("Mine"));
        for (int j = 0; j < 50; j++)
        {
            mine[i]->addResource(new Mineral("Mineral", 100));
        }
    }
    std::vector<Biom*> river;
    for (int i = 0; i < river_num; i++)
    {
        river.push_back(new Biom("River"));
        for (int j = 0; j < 50; j++)
        {
            river[i]->addResource(new Fish("Fish", 10));
        }
    }

    while(true)
    {
        //going to work
        for (int i = 0; i < maxWorkers; i++)
        {
            if (forester[i])
            {
                if (forester[i]->getToolAmount() == 0 && 
                    forester[i]->getLocation() == city->getName() &&
                    city->hasMinerals())
                {
                    forester[i]->addTool(city->getMineral());
                }
                if (forester[i]->getLocation() == forest.back()->getName()) {continue;}
                forester[i]->setLocation(forest.back()->getName());
            }
            if (miner[i])
            {
                if (miner[i]->getLocation() == mine.back()->getName()) {continue;}
                miner[i]->setLocation(mine.back()->getName());
            }
            if (fisher[i])
            {
                if (fisher[i]->getLocation() == river.back()->getName()) {continue;}
                fisher[i]->setLocation(river.back()->getName());
            }
        }

        while (true)
        {

        }

    return 0;
}