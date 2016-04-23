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

int min(int a,int b) {
   return ((a < b) ? a : b);
}

int diff(char a, char b) {
  //if characters not same, return 1 to add to minimum # changes needed
  return ((a == b) ? 0 : 1);
}

int minChanges(string str1, string str2) {
  int s1 = str1.length();
  int s2 = str2.length();

  //edit distance table to compute minimum # of changes
  int table[s1+1][s2+1];
 
  for (int i = 0; i < s1+1; i++) {        // 0 1 2 3 4 5
    table[i][0] = i;                          // 1
  }                                       // 2
                                          // 3
  for (int i = 1; i < s2+1; i++) {        // 4
    table[0][i] = i;                          // 5
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
 
 4 florida
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

