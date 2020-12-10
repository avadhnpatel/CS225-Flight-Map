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
#include "catch/catch.hpp"
#include "edge.h"
#include "parse.h"
#include "dijkstra.h"
using namespace std;

TEST_CASE("fastestWithNoStops"){
    Graph flightMap(true, true);
    map<string, Airports> airportData;
    map<string, string> airportRoutes;
    map<string, string> airportNames;

    ifstream routes;
    ifstream airnames;

    routes.open("routes.dat");
    airnames.open("airports.dat");
    Parsing testTwo;
    testTwo.parseAirports(airnames, airportData, airportNames, flightMap);
    testTwo.parseRoutes(routes, airportData, airportNames, flightMap);
    Dijkstra testDijk;
    SECTION("Base cases work") {
        vector<Vertex> path = testDijk.dijkstra(flightMap, "Aspen-Pitkin Co/Sardy Field", "Denver International Airport");
        // for (int i = 0; i < path.size(); i++) {
        //     cout << path.at(i) << endl;
        // }
        vector<Vertex> actual{"Aspen-Pitkin Co/Sardy Field", "Denver International Airport"};
        for (int i = 0; i < path.size(); i++) {
            REQUIRE(path[i]==actual[i]);
        }
    }
}

TEST_CASE("fastestWithOneStop"){
    Graph flightMap(true, true);
    map<string, Airports> airportData;
    map<string, string> airportRoutes;
    map<string, string> airportNames;

    ifstream routes;
    ifstream airnames;

    routes.open("routes.dat");
    airnames.open("airports.dat");
    Parsing testTwo;
    testTwo.parseAirports(airnames, airportData, airportNames, flightMap);
    testTwo.parseRoutes(routes, airportData, airportNames, flightMap);
    Dijkstra testDijk;
    SECTION("Base cases work") {
        vector<Vertex> path = testDijk.dijkstra(flightMap, "University of Illinois Willard Airport", "Newark Liberty International Airport");
        // for (int i = 0; i < path.size(); i++) {
        //     cout << path.at(i) << endl;
        // }
        vector<Vertex> actual{"University of Illinois Willard Airport", "Chicago O'Hare International Airport", "Newark Liberty International Airport"};
        for (int i = 0; i < path.size(); i++) {
            REQUIRE(path[i]==actual[i]);
        }
    }
}

TEST_CASE("fastestWithTwoStops"){
    Graph flightMap(true, true);
    map<string, Airports> airportData;
    map<string, string> airportRoutes;
    map<string, string> airportNames;

    ifstream routes;
    ifstream airnames;

    routes.open("routes.dat");
    airnames.open("airports.dat");
    Parsing testTwo;
    testTwo.parseAirports(airnames, airportData, airportNames, flightMap);
    testTwo.parseRoutes(routes, airportData, airportNames, flightMap);
    Dijkstra testDijk;
    SECTION("Base cases work") {
        vector<Vertex> path = testDijk.dijkstra(flightMap, "La Guardia Airport", "Brisbane International Airport");
        // for (int i = 0; i < path.size(); i++) {
        //     cout << path.at(i) << endl;
        // }
        vector<Vertex> actual{"La Guardia Airport", "Kansas City International Airport", "Los Angeles International Airport", "Brisbane International Airport"};
        for (int i = 0; i < path.size(); i++) {
            REQUIRE(path[i]==actual[i]);
        }
    }
}

TEST_CASE("LandmarkWithNoStops"){
    Graph flightMap(true, true);
    map<string, Airports> airportData;
    map<string, string> airportRoutes;
    map<string, string> airportNames;

    ifstream routes;
    ifstream airnames;

    routes.open("routes.dat");
    airnames.open("airports.dat");
    Parsing testTwo;
    testTwo.parseAirports(airnames, airportData, airportNames, flightMap);
    testTwo.parseRoutes(routes, airportData, airportNames, flightMap);
    Dijkstra testDijk;
    SECTION("Base cases work") {
        vector<Vertex> path = testDijk.landmarkPath(flightMap, "John F Kennedy International Airport", "Chicago O'Hare International Airport", "Los Angeles International Airport");
        // for (int i = 0; i < path.size(); i++) {
        //     cout << path.at(i) << endl;
        // }
        vector<Vertex> actual{"John F Kennedy International Airport", "Chicago O'Hare International Airport", "Los Angeles International Airport"};
        for (int i = 0; i < path.size(); i++) {
            REQUIRE(path[i]==actual[i]);
        }
    }
}

TEST_CASE("LandmarkWithOneStop"){
    Graph flightMap(true, true);
    map<string, Airports> airportData;
    map<string, string> airportRoutes;
    map<string, string> airportNames;

    ifstream routes;
    ifstream airnames;

    routes.open("routes.dat");
    airnames.open("airports.dat");
    Parsing testTwo;
    testTwo.parseAirports(airnames, airportData, airportNames, flightMap);
    testTwo.parseRoutes(routes, airportData, airportNames, flightMap);
    Dijkstra testDijk;
    SECTION("Base cases work") {
        vector<Vertex> path = testDijk.landmarkPath(flightMap, "University of Illinois Willard Airport", "Dublin Airport", "Newark Liberty International Airport");
        // for (int i = 0; i < path.size(); i++) {
        //     cout << path.at(i) << endl;
        // }
        vector<Vertex> actual{"University of Illinois Willard Airport", "Chicago O'Hare International Airport", "Dublin Airport", "Newark Liberty International Airport"};
        for (int i = 0; i < path.size(); i++) {
            REQUIRE(path[i]==actual[i]);
        }
    }
}

TEST_CASE("LandmarkWithALotOfStop"){
    Graph flightMap(true, true);
    map<string, Airports> airportData;
    map<string, string> airportRoutes;
    map<string, string> airportNames;

    ifstream routes;
    ifstream airnames;

    routes.open("routes.dat");
    airnames.open("airports.dat");
    Parsing testTwo;
    testTwo.parseAirports(airnames, airportData, airportNames, flightMap);
    testTwo.parseRoutes(routes, airportData, airportNames, flightMap);
    Dijkstra testDijk;
    SECTION("Base cases work") {
        vector<Vertex> path = testDijk.landmarkPath(flightMap, "University of Illinois Willard Airport", "Brisbane International Airport", "La Guardia Airport");
        // for (int i = 0; i < path.size(); i++) {
        //     cout << path.at(i) << endl;
        // }
        vector<Vertex> actual{"University of Illinois Willard Airport", "Dallas Fort Worth International Airport", "Brisbane International Airport", "Los Angeles International Airport", "Kansas City International Airport", "La Guardia Airport"};
        for (int i = 0; i < path.size(); i++) {
            REQUIRE(path[i]==actual[i]);
        }
    }
}

TEST_CASE("LandmarkWithActualImplication"){
    Graph flightMap(true, true);
    map<string, Airports> airportData;
    map<string, string> airportRoutes;
    map<string, string> airportNames;

    ifstream routes;
    ifstream airnames;

    routes.open("routes.dat");
    airnames.open("airports.dat");
    Parsing testTwo;
    testTwo.parseAirports(airnames, airportData, airportNames, flightMap);
    testTwo.parseRoutes(routes, airportData, airportNames, flightMap);
    Dijkstra testDijk;
    SECTION("Base cases work") {
        vector<Vertex> path = testDijk.landmarkPath(flightMap, "Chicago Midway International Airport", "John F Kennedy International Airport", "London Heathrow Airport");
        // for (int i = 0; i < path.size(); i++) {
        //     cout << path.at(i) << endl;
        // }
        vector<Vertex> actual{"Chicago Midway International Airport", "Cleveland Hopkins International Airport", "John F Kennedy International Airport", "London Heathrow Airport"};
        for (int i = 0; i < path.size(); i++) {
            REQUIRE(path[i]==actual[i]);
        }
    }
}