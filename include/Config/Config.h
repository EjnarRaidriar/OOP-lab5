#ifndef CONFIG_H
#define CONFIG_H

#include"../../include/resources/fish/Fish.h"
#include"../../include/resources/iron/Iron.h"
#include"../../include/resources/wood/Wood.h"
#include"../../include/tools/Tool.h"
#include"../../include/tools/rod/Rod.h"
#include"../../include/tools/axe/Axe.h"
#include"../../include/tools/pickaxe/Pickaxe.h"
#include"../../include/workers/Worker.h"
#include"../../include/workers/fisher/Fisher.h"
#include"../../include/workers/miner/Miner.h"
#include"../../include/workers/forester/Forester.h"
#include"../../include/biom/Biom.h"
#include"../../include/city/City.h"
#include"../../include/colors.h"

class Config
{
private:
    int foresters_num;
    int miners_num;
    int fishers_num;
    int forests_num;
    int mines_num;
    int lakes_num;
    std::vector<Worker*> foresters;
    std::vector<Worker*> miners;
    std::vector<Worker*> fishers;
    std::vector<Biom*> forests;
    std::vector<Biom*> mines;
    std::vector<Biom*> lakes;
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

    // Config (const Config&) = delete;
    // Config& operator=(const Config&) = delete;

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

    void addNewForester();
    void addNewMiner();
    void addNewFisher();

    // virtual const Worker &getForesterRef(int index) const;
    // virtual const Worker &getMinerRef(int index) const;
    // virtual const Worker &getFisherRef(int index) const;
    // virtual const Biom &getForestRef(int index) const;
    // virtual const Biom &getMineRef(int index) const;
    // virtual const Biom &getLakeRef(int index) const;
    // virtual const City &getCityRef() const;

    // void setForester(std::unique_ptr<Worker> worker, int index);

    Worker* getForester(int index);
    Worker* getMiner(int index);
    Worker* getFisher(int index);
    Biom* getForest(int index);
    Biom* getMine(int index);
    Biom* getLake(int index);
    City* getCity();

    void printData();

    void Initialize();

    static Config *Get();

};

#endif