#include <list>
#include <unordered_map>
#include <utility>
#include <algorithm>
#include <string>
#include <cstdlib>
#include <climits>
#include <fstream>
#include <iostream>
#include <iomanip>
#include <set>
#include <sstream>
#include <vector>
#include <queue>
#include <stdexcept>
#include <unordered_set>
#include <map>


#include "dijkstra.h"
#include "graph.h"
#include "edge.h"
#include "BFS.h"

using namespace std;

BFS::BFS(const Graph &flightMap) : flightMap_(flightMap){
}

vector<Vertex> BFS::BFSearch(const Vertex &v){
  if (flightMap_.vertexExists(v) == false){ //makes sure that input exists in map
    throw invalid_argument("Invalid start vertex");
  }

  queue<Vertex> BFSqueue; //queue for BFS
  map<Vertex, bool> visited; //map for checking if vertex has been visited
  visited[v] = true;

  vector<Vertex> output;

  BFSqueue.push(v);

  while(!BFSqueue.empty()){
    Vertex currVertex = BFSqueue.front(); //makes currVertex first element in queue
    BFSqueue.pop(); //removes currVertex
    output.push_back(currVertex); //visited currVertex
    for(Vertex &adjVertex : flightMap_.getAdjacent(currVertex)){ //iterate through all adjacent vertices
      if(visited[adjVertex] == false) //checks if vertex has been visited
        BFSqueue.push(adjVertex); //if it has not been visited it pushes to queue and marks it as visited
        visited[adjVertex] = true;
    }
  }
  return output;
}

