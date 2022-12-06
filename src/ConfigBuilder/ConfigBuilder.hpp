#ifndef CONFIGURATIONBUILDER_HPP
#define CONFIGURATIONBUILDER_HPP

#include"Config.hpp"

class ConfigBuilder
{
private:
    int foresters_num;
    int miners_num;
    int fishers_num;
    int forests_num;
    int mines_num;
    int lakes_num;
public:
    ConfigBuilder();
    virtual ~ConfigBuilder();
    ConfigBuilder& foresters(int foresters_num);
    ConfigBuilder& miners(int miners_num);
    ConfigBuilder& fishers(int fishers_num);
    ConfigBuilder& forests(int forests_num);
    ConfigBuilder& mines(int mines_num);
    ConfigBuilder& lakes(int lakes_num);
    Config& build();
};

#endif