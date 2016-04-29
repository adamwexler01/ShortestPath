#include <iostream>             //Definitely need
#include <vector>               //Might use this lib, not entirely sure yet
#include <string>               //Realms have string values, so this is needed
#include <set>                  //Used for finding the Increasing Order of Set
#include <cmath>
#include <climits>
#include <list>

using namespace std;

struct Vertex;


//Initializes the Edge Structure
struct Edge {
  Vertex *destination;
  int weight;
};


//Constructs Vertex Structure
struct Vertex {
  int minDistance, minGems;
  string value;
  vector<int> powers;
  vector<Edge> edges;
  
  friend bool operator== (const Vertex &v1, const Vertex &v2);
  friend bool operator!= (const Vertex &v1, const Vertex &v2);
  vector<int> checkSubset();
};

//Checks whether the Vertices are equal in value
bool operator== (const Vertex &v1, const Vertex &v2) {
  return v1.value == v2.value;
}

//Checks whether Vertices are not equal

bool operator!= (Vertex &v1, Vertex &v2) {
  return v1.value != v2.value;
}

//Finds the largest increasing subset of Magi
vector<int> Vertex::checkSubset() {
  
  vector<vector<int>> results = vector<vector<int>>();
  
  int smallestIndex = INT_MAX;
  
  for (int i = 0; i < powers.size(); i++) {
    
    if (powers[i] < smallestIndex) {
      
      // Create new array
      smallestIndex = powers[i];
      vector<int> temp = { powers[i] };
      results.push_back(temp);
    } else if (powers[i] > smallestIndex) {
      
      // Add value to every array if its greater than the max index
      
      for(int j = 0; j < results.size(); j++) {
        
        if (powers[i] > results[j].back()) {
          
          results[j].push_back(powers[i]);
        }
      }
    }
  }
  
  
  int maxIndex = -1;
  int maxSize = 0;
  int maxSum = INT_MAX;
  
  
  for (int i = 0; i < results.size(); i++) {
    
    if (results[i].size() > maxSize) {
      maxIndex = i;
      maxSize = (int)results[i].size();
    } else if (results[i].size() == maxSize) {
      // Find lower gem count
      
      int tempSum = 0;
      
      for (int n : results[maxIndex]) tempSum += n;
      
      if (tempSum < maxSum) {
        maxIndex = i;
        maxSize = (int)results[i].size();
        maxSum = tempSum;
      }
    }
  }
  
  if (maxIndex == -1) {
    return {};
  } else {
    return results[maxIndex];
  }
}

//Class structure of Graph
class Graph{
private:
  vector<Vertex*> realms;
  int realmsCount;
  
public:
  Graph(int size);                                                        //Constructor of the Graph Class
  Vertex *vertexNamed(string name);
  void generateEdges();                                                   //Creates Edges of Graph
  void resetRealms();                                                     //Used to flush Values stored in the Pointers
  
  string getRealmVal(int index);
  void addRealm(int i, string val, vector<int> powers);                   //Helper to create the Graph Structure
  int minChanges(string str1, string str2);                               //edit distance
  void Dijkstras(Vertex *source, Vertex *destination);                    //Traversal function
  
};

Graph::Graph(int size) {
  //Setting up Graph Data Structure
  this->realmsCount = size;
  this->realms = vector<Vertex*>();
}

// Find realm by name
Vertex *Graph::vertexNamed(string name) {
  //Initializes an iterator to cycle through the vertices
  vector<Vertex*>::iterator i;
  for(i = realms.begin(); i < realms.end(); i++ ) {
    if ((*i)->value == name) {
      return *i;
    }
  }
  return NULL;
}


// Generates all edges between all vertices
void Graph::generateEdges() {
  //Checks if tranversal is possible
  if (realmsCount < 1) {
    return;
  }
  
  for (int i = 0; i < realmsCount; i++) {
    
    int k = 0;
    
    for (int j = 0; j < realmsCount; j++) {
      //Gets the weight using edit distance algorithm
      int weight = minChanges(realms[i]->value, realms[j]->value);
      
      if (realms[i] != realms[j] && realms[i]->checkSubset().size() >= weight) {
        Edge edge = Edge();
        edge.destination = realms[j];
        edge.weight = weight;
        realms[i]->edges.push_back(edge);
        k++;
      }
    }
  }
}

void Graph::addRealm(int i, string val, vector<int> powers) {
  //Initializes the properties of the Realm
  Vertex *realm = new Vertex();
  realm->edges = vector<Edge>();
  realm->minDistance = INT_MAX;                                       //Uses INT_MAX to fix the possible paths for the traversal
  realm->value = val;
  realm->powers = powers;
  realms.push_back(realm);
}

void Graph::resetRealms() {
  
  vector<Vertex*>::iterator i;  // declare an iterator to a vector of strings
  for(i = realms.begin(); i < realms.end(); i++ ) {
    Vertex *realm = *i;
    realm->minDistance = INT_MAX;
    realm->minGems = 0;
  }
}


//Edit Distance Algorithm
int Graph::minChanges(string str1, string str2) {
  int s1 = (int)str1.length();
  int s2 = (int)str2.length();
  
  //edit distance table to compute minimum # of changes
  int table[s1+1][s2+1];
  for (int i = 0; i < s1+1; i++) {
    table[i][0] = i;
  }
  
  for (int i = 1; i < s2+1; i++) {
    table[0][i] = i;
  }
  
  for (int i = 1; i < s1+1; i++) {
    for (int j = 1; j < s2+1; j++) {
      int less = min(table[i-1][j], table[i][j-1]) + 1;
      table[i][j] = min(less, table[i-1][j-1] + ((str1[i-1] == str2[j-1]) ? 0 : 1));
    }
  }
  
  //minimum number of changes need to go from str1 to str2
  return table[s1][s2];
}

void Graph::Dijkstras(Vertex *source, Vertex *destination) {
  
  list<Vertex*> q = list<Vertex*>();
  source->minDistance = 0;
  source->minGems = 0;
  q.push_back(source);
  
  while (!q.empty()) {
    Vertex *currentVertex = q.front();
    q.pop_front();
    vector<int> subset = currentVertex->checkSubset();
    int subsetSum = 0;
    for (int n : subset) subsetSum += n;
    
    for (int i = 0; i < currentVertex->edges.size(); i++) {
      
      // Visit adjacent vertices
      Edge edge = currentVertex->edges[i];
      Vertex* adjacentVertex = edge.destination;
      
      if (subset.size() >= edge.weight) {
        
        if (currentVertex->minDistance + edge.weight < adjacentVertex->minDistance) {
          
          // Take path & update minDistance
          adjacentVertex->minDistance = currentVertex->minDistance + edge.weight;
          
          adjacentVertex->minGems = currentVertex->minGems + subsetSum;
          q.push_back(adjacentVertex);
          
        }
      }
    }
  }
  
  if (destination->minDistance == INT_MAX) {
    cout << "IMPOSSIBLE" << endl;
  } else {
    cout << destination->minDistance << " " << destination->minGems << endl;
  }
  
}


/*
 4
 sitting
 6
 1 2 1 3 2 4
 knitting
 4
 4 2 3 1
 knowing
 5
 2 3 1 4 2
 kneeding
 4
 1 3 4 2
 sitting
 kneeding
 
 */









