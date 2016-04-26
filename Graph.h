#include <iostream>               //Definitely need
#include <vector>               //Might use this lib, not entirely sure yet
#include <string>               //Realms have string values, so this is needed
#include <set>                  //Used for finding the Increasing Order of Set



using namespace std;

//Creating the Directed Graph Structure

struct Vertex;

struct Edge {
  Vertex *destination;
  int weight;
};

struct Vertex {
  string value;
  int *powers;                //Holds the set of magi
  Edge *edges;
  
  public:
  friend bool operator== (const Vertex &v1, const Vertex &v2);
  friend bool operator!= (const Vertex &v1, const Vertex &v2);
};

bool operator== (const Vertex &v1, const Vertex &v2) {
  return v1.value == v2.value;
}

bool operator!= (Vertex &v1, Vertex &v2) {
  return v1.value != v2.value;
}


//Class structure of Graph

class Graph{
private:
  Vertex **realms;
  int realmsCount;

public:
  Graph(int size);
  ~Graph();
  string getRealmVal(int index);
  void addRealm(int i, string val, int pows[]);
  int min(int a, int b);            //edit distance
  int diff(char a, char b);         //edit distance
  int minChanges(string str1, string str2); //edit distance
  void checkSubset(int* array);       
  void addEdge();
  void Dijkstras();
  void generateEdges();
  Vertex *vertexNamed(string name);
};

// Find realm by name
Vertex *Graph::vertexNamed(string name) {
  for (int i = 0; i < realmsCount; i++) {
    if (realms[i]->value == name) {
      return realms[i];
    }
  }
  return nullptr;
}


// Generates all edges between all vertices
void Graph::generateEdges() {
  if (realmsCount < 1) {
    return;
  }
  
  for (int i = 0; i < realmsCount; i++) {
    realms[i]->edges = new Edge[realmsCount - 1];
    int k = 0;

    for (int j = 0; j < realmsCount; j++) {
      
      if (realms[i] != realms[j]) {
        Edge edge = Edge();
        edge.destination = realms[j];
        edge.weight = minChanges(realms[i]->value, realms[j]->value);
        realms[i]->edges[k] = edge;
        k++;
      }
    }
  }
}

Graph::Graph(int size){
  //Setting up Graph Data Structure
  this->realmsCount = size;
  realms = new Vertex*[size];
}

Graph::~Graph(){
  delete realms;
}

//Function used to have access to Private Variables
//AKA getter method
string Graph::getRealmVal(int index){
  return realms[index]->value;
}

void Graph::addRealm(int i, string val, int pows[]){
  Vertex *realm = new Vertex();
  realm->value = val;
  realm->powers = pows;
  realms[i] = realm;
}

int Graph::min(int a,int b) {
   return ((a < b) ? a : b);
}

int Graph::diff(char a, char b) {
  //if characters not same, return 1 to add to minimum # changes needed
  return ((a == b) ? 0 : 1);
}

//Edit Distance Algorithm
int Graph::minChanges(string str1, string str2) {
  
  int s1 = str1.length();
  int s2 = str2.length();

  //edit distance table to compute minimum # of changes
  int table[s1+1][s2+1];
 
  for (int i = 0; i < s1+1; i++) {        // 0 1 2 3 4 5
    table[i][0] = i;                      // 1 - - - - -
  }                                       // 2 - - - - -  table is dynamic according to charms' string
                                          // 3 - - - - -  where a = answer
  for (int i = 1; i < s2+1; i++) {        // 4 - - - - -
    table[0][i] = i;                      // 5 - - - - a
  }
 
  for (int i = 1; i < s1+1; i++) {
    for (int j = 1; j < s2+1; j++) {
      int less = min(table[i-1][j], table[i][j-1]) + 1;
      table[i][j] = min(less, table[i-1][j-1] + diff(str1[i-1], str2[j-1]));
    }
  }
  
  //minimum number of changes need to go from str1 to str2
  cout << str1 << " " << str2 << " = " << table[s1][s2] << endl;

  return table[s1][s2];
}

void Graph::checkSubset(int* array) {
  // We want to check if we can go straight from start to destination(this would be shortest path),
  // (start's minChanges to go form itself to desitantion's string MUST be <= largestSubset)
  // if not, then we go check if possible to go to all other realms

  /*
    minChanges = minimum # changes needed to go from one Real's string to another's
    if(minChanges > largestSubset[Realm])
      cant move to this Realm
    else if (minChanges <= largestSubset[Realm])
      can move to this Realm
  */
}


void Graph::Dijkstras(){
//Implementing Dijkstras Algorithm
//Got the algorithm from the internet need to change, when Edit Distance is done
//Have to get the Edges from all of the Vertices on the Graph
  // int n = adj.size();
  // vector<int> dist(n);
  // vector<bool> vis(n);

  // for(int i = 0; i < n; ++i) {
  //  dist[i] = INFINITY;
  // }
  // dist[src] = 0;

  // for(int i = 0; i < n; ++i) {
  //  int cur = -1;
  //  for(int j = 0; j < n; ++j) {
  //    if (vis[j]) {
  //        continue;
  //    }
  //    if (cur == -1 || dist[j] < dist[cur]) {
  //      cur = j;
  //    }
  //  }

  //  vis[cur] = true;
    
  //  for(int j = 0; j < n; ++j) {
  //    int path = dist[cur] + adj[cur][j];
  //    if (path < dist[j]) {
  //      dist[j] = path;
  //    }
  //  }
  // }

  // return dist[dest];
}












