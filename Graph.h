#include <iostream>							//Definitely need
#include <vector>							//Might use this lib, not entirely sure yet
#include <string>							//Realms have string values, so this is needed
#include <set>								//Used for finding the Increasing Order of Set

using namespace std;

//Creating the Directed Graph Structure

struct Vertex {
	string value;
	int *powers;							//Add the largest Subset in Increasing Order
};

struct Edge{
	Vertex *source;
	Vertex *destination;
	int weight;
};

//Class structure of Graph

class Graph{
private:


public:
	Graph();
	~Graph();
	void Dijkstras();

};

Graph::Graph(){
	//Setting up Graph Data Structure
}

Graph::~Graph(){
	//Destruct the Structure
}

void Graph::Dijkstras(){
	//Implementing Dijkstras Algorithm
}

















