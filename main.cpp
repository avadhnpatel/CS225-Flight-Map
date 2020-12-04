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
    routes.open("test.dat");

    string line;
    string srcAirportID;
    string destAirportID;

    vector<string> result;

    while(getline(routes, line)){
        stringstream ss(line);
        while(getline(ss, line, ',')){
            result.push_back(line);
        }
        srcAirportID = result[2];
        destAirportID = result[4];
        cout << srcAirportID << "  "<< destAirportID << "  ";
    }
    return 0;
}