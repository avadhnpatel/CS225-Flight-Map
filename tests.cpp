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
using namespace std;

TEST_CASE("dijkstra"){
    Graph flightMap(true, true);
    map<string, Airports> airportData;
    map<string, string> airportRoutes;
    map<string, string> airportNames;

    ifstream routes;
    ifstream airnames;

    routes.open("routes.dat");
    airnames.open("airports.dat");
    parseAirports(airnames, airportData, airportNames, flightMap);
    parseRoutes(routes, airportData, airportNames, flightMap);
    //flightMap.print();

    SECTION("Base cases work") {
        bool isCorrect = true;
        vector<Vertex> path = dijkstra(flightMap, "Aspen-Pitkin Co/Sardy Field", "Denver International Airport");
        for (int i = 0; i < path.size(); i++) {
            cout << path.at(i) << endl;
        }
        vector<Vertex> actual{"Aspen-Pitkin Co/Sardy Field", "Denver International Airport"};
        for (int i = 0; i < path.size(); i++) {
            assert(path[i]==actual[i]);
        }
    }
}