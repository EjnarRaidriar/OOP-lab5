#ifndef SIMULATION_HPP
#define SIMULATION_HPP

#include"../ConfigBuilder/ConfigBuilder.hpp"

class Simulation
{
public:
    Simulation(Config& config);
    virtual ~Simulation();
    void run();
};

#endif