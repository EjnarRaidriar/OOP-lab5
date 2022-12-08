CC = g++
CFLAGS = -g -O3 -std=c++17 -Wall -Wextra -MMD -MP
all: 
	$(CC) $(CFLAGS) `find . -type f -iregex ".*\.cpp"` -o a.out
clean:
	rm *.out