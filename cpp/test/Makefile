# Makefile for various test scripts

# Compiler shortcuts
CC=g++
FLAGS=-Wall -Werror -pedantic
STD=-std=c++11

# Dependency shortcuts
GRAPH_DEP=../graph.hpp


graph_test: graph_test.cpp $(GRAPH_DEP)
	$(CC) $(STD) $(FLAGS) -o graph.tst graph_test.cpp -I/$(GRAPH_DEP)

clean:
	rm -f graph.tst 