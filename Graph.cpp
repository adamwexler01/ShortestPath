#include <iostream>
#include <vector>

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

}

void Graph::Dijkstras(){

}

int main(int argc, char *argv[]){



	return 0;

}




















