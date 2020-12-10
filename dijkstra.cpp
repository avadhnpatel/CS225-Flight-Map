#include "dijkstra.h"
#include "graph.h"
#include "edge.h"
#include <queue>
#include <map>
//#include <vector>

struct VertexWeight{
    Vertex vertexName;
    double distance;
    bool visited;
    Vertex previous;
};

class Compare
{
public:
    bool operator() (VertexWeight *a, VertexWeight *b)
    {
        return a->distance > b->distance;
    }
};
/**
 * Returns the shortest path between two airports
 *
 * @param flightMap The graph of airports and routes
 * @param srcAirport The source airport
 * @param dstAirport The destination airport
 */
vector<Vertex> Dijkstra::dijkstra(Graph flightMap, Vertex srcAirport, Vertex dstAirport){
    std::priority_queue<VertexWeight*, std::vector<VertexWeight*>, Compare> pq;
    map<Vertex, VertexWeight*> vertexMap;
    
    vector<Vertex> allVertices = flightMap.getVertices();
    vector<VertexWeight*> allVertexWeights;
    for (size_t i = 0; i < allVertices.size(); i++) {
        VertexWeight *newVertexWeight = new VertexWeight;
        newVertexWeight->vertexName = allVertices.at(i);
        newVertexWeight->distance = std::numeric_limits<double>::max();
        newVertexWeight->visited = false;
        allVertexWeights.push_back(newVertexWeight);
        
        vertexMap[allVertices.at(i)] = newVertexWeight;
        
        
        
        
        if (allVertices.at(i) == srcAirport) {
            newVertexWeight->distance = 0;
            pq.push(newVertexWeight);
        }
    }

    while (pq.top()->vertexName != dstAirport) {
        VertexWeight *current = pq.top();
        pq.pop();
        
        if (!current->visited) {
            vector<Vertex> neighborList = flightMap.getAdjacent(current->vertexName);
            for (size_t i = 0; i < neighborList.size(); i++) {
                VertexWeight *neighbor = vertexMap[neighborList.at(i)];
                if (!neighbor->visited) {
                    double currentToNeighborEdgeWeight = flightMap.getEdgeWeight(current->vertexName, neighbor->vertexName);
                    if (neighbor-> distance > current->distance + currentToNeighborEdgeWeight) {
                        neighbor-> distance = current->distance + currentToNeighborEdgeWeight;
                        neighbor-> previous = current -> vertexName;
                    }
                    
                    pq.push(neighbor);
                }
            }
            current-> visited = true;
        }

    }
    
    vector<Vertex> vertexPath;
    VertexWeight *lastVertex = vertexMap[dstAirport];
    vertexPath.push_back(lastVertex->vertexName);
    while (vertexPath.back() != srcAirport) {
        vertexPath.push_back(vertexMap[vertexPath.back()]->previous);
    }
    
    for (size_t i = 0; i<allVertexWeights.size(); i++) {
        delete allVertexWeights.at(i);
    }
    
    // returns the path in reverse order
    reverse(vertexPath.begin(),vertexPath.end());
    return vertexPath;
    
}

/**
 * Returns the shortest path when having to go through a third location, also known as landmark path
 * Uses two calls of the dijkstra method above
 *
 * @param flightMap The graph of airports and routes
 * @param srcAirport The source airport
 * @param middleAirport The middle airport
 * @param dstAirport The destination airport
 */
vector<Vertex> Dijkstra::landmarkPath(Graph flightMap, Vertex srcAirport, Vertex middleAirport, Vertex dstAirport){
    vector<Vertex> dijkstraOne = dijkstra(flightMap, srcAirport, middleAirport); //Get shortest path from point a to c
    vector<Vertex> dijkstraTwo = dijkstra(flightMap, middleAirport, dstAirport); //Get shortest path from point c to b
    dijkstraTwo.erase(dijkstraTwo.begin()); //Remove first element from the second path, as it is a repeat of last element in first path
    //Loop through second path and append elements to first path to give us a single vector
    for(size_t x =0; x<dijkstraTwo.size(); x++){
        dijkstraOne.push_back(dijkstraTwo[x]);
    }
    return dijkstraOne;
}
