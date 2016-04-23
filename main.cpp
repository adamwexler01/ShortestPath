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


class Realm {
private:
  string charm;
  int magiPowers;
public:
};


int main(int argc, const char * argv[]) {
  
  string charmStart, charmDest;
  int n;
  
  // Read number of realms
  cin >> n;
  string realms;
  
  for (int i = 0; i < n; i++) {
    string charm;
    int magiCount;
    
    // Read charm and count
    cin >> charm;
    cin >> magiCount;
    
    // Read power for each magi
    int magiPowers[magiCount];
    
    for (int j = 0; j < magiCount; j++) {
      cin >> magiPowers[j];
    }
  }
  
  // Read start and destination charms
  cin >> charmStart;
  cin >> charmDest;
  
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
 
 4
 florida
 7 4 3 2 1 2 3 4
 flower
 4 5 6 7 8
 collapse
 4 2 1 2 3
 teamer
 3 4 5 6
 teamer
 florida
*/

