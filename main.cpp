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
#include "BFS.h"
#include "parse.h"
#include <algorithm>

using namespace std;




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
    string mid;
    string arrive;
    string land;

    routes.open("routes.dat");  
    airnames.open("airports.dat");
    Parsing testOne;
    testOne.parseAirports(airnames, airportData, airportNames, flightMap); //parses through airports.dat
    testOne.parseRoutes(routes, airportData, airportNames, flightMap); //parses through routes.dat
    
    
    
    // Graph g(false, true);
    // g.insertEdge("0", "1");
    // g.insertEdge("0", "2");
    // g.insertEdge("1", "2");
    // g.insertEdge("2", "0");
    // g.insertEdge("2", "3");
    // g.insertEdge("3", "3");

    // BFS search(g);
    // vector<Vertex> BFSoutput = search.BFSearch("2");

    // for(size_t i = 0; i < BFSoutput.size(); i++){
    //     cout << BFSoutput[i] << endl;
    // }




    cout<< "Input \"Landmark\" for a connecting destination or \"Fastest\" for quickest path: "; //gets input for either landmark or fastest
    getline(cin, land);
    while(land != "Landmark" && land != "Fastest"){  //makes sure that input is valid
        if(land == "Gulag"){ //easter egg 
            cout<<"We agree that Roshun is useless! but for real give me an input\n";
            cout<< "Input \"Landmark\" for a connecting destination or \"Fastest\" for quickest path: ";
            getline(cin, land);
            continue; 
        }
        cout << "Sorry this is not a valid entry. Please try again.\n";
        cout<< "Input \"Landmark\" for a connecting destination or \"Fastest\" for quickest path: ";
        getline(cin, land);
    }
    if(land == "Fastest"){  

        cout << "Input your departing airport: ";
        getline(cin, src);
        if(src == "Hell"){ //easter egg
            src = "Newark Liberty International Airport";
        }
        if(src == "Home"){ //easter egg
            src = "University of Illinois Willard Airport";
        }
        while(airportData.count(src) < 1){ //makes sure that airport exists
            cout << "Sorry this airport does not exist. Please input another one.\n ";
            cout << "Input your departing airport: ";
            getline(cin, src);
        }


        cout << "Input your arriving airport: ";
        getline(cin, arrive);
        if(arrive == "Hell"){ //easter egg
            arrive = "Newark Liberty International Airport";
        }
        if(arrive == "Home"){ //easter egg
            arrive = "University of Illinois Willard Airport";
        }
        while(airportData.count(arrive) < 1){ //makes sure that airport exists
            cout << "Sorry this airport does not exist. Please input another one.\n";
            cout << "Input your arriving airport: ";
            getline(cin, arrive);
        }

        //flightMap.print();
        Dijkstra dijkstraTest;
        vector<Vertex> path = dijkstraTest.dijkstra(flightMap, src, arrive); //runs dijkstra for fastest path
        double count = 0; //used for total miles
        // cout << path[0] << "\n";
        for(size_t i = 1; i < path.size(); i++){ //goes through vector outputed by dijkstra 
            // cout << path[i] << "\n";
            cout << "\n" << "You must go from "<< path[i - 1] << " to " << path[i] << " which is " << flightMap.getEdgeWeight(path[i-1], path[i]) << " miles."<< endl; 
            count += flightMap.getEdgeWeight(path[i-1], path[i]);
        }
        cout << "\n" << "Your total flight distance will be " << count << " miles\n";
    }
    else if(land == "Landmark"){
        cout << "Input your departing airport: ";
        getline(cin, src);
        if(src == "Hell"){ //easter egg
            src = "Newark Liberty International Airport";
        }
        if(src == "Home"){ //easter egg
            src = "University of Illinois Willard Airport";
        }
        while(airportData.count(src) < 1){ //makes sure aiport is valid
            cout << "Sorry this airport does not exist. Please input another one.\n ";
            cout << "Input your departing airport: ";
            getline(cin, src);
        }

        cout << "Input your connecting airport: "; 
        getline(cin, mid);
        if(mid == "Hell"){ //easter egg
            mid = "Newark Liberty International Airport";
        }
        if(mid == "Home"){ //easter egg
            mid = "University of Illinois Willard Airport";
        }
        while(airportData.count(mid) < 1){ //makes sure aiport is valid
            cout << "Sorry this airport does not exist. Please input another one.\n ";
            cout << "Input your connecting airport: ";
            getline(cin, mid);
        }

        cout << "Input your arriving airport: ";
        getline(cin, arrive);
        if(arrive == "Hell"){ //easter egg
            arrive = "Newark Liberty International Airport";
        }
        if(arrive == "Home"){ //easter egg
            arrive = "University of Illinois Willard Airport";
        }
        while(airportData.count(arrive) < 1){ //makes sure aiport is valid
            cout << "Sorry this airport does not exist. Please input another one.\n";
            cout << "Input your arriving airport: ";
            getline(cin, arrive);
        }

        //flightMap.print();
        Dijkstra dijkstraTest;
        vector<Vertex> path = dijkstraTest.landmarkPath(flightMap, src, mid,arrive); //finds all destinations using landmark algorithm
        double count = 0;
        for(size_t i = 1; i < path.size(); i++){ //outputs all elements of landmark
            cout << "\n" << "You must go from "<< path[i - 1] << " to " << path[i] << " which is " << flightMap.getEdgeWeight(path[i-1], path[i]) << " miles."<< endl;
            count += flightMap.getEdgeWeight(path[i-1], path[i]);
        }
        cout << "\n" << "Your total flight distance will be " << count << " miles\n";
    }
    return 0;
}
