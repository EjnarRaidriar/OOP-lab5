#include"../include/Simulation/Simulation.h"

int main()
{
    ConfigBuilder builder;
    Config config = builder
        .foresters(5)
        .miners(5)
        .fishers(5)
        .forests(5)
        .mines(5)
        .lakes(5)
        .build();
    Simulation simulation(config);
    simulation.run();
    return 0;
}