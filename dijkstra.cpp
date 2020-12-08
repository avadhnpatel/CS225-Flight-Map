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
    return vertexPath;
    
}

vector<Vertex> Dijkstra::landmarkPath(Graph flightMap, Vertex srcAirport, Vertex middleAirport, Vertex dstAirport){
    vector<Vertex> dijkstraOne = dijkstra(flightMap, srcAirport, middleAirport);
    vector<Vertex> dijkstraTwo = dijkstra(flightMap, middleAirport, dstAirport);
    reverse(dijkstraOne.begin(),dijkstraOne.end());
    reverse(dijkstraTwo.begin(),dijkstraTwo.end());
    dijkstraTwo.erase(dijkstraTwo.begin());
    for(size_t x =0; x<dijkstraTwo.size(); x++){
        dijkstraOne.push_back(dijkstraTwo[x]);
    }
    return dijkstraOne;
}
