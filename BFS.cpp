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
  flightMap_.print();
}

vector<Vertex> BFS::BFSearch(const Vertex &v){
  if (flightMap_.vertexExists(v) == false){
    throw invalid_argument("Invalid start vertex");
  }

  queue<Vertex> BFSqueue;
  map<Vertex, bool> visited;
  visited[v] = true;

  vector<Vertex> output;

  BFSqueue.push(v);

  while(!BFSqueue.empty()){
    Vertex currVertex = BFSqueue.front();
    BFSqueue.pop();

    cout << " Visited: " << currVertex << endl;
    output.push_back(currVertex);
    for(Vertex &adjVertex : flightMap_.getAdjacent(currVertex)){
      cout << " Reached: " << adjVertex << endl;
      if(visited.count(adjVertex) == 0)
        BFSqueue.push(adjVertex);
        visited[adjVertex] = true;
    }
  }
  return output;
}

// vector<Vertex> BFS::BFSearch(const Vertex &v){
//   if (flightMap_.vertexExists(v) == false){
//     throw invalid_argument("Invalid start vertex");
//   }
//   queue<string> q;
//   q.push(v);
//   unordered_set<string> visitVert;

//   while(q.empty() == false){
//     string currVertex = q.front();
//     q.pop();
//     if(visitVert.find(currVertex) == visitVert.end()){
//       visitVert.insert(currVertex);

//       cout << "Visited: " << currVertex << endl;

//       for(Vertex &adjVertex : flightMap_.getAdjacent(currVertex)){
//         cout << "Reached: " << adjVertex << endl;
//         q.push(adjVertex);
//       }
//     }
//   }

// }

// DFS::DFS(const Graph &graph) : graph_(graph) { graph_.print(); }
 
// vector<string> DFS::PerformSearch(const string &start_vertex) {
//   if (!graph_.vertexExists(start_vertex)) {
//     throw std::invalid_argument("Start Vertex does not exist in the graph");
//   }
//   std::vector<string> processed;
 
//   std::unordered_set<string> visited;
//   std::stack<string> discovered;
 
//   discovered.push(start_vertex);
//   while (!discovered.empty()) {
//     string vertex = discovered.top();
//     discovered.pop();
//     if (visited.find(vertex) == visited.end()) {
//       visited.insert(vertex);
//       std::cout << "Visited: " << vertex << std::endl;
//       processed.push_back(vertex);
//       std::cout << "push back " << std::endl;
//       for (Vertex &adjacent_vertex : graph_.getAdjacent(vertex)) {
//         std::cout << "got here" << adjacent_vertex << std::endl;
//         if (visited.find(adjacent_vertex) == visited.end()) {
//           discovered.push(adjacent_vertex);
//         }
//       }
//     }
//   }
//   return processed;
// }
