#include <iostream>							//Definitely need
#include <vector>							//Might use this lib, not entirely sure yet
#include <string>							//Realms have string values, so this is needed
#include <set>								//Used for finding the Increasing Order of Set

using namespace std;

//Creating the Directed Graph Structure

struct Vertex {
	string value;
	int *powers;							//Holds the set of magi
	//int *sub;  							//largest subset of increasing numbers
};

//Class structure of Graph

class Graph{
private:
	Vertex *realms;

public:
	Graph(int size);
	~Graph();
	void addRealm(int src, string val, int pows[]);
	int min(int a, int b);
	int diff(char a, char b);
	void minChanges(string str1, string str2);	//edit distance
	void checkSubset(int* array);
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

int Graph::min(int a,int b) {
   return ((a < b) ? a : b);
}

int Graph::diff(char a, char b) {
  //if characters not same, return 1 to add to minimum # changes needed
  return ((a == b) ? 0 : 1);
}

int Graph::minChanges(string str1, string str2) {
  int s1 = str1.length();
  int s2 = str2.length();

  //edit distance table to compute minimum # of changes
  int table[s1+1][s2+1];
 
  for (int i = 0; i < s1+1; i++) {        // 0 1 2 3 4 5
    table[i][0] = i;                      // 1
  }                                       // 2
                                          // 3
  for (int i = 1; i < s2+1; i++) {        // 4
    table[0][i] = i;                      // 5
  }
 
  for (int i = 1; i < s1+1; i++) {
    for (int j = 1; j < s2+1; j++) {
      int less = min(table[i-1][j], table[i][j-1]) + 1;
      table[i][j] = min(less, table[i-1][j-1] + diff(str1[i-1], str2[j-1]));
    }
  }
  
  //minimum number of changes need to go from str1 to str2
  return table[s1][s2];
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











