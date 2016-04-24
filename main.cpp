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

	//	Read number of realms and creating Graph
	cin >> n;
	graph = new Graph(n);

	for (int i = 0; i < n; i++) {
		string charm;
		int magiCount;

		//	Read charm and count
		cin >> charm;
		cin >> magiCount;

		//	Read power for each magi
		int magiPowers[magiCount];

		for (int j = 0; j < magiCount; j++) {
			cin >> magiPowers[j];
		}

		//	Begin adding individual realms(vertices)
		graph->addRealm(i, charm, magiPowers);
	}

	// Read start and destination charms
	cin >> charmStart;
	cin >> charmDest;

	return 0;
}




