#include"Config.hpp"

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

void Config::Initialize()
{
    for (int i = 0; i < this->foresters_num; i++)
    {
        this->foresters.push_back(std::make_unique<Forester>());
    }
    for (int i = 0; i < this->miners_num; i++)
    {
        this->miners.push_back(std::make_unique<Miner>());
    }
    for (int i = 0; i < this->fishers_num; i++)
    {
        this->fishers.push_back(std::make_unique<Fisher>());
    }
    for (int i = 0; i < this->forests_num; i++)
    {
        this->forests.push_back(std::make_unique<Biom>("Forest"));
    }
    for (int i = 0; i < this->mines_num; i++)
    {
        this->mines.push_back(std::make_unique<Biom>("Mine"));
    }
    for (int i = 0; i < this->lakes_num; i++)
    {
        this->lakes.push_back(std::make_unique<Biom>("Lake"));
    }
}

Worker& Config::getForester(int index)
{
    return *foresters[index];
}

Worker& Config::getMiner(int index)
{
    return *miners[index + this->foresters_num];
}

Worker& Config::getFisher(int index)
{
    return *fishers[index];
}

Biom& Config::getForest(int index)
{
    return *forests[index];
}

Biom& Config::getMine(int index)
{
    return *mines[index];
}

Biom& Config::getLake(int index)
{
    return *lakes[index];
}