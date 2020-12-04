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
void parseRoutes(ifstream &routes, map<string,string> &airportRoutes){
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

        
        // cout << srcAirportID << "  "<< destAirportID << "  ";
    }
}

void parseAirports(ifstream &airnames, map<string, Airports> &airportData){
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

        
        airportData[airportName] = newport;
        //cout << longitude << "  "<< latitude << "  ";
    }
}


int main(int argc, char *argv[]){

    map<string, Airports> airportData;
    map<string, string> airportRoutes;


    ifstream routes;
    ifstream airnames;

    routes.open("test.dat");
    airnames.open("airports.dat");
    parseAirports(airnames, airportData);
    parseRoutes(routes, airportRoutes);

    
    return 0;
}

// void parseRoutes(ifstream &routes, map<string,string> &airportRoutes){
//     vector<string> result;
//     string line;
//     string srcAirportID;
//     string destAirportID;
//     while(getline(routes, line)){
//         result.clear();
//         stringstream ss(line);
//         while(getline(ss, line, ',')){
//             result.push_back(line);
//         }
//         srcAirportID = result[2];
//         destAirportID = result[4];

        
//         // cout << srcAirportID << "  "<< destAirportID << "  ";
//     }
// }

// void parseAirports(ifstream &airnames, map<string, Airports> &airportData){
//     vector<string> result;
//     string line;
//     string longitude;
//     string latitude;
//     string airportName;
//     string iata;
//     Airports newport;
//     while(getline(airnames, line)){
//         result.clear();
//         stringstream ss(line);
//         while(getline(ss, line, ',')){
//             result.push_back(line);
//         }
//         longitude = result[6];
//         latitude = result[7];
//         airportName = result[1];
//         iata = result[4];
//         newport.longitude = longitude;
//         newport.latitude = latitude;
//         newport.airportName = airportName;
//         newport.iata = iata;

        
//         airportData[airportName] = newport;
//         //cout << longitude << "  "<< latitude << "  ";
//     }
// }
