#include"./Simulation/Simulation.hpp"

int main()
{
    ConfigBuilder builder;
    Config& config = builder
        .foresters(10)
        .miners(10)
        .fishers(10)
        .forests(10)
        .mines(10)
        .lakes(10)
        .build();
    Simulation simulation(config);
    simulation.run();
    return 0;
}