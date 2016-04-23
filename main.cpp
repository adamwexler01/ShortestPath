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


class Realm {
private:
  std::string charm;
  int magiPowers;
public:
};





int main(int argc, const char * argv[]) {
  
  std::string charmStart, charmDest;
  int n;
  
  // Read number of realms
  std::cin >> n;
  
  for (int i = 0; i < n; i++) {
    
    std::string charm;
    int magiCount;
    
    // Read charm and count
    std::cin >> charm;
    std::cin >> magiCount;
    
    
    // Read power for each magi
    int magiPowers[magiCount];
    
    for (int j = 0; j < magiCount; j++) {
      std::cin >> magiPowers[j];
    }
  }
  
  // Read start and destination charms
  std::cin >> charmStart;
  std::cin >> charmDest;
  
  
  
  return 0;
}

/*
 4
 sitting
 6
 121324
 knitting
 4
 4231
 knowing
 5
 23142
 kneeding
 4
 1342
 sitting
 kneeding
 
*/

