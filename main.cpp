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
#include <algorithm>

using namespace std;


void parseAirports(ifstream &airnames, map<string, Airports> &airportData, map<string, string> &airportNames, Graph &flightMap);
void parseRoutes(ifstream &routes, map<string,Airports> &airportData, map<string, string> &airportNames, Graph &flightMap);
double findDist(double srclong, double srclat, double destlong, double destlat);

int main(int argc, char *argv[]){

    (void)argv;
    (void)argc;

    Graph flightMap(true, true);

    map<string, Airports> airportData;
    map<string, string> airportRoutes;
    map<string, string> airportNames;

    ifstream routes;
    ifstream airnames;

    string src;
    string arrive;
    string land;

    routes.open("routes.dat");
    airnames.open("airports.dat");
    parseAirports(airnames, airportData, airportNames, flightMap);
    parseRoutes(routes, airportData, airportNames, flightMap);

    cout<< "Input \"Landmark\" for a connecting destination or \"Fastest\" for quickest path: ";
    getline(cin, land);
    while(land != "Landmark" && land != "Fastest"){
        cout << "Sorry this is not a valid entry. Please try again.\n";
        cout<< "Input \"Landmark\" for a connecting destination or \"Fastest\" for quickest path: ";
        getline(cin, land);
    }
    if(land == "Fastest"){

        cout << "Input your departing airport: ";
        getline(cin, src);

        while(airportData.count(src) < 1){
            cout << "Sorry this airport does not exist. Please input another one.\n ";
            cout << "Input your departing airport: ";
            getline(cin, src);
        }


        cout << "Input your arriving airport: ";
        getline(cin, arrive);
        while(airportData.count(arrive) < 1){
            cout << "Sorry this airport does not exist. Please input another one.\n";
            cout << "Input your arriving airport: ";
            getline(cin, arrive);
        }

        //flightMap.print();
        Dijkstra dijkstraTest;
        vector<Vertex> path = dijkstraTest.dijkstra(flightMap, src, arrive);
        vector<Vertex> rightOrder;
        unsigned long i = 0;
        unsigned long j = 1;
        reverse(path.begin(),path.end());

        while(i != path.size()){
            cout << path[0] << endl;
            i++;
        }

        

    }else if(land == "Landmark"){
            cout << "landmark algo";
           return 0; 
        }

    return 0;
}

void parseAirports(ifstream &airnames, map<string, Airports> &airportData, map<string, string> &airportNames, Graph &flightMap){
    vector<string> result;
    string line;
    string strlongitude;
    string strlatitude;
    string airportName;
    string iata;
    Airports newport;
    while(getline(airnames, line)){
        result.clear();
        stringstream ss(line);
        while(getline(ss, line, ',')){
            result.push_back(line);
        }
        iata = result[4];
        if(iata != "\"N/A\""){
            strlongitude = result[7];
            strlatitude = result[6];
            airportName = result[1];

            iata.erase(0, 1);
            iata.erase(iata.size() - 1);
            airportName.erase(0, 1);
            airportName.erase(airportName.size() - 1);

            newport.longitude = atof(strlongitude.c_str());
            newport.latitude = atof(strlatitude.c_str());
            newport.airportName = airportName;
            newport.iata = iata;

            airportNames[iata] = airportName;   
            airportData[airportName] = newport;
            if(!flightMap.vertexExists(airportName)){
                flightMap.insertVertex(airportName);
            }
        }
        //cout << longitude << "  "<< latitude << "  ";
    }
}
void parseRoutes(ifstream &routes, map<string,Airports> &airportData, map<string, string> &airportNames, Graph &flightMap){
    vector<string> result;
    string line;
    string srcAirportIATA;
    string destAirportIATA;
    while(getline(routes, line)){
        result.clear();
        stringstream ss(line);
        while(getline(ss, line, ',')){
            result.push_back(line);
        }
        srcAirportIATA = result[2];
        destAirportIATA = result[4];
        double srclong = airportData[airportNames[srcAirportIATA]].longitude;
        double srclat = airportData[airportNames[srcAirportIATA]].latitude;

        double destlong = airportData[airportNames[destAirportIATA]].longitude;
        double destlat = airportData[airportNames[destAirportIATA]].latitude;
        double distance = findDist(srclong, srclat, destlong, destlat);

        // if(!flightMap.vertexExists(srcAirportIATA)){
        //     flightMap.insertVertex(srcAirportIATA);
        // }
        // if(!flightMap.vertexExists(destAirportIATA)){
        //     flightMap.insertVertex(destAirportIATA);
        // }
        
        
        flightMap.insertEdge(airportNames[srcAirportIATA], airportNames[destAirportIATA]);
        flightMap.setEdgeWeight(airportNames[srcAirportIATA], airportNames[destAirportIATA], distance);
        flightMap.setEdgeLabel(airportNames[srcAirportIATA], airportNames[destAirportIATA], srcAirportIATA + " - " + destAirportIATA);
        //cout << srcAirportIATA << "  "<< destAirportIATA << "  " << distance << "\n";
    }
}

double findDist(double srclong, double srclat, double destlong, double destlat){
    long double one_deg = (M_PI) / 180; 

    // Convert the latitudes  
    // and longitudes 
    // from degree to radians. 
    double lat1 = srclat * one_deg;
    double long1 = srclong * one_deg; 
    double lat2 = destlat * one_deg; 
    double long2 = destlong * one_deg; 
      
    // Haversine Formula 
    long double dlong = long2 - long1; 
    long double dlat = lat2 - lat1; 
  
    long double ans = pow(sin(dlat / 2), 2) +  
                          cos(lat1) * cos(lat2) *  
                          pow(sin(dlong / 2), 2); 
  
    ans = 2 * asin(sqrt(ans)); 
  
    // Radius of Earth in  
    // Kilometers, R = 6371 
    // Use R = 3956 for miles 
    long double R = 3956; 
      
    // Calculate the result 
    ans = ans * R; 
  
    return ans;
}

