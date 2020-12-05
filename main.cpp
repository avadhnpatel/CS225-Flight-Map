#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <map>
#include <vector>
#include <stdio.h>
#include <string.h>
#include "graph.h"

using namespace std;

void parseAirports(ifstream &airnames, map<string, Airports> &airportData);
void parseRoutes(ifstream &routes, map<string,Airports> &airportData);

int main(int argc, char *argv[]){

    map<string, Airports> airportData;
    map<string, string> airportRoutes;
    map<string, string> airportNames;


    ifstream routes;
    ifstream airnames;

    routes.open("test.dat");
    airnames.open("airports.dat");
    parseAirports(airnames, airportData, airportNames);
    parseRoutes(routes, airportData, airportNames);

    
    return 0;
}

void parseAirports(ifstream &airnames, map<string, Airports> &airportData, map<string, string> &airportNames){
    vector<string> result;
    string line;
    string longitude;
    string latitude;
    string airportName;
    string iata;
    Airports newport;
    while(getline(airnames, line)){
        result.clear();
        stringstream ss(line);
        while(getline(ss, line, ',')){
            result.push_back(line);
        }
        longitude = result[6];
        latitude = result[7];
        airportName = result[1];
        iata = result[4];
        newport.longitude = longitude;
        newport.latitude = latitude;
        newport.airportName = airportName;
        newport.iata = iata;

        airportNames[iata] = airportName;
        airportData[airportName] = newport;
        //cout << longitude << "  "<< latitude << "  ";
    }
}
void parseRoutes(ifstream &routes, map<string,Airports> &airportData, map<string, string> &airportNames){
    vector<string> result;
    string line;
    string srcAirportID;
    string destAirportID;
    while(getline(routes, line)){
        result.clear();
        stringstream ss(line);
        while(getline(ss, line, ',')){
            result.push_back(line);
        }
        srcAirportID = result[2];
        destAirportID = result[4];
        double longitude =  airportData[airportNames[srcAirportID]].longitude;
        
        // cout << srcAirportID << "  "<< destAirportID << "  ";
    }
}
