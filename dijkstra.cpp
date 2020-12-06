#include "dijkstra.h"
#include "graph.h"
#include "edge.h"

void Dijkstra::dijkstra(Graph flightMap, string srcAirport){
    vector<Vertex> allVertices = flightMap.getVertices();
    int numVertices = allVertices.size();
    vector<double> distance(numVertices, INFINITY);
    
}