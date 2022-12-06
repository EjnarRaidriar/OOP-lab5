#ifndef SIMULATION_HPP
#define SIMULATION_HPP

#include"../ConfigBuilder/ConfigBuilder.hpp"

class Simulation
{
    Config config;
public:
    Simulation();
    Simulation(Config &config);
    virtual ~Simulation();

    void CheckBiom();
    void PrepareForWork();
    void GoToWork();
    void Work();
    void EndWork();

    void run();
};

#endif