//
//  main.cpp
//  Project2
//
//  Created by Ian MacCallum on 4/17/16.
//  Copyright © 2016 Ian MacCallum. All rights reserved.
//
#include <iostream>
#include <vector>
#include <string>
#include "Graph.h"

using namespace std;

int main(int argc, const char * argv[]) {
  
  string charmStart, charmDest;
  int n;
  Graph *graph;
  
  //  Read number of realms and creating Graph
  cin >> n;
  graph = new Graph(n);
  
  for (int i = 0; i < n; i++) {
    string charm;
    int magiCount;
    
    //  Read charm and count
    cin >> charm;
    cin >> magiCount;
    
    //  Read power for each magi
    vector<int> magiPowers;
    
    for (int j = 0; j < magiCount; j++) {
      int temp;
      cin >> temp;
      magiPowers.push_back(temp);
    }
    
    // Add individual realms(vertices)
    graph->addRealm(i, charm, magiPowers);
  }
  
  // Read start and destination charms
  cin >> charmStart;
  cin >> charmDest;
  
  // Generate all edges
  graph->generateEdges();
  
  
  // Find source/destination realms
  Vertex *source = graph->vertexNamed(charmStart);
  Vertex *destination = graph->vertexNamed(charmDest);
  
  // Perform traversal
  graph->Dijkstras(source, destination);
  graph->resetRealms();
  graph->Dijkstras(destination, source);
  
  return 0;
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



