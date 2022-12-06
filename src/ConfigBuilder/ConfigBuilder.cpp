#include"ConfigBuilder.hpp"

ConfigBuilder::ConfigBuilder() {}

ConfigBuilder::~ConfigBuilder() {}

ConfigBuilder& ConfigBuilder::foresters(int foresters_num)
{
    this->foresters_num = foresters_num;
    return *this;
}

ConfigBuilder& ConfigBuilder::miners(int miners_num)
{
    this->miners_num = miners_num;
    return *this;
}

ConfigBuilder& ConfigBuilder::fishers(int fishers_num)
{
    this->fishers_num = fishers_num;
    return *this;
}

ConfigBuilder& ConfigBuilder::forests(int forests_num)
{
    this->forests_num = forests_num;
    return *this;
}

ConfigBuilder& ConfigBuilder::mines(int mines_num)
{
    this->mines_num = mines_num;
    return *this;
}

ConfigBuilder& ConfigBuilder::lakes(int lakes_num)
{
    this->lakes_num = lakes_num;
    return *this;
}

Config& ConfigBuilder::build()
{
    Config* config = new Config(
        this->foresters_num,
        this->miners_num,
        this->fishers_num,
        this->forests_num,
        this->mines_num,
        this->lakes_num);
    return *config;
}