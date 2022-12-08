#ifndef SIMULATION_H
#define SIMULATION_H

#include"../ConfigBuilder/ConfigBuilder.h"
#include<unistd.h>

class Simulation
{
private:
    Config config;
public:
    Simulation();
    Simulation(Config &config);
    virtual ~Simulation() = default;

    void CheckBiom();
    void PrepareForWork();
    void GoToWork();
    void Work();
    void PlaceResources();
    void addWorkers();
    void CheckWorkers();
    void CheckTools();
    void EndTurn();

    void run();
};

#endif