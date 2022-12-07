#include"Config.hpp"

Config::Config()
{
    this->foresters_num = 1;
    this->miners_num = 1;
    this->fishers_num = 1;
    this->forests_num = 1;
    this->mines_num = 1;
    this->lakes_num = 1;
}

Config::Config(
    int foresters_num,
    int miners_num,
    int fishers_num,
    int forests_num,
    int mines_num,
    int lakes_num)
{
    this->foresters_num = foresters_num;
    this->miners_num = miners_num;
    this->fishers_num = fishers_num;
    this->forests_num = forests_num;
    this->mines_num = mines_num;
    this->lakes_num = lakes_num;
}

Config::~Config() {}

void Config::setForestersNum(int foresters_num)
{
    this->foresters_num = foresters_num;
}

void Config::setMinersNum(int miners_num)
{
    this->miners_num = miners_num;
}

void Config::setFishersNum(int fishers_num)
{
    this->fishers_num = fishers_num;
}

void Config::setForestsNum(int forests_num)
{
    this->forests_num = forests_num;
}

void Config::setMinesNum(int mines_num)
{
    this->mines_num = mines_num;
}

void Config::setLakesNum(int lakes_num)
{
    this->lakes_num = lakes_num;
}

int Config::getForestersNum()
{
    return this->foresters_num;
}

int Config::getMinersNum()
{
    return this->miners_num;
}

int Config::getFishersNum()
{
    return this->fishers_num;
}

int Config::getForestsNum()
{
    return this->forests_num;
}

int Config::getMinesNum()
{
    return this->mines_num;
}

int Config::getLakesNum()
{
    return this->lakes_num;
}

void Config::deleteForester(int index)
{
    this->foresters.erase(this->foresters.begin() + index);
}

void Config::deleteMiner(int index)
{
    this->miners.erase(this->miners.begin() + index);
}

void Config::deleteFisher(int index)
{
    this->fishers.erase(this->fishers.begin() + index);
}

void Config::deleteForest(int index)
{
    this->forests.erase(this->forests.begin() + index);
}

void Config::deleteMine(int index)
{
    this->mines.erase(this->mines.begin() + index);
}

void Config::deleteLake(int index)
{
    this->lakes.erase(this->lakes.begin() + index);
}

void Config::addNewForester()
{
    this->foresters.push_back(std::make_unique<Forester>());
}

void Config::addNewMiner()
{
    this->miners.push_back(std::make_unique<Miner>());
}

void Config::addNewFisher()
{
    this->fishers.push_back(std::make_unique<Fisher>());
}

Worker* Config::getForester(int index)
{
    return foresters[index].get();
}

Worker* Config::getMiner(int index)
{
    return miners[index].get();
}

Worker* Config::getFisher(int index)
{
    return fishers[index].get();
}

Biom* Config::getForest(int index)
{
    return forests[index].get();
}

Biom* Config::getMine(int index)
{
    return mines[index].get();
}

Biom* Config::getLake(int index)
{
    return lakes[index].get();
}

City* Config::getCity()
{
    return city;
}

void Config::Initialize()
{
    //initializing foresters
    for (int i = 0; i < this->foresters_num; i++)
    {
        this->foresters.push_back(std::make_unique<Forester>());
    }
    //initializing miners
    for (int i = 0; i < this->miners_num; i++)
    {
        this->miners.push_back(std::make_unique<Miner>());
    }
    //initializing fishers
    for (int i = 0; i < this->fishers_num; i++)
    {
        this->fishers.push_back(std::make_unique<Fisher>());
    }
    //initializing forests
    for (int i = 0; i < this->forests_num; i++)
    {
        this->forests.push_back(std::make_unique<Biom>("Forest"));
        for (int j = 0; j < 50; j++)
        {
            this->forests[i]->addResource(std::make_unique<Wood>());
        }
    }
    //initializing mines
    for (int i = 0; i < this->mines_num; i++)
    {
        this->mines.push_back(std::make_unique<Biom>("Mine"));
        for (int j = 0; j < 50; j++)
        {
            this->mines[i]->addResource(std::make_unique<Iron>());
        }
    }
    //initializing lakes
    for (int i = 0; i < this->lakes_num; i++)
    {
        this->lakes.push_back(std::make_unique<Biom>("Lake"));
        for (int j = 0; j < 50; j++)
        {
            this->lakes[i]->addResource(std::make_unique<Fish>());
        }
    }
    //initializing city
    this->city = new City("City", foresters_num + miners_num + fishers_num);
}

Config* Config::Get()
{
    static Config config;
    return &config;
}
