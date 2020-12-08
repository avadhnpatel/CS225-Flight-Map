#pragma once
#include <list>
#include <unordered_map>
#include <utility>
#include <algorithm>
#include <string>
#include <cstdlib>
#include <climits>
#include <fstream>
#include <iostream>
#include <iomanip>
#include <set>
#include <sstream>
#include <vector>

#include "graph.h"
#include "edge.h"

using namespace std;

class Dijkstra{
    public:
        vector<Vertex> dijkstra(Graph flightMap, Vertex srcAirport, Vertex destAirport);
        vector<Vertex> landmarkPath(Graph flightMap, Vertex srcAirport, Vertex middleAirport, Vertex dstAirport);
};

    

