#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <map>
#include <vector>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include "graph.h"
#include <cstdlib>

using namespace std;

void parseAirports(ifstream &airnames, map<string, Airports> &airportData, map<string, string> &airportNames);
void parseRoutes(ifstream &routes, map<string,Airports> &airportData, map<string, string> &airportNames);
double findDist(double srclong, double srclat, double destlong, double destlat);

int main(int argc, char *argv[]){

    map<string, Airports> airportData;
    map<string, string> airportRoutes;
    map<string, string> airportNames;


    ifstream routes;
    ifstream airnames;

    routes.open("testR.dat");
    airnames.open("airports.dat");
    parseAirports(airnames, airportData, airportNames);
    parseRoutes(routes, airportData, airportNames);

    
    return 0;
}

void parseAirports(ifstream &airnames, map<string, Airports> &airportData, map<string, string> &airportNames){
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
        if(iata != "\"N/A\""){
            strlongitude = result[6];
            strlatitude = result[7];
            airportName = result[1];
            iata = result[4];

            iata.erase(0, 1);
            iata.erase(iata.size() - 1);
            airportName.erase(0, 1);
            airportName.erase(airportName.size() - 1);

            newport.longitude = stod(strlongitude);
            newport.latitude = stod(strlatitude);
            newport.airportName = airportName;
            newport.iata = iata;

            airportNames[iata] = airportName;   
            airportData[airportName] = newport;
        }
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
        double srclong = airportData[airportNames[srcAirportID]].longitude;
        double srclat = airportData[airportNames[srcAirportID]].latitude;

        double destlong = airportData[airportNames[destAirportID]].longitude;
        double destlat = airportData[airportNames[destAirportID]].latitude;
        double distance = findDist(srclong, srclat, destlong, destlat);

        cout << srcAirportID << "  "<< destAirportID << "  " << distance;
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
    long double R = 6371; 
      
    // Calculate the result 
    ans = ans * R; 
  
    return ans;
}

