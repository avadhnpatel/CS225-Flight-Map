#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <map>
#include <vector>
#include <stdio.h>
#include <string.h>

using namespace std;

int main(int argc, char *argv[]){
    ifstream routes;
    ifstream airports;

    routes.open("test.dat");
    airports.open("airports.dat");
    parseRoutes(routes);
    parseAirports(airports);

    
    return 0;
}

void parseRoutes(ifstream &routes){
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
        cout << srcAirportID << "  "<< destAirportID << "  ";
    }
}

void parseAirports(ifstream &routes){
    vector<string> result;
    string line;
    string longitude;
    string latitude;
    while(getline(routes, line)){
        result.clear();
        stringstream ss(line);
        while(getline(ss, line, ',')){
            result.push_back(line);
        }
        longitude = result[6];
        latitude = result[7];
        //cout << longitude << "  "<< latitude << "  ";
    }
}
