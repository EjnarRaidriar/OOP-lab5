#ifndef CONFIG_HPP
#define CONFIG_HPP

#include"../lib/resources/Resource.hpp"
#include"../lib/resources//fish/Fish.hpp"
#include"../lib/resources/iron/Iron.hpp"
#include"../lib/resources/wood/Wood.hpp"
#include"../lib/tools/Tool.hpp"
#include"../lib/tools/rod/Rod.hpp"
#include"../lib/tools/axe/Axe.hpp"
#include"../lib/tools/pickaxe/Pickaxe.hpp"
#include"../lib/workers/Worker.hpp"
#include"../lib/workers/fisher/Fisher.hpp"
#include"../lib/workers/miner/Miner.hpp"
#include"../lib/workers/forester/Forester.hpp"
#include"../lib/biom/Biom.hpp"
#include"../lib/city/City.hpp"
#include"../lib/colors.h"

class Config
{
private:
    int foresters_num;
    int miners_num;
    int fishers_num;
    int forests_num;
    int mines_num;
    int lakes_num;
    std::vector<std::unique_ptr<Worker>> foresters;
    std::vector<std::unique_ptr<Worker>> miners;
    std::vector<std::unique_ptr<Worker>> fishers;
    std::vector<std::unique_ptr<Biom>> forests;
    std::vector<std::unique_ptr<Biom>> mines;
    std::vector<std::unique_ptr<Biom>> lakes;
    City *city;
public:
    Config();
    Config(
        int foresters_num,
        int miners_num,
        int fishers_num,
        int forests_num,
        int mines_num,
        int lakes_num);
    virtual ~Config();
    void setForestersNum(int foresters_num);
    void setMinersNum(int miners_num);
    void setFishersNum(int fishers_num);
    void setForestsNum(int forests_num);
    void setMinesNum(int mines_num);
    void setLakesNum(int lakes_num);
    int getForestersNum();
    int getMinersNum();
    int getFishersNum();
    int getForestsNum();
    int getMinesNum();
    int getLakesNum();

    void deleteForester(int index);
    void deleteMiner(int index);
    void deleteFisher(int index);
    void deleteForest(int index);
    void deleteMine(int index);
    void deleteLake(int index);

    void Initialize();

    static Config *Get();

    Worker* getForester(int index);
    Worker* getMiner(int index);
    Worker* getFisher(int index);
    Biom* getForest(int index);
    Biom* getMine(int index);
    Biom* getLake(int index);
};

#endif