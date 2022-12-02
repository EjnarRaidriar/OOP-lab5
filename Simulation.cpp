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
    return 0;
}