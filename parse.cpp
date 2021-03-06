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
#include "parse.h"
#include "dijkstra.h"
#include "BFS.h"
#include <algorithm>

using namespace std;
void Parsing::parseAirports(ifstream &airnames, map<string, Airports> &airportData, map<string, string> &airportNames, Graph &flightMap){
    vector<string> result;
    string line;
    string strlongitude;
    string strlatitude;
    string airportName;
    string iata;
    Airports newport;
    while(getline(airnames, line)){ //makes sure that a text line exists
        result.clear();
        stringstream ss(line); //gets line
        while(getline(ss, line, ',')){ //parses through using a comma to seperate
            result.push_back(line);
        }
        iata = result[4];
        if(iata != "\"N/A\""){ //helps to ensure that an iata actually exists for the airport
            strlongitude = result[7]; //7,6,1 are the respective indices that stored the longtidue, latitude, and airport name
            strlatitude = result[6];
            airportName = result[1];

            iata.erase(0, 1); //these 4 lines gets ride of quotation marks
            iata.erase(iata.size() - 1);
            airportName.erase(0, 1);
            airportName.erase(airportName.size() - 1);

            newport.longitude = atof(strlongitude.c_str());
            newport.latitude = atof(strlatitude.c_str());
            newport.airportName = airportName;
            newport.iata = iata;

            airportNames[iata] = airportName;   //maps iata to airport name
            airportData[airportName] = newport; //maps airport name to airport object
            if(!flightMap.vertexExists(airportName)){
                flightMap.insertVertex(airportName);
            }
        }
    }
}
void Parsing::parseRoutes(ifstream &routes, map<string,Airports> &airportData, map<string, string> &airportNames, Graph &flightMap){
    vector<string> result;
    string line;
    string srcAirportIATA;
    string destAirportIATA;
    while(getline(routes, line)){
        result.clear();
        stringstream ss(line);
        while(getline(ss, line, ',')){ //parses through using commas to seperate
            result.push_back(line);
        }
        srcAirportIATA = result[2];
        destAirportIATA = result[4];
        double srclong = airportData[airportNames[srcAirportIATA]].longitude;
        double srclat = airportData[airportNames[srcAirportIATA]].latitude;

        double destlong = airportData[airportNames[destAirportIATA]].longitude;
        double destlat = airportData[airportNames[destAirportIATA]].latitude;
        double distance = findDist(srclong, srclat, destlong, destlat);
        
        
        flightMap.insertEdge(airportNames[srcAirportIATA], airportNames[destAirportIATA]);
        flightMap.setEdgeWeight(airportNames[srcAirportIATA], airportNames[destAirportIATA], distance);
        flightMap.setEdgeLabel(airportNames[srcAirportIATA], airportNames[destAirportIATA], srcAirportIATA + " - " + destAirportIATA);
    }
}

double Parsing::findDist(double srclong, double srclat, double destlong, double destlat){
    long double one_deg = (M_PI) / 180; //converts pi from radians to degrees
    double lat2 = destlat * one_deg;  //all 4 lines convert longitude and latitude from degrees to radians
    double long2 = destlong * one_deg; 
    double lat1 = srclat * one_deg; 
    double long1 = srclong * one_deg; 
    long double dlong = long2 - long1;  //haversine formula
    long double dlat = lat2 - lat1; 
    long double ans = pow(sin(dlat / 2), 2) +  cos(lat1) * cos(lat2) *  pow(sin(dlong / 2), 2); 
    ans = 2 * asin(sqrt(ans)); 
    long double R = 3956; //earths radius in miles 
    ans = ans * R; 
    return ans;
}

