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
#include "dijkstra.h"


class BFS{
    public:
        BFS (const Graph &flightMap);
        vector<Vertex> BFSearch(const Vertex &v);
    private:
        Graph flightMap_;
};