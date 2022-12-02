all: testForester testFisher testMiner testBiom testCity Simulation

Simulation:Simulation.o
	g++ $< -o $@

testBiom:testBiom.o
	g++ $< -o $@

testCity:testCity.o
	g++ $< -o $@

testForester:testForester.o
	g++ $< -o $@

testFisher:testFisher.o
	g++ $< -o $@

testMiner:testMiner.o
	g++ $< -o $@

Simulation.o:Simulation.cpp Config.h
	g++ -c -O0 $^

testBiom.o:testBiom.cpp
	g++ -c -O0 $^

testCity.o:testCity.cpp
	g++ -c -O0 $^

testForester.o:testForester.cpp
	g++ -c -O0 $^

testFisher.o:testFisher.cpp
	g++ -c -O0 $^

testMiner.o:testMiner.cpp
	g++ -c -O0 $^

clean:
	rm *.o testForester testFisher testMiner testBiom testCity Simulation