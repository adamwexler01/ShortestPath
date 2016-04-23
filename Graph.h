#include <iostream>							//Definitely need
#include <vector>							//Might use this lib, not entirely sure yet
#include <string>							//Realms have string values, so this is needed
#include <set>								//Used for finding the Increasing Order of Set

using namespace std;

//Creating the Directed Graph Structure

struct Vertex {
	string value;
	int *powers;							//Holds the set of magi
};

//Class structure of Graph

class Graph{
private:
	Vertex *realms;

public:
	Graph(int size);
	~Graph();
	void addRealm(int src, string val, int pows[]);
	void addEdge();
	void Dijkstras();
};

Graph::Graph(int size){
	//Setting up Graph Data Structure
	
	realms = new Vertex[size];

}

Graph::~Graph(){
	//Destruct the Structure
	delete realms;
}

void Graph::addRealm(int src, string val, int pows[]){
	realms[src].value = val;
	realms[src].powers = pows;
}


void Graph::Dijkstras(){
	//Implementing Dijkstras Algorithm
}




//Might not be used because Edit Distance covers that
//
// struct Edge{
// 	Vertex *source;
// 	Vertex *destination;
// 	int weight;
// };











