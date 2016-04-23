all: graph

graph: Graph.o
	g++ Graph.o -o graph
Graph.o: Graph.cpp
	g++ -c Graph.cpp