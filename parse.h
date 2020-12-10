#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <map>
#include <vector>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <cstdlib>
#include <list>
#include "graph.h"
#include "edge.h"
#include "dijkstra.h"
#include "BFS.h"
#include <algorithm>

using namespace std;
class Parsing{
    public: 
        void parseAirports(ifstream &airnames, map<string, Airports> &airportData, map<string, string> &airportNames, Graph &flightMap);
        void parseRoutes(ifstream &routes, map<string,Airports> &airportData, map<string, string> &airportNames, Graph &flightMap);
        double findDist(double srclong, double srclat, double destlong, double destlat);
};