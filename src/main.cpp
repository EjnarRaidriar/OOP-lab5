#include"../include/Simulation/Simulation.h"

int main()
{
    ConfigBuilder builder;
    Config config = builder
        .foresters(1)
        .miners(1)
        .fishers(1)
        .forests(1)
        .mines(1)
        .lakes(1)
        .build();
    Simulation simulation(config);
    simulation.run();
    return 0;
}