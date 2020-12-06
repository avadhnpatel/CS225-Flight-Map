#pragma once

#include <string>
#include <limits.h>
#include "graph.h"


using std::string;

typedef string Vertex;

struct Airports{
    double longitude;
    double latitude;

    string airportName;
    string iata;
};
class Edge
{
  public:
    Vertex source; /**< The source of the edge **/
    Vertex dest; /**< The destination of the edge **/

    /**
     * Parameter constructor for unweighted graphs.
     * @param u - one vertex the edge is connected to
     * @param v - the other vertex it is connected to
     */
    Edge(Vertex u, Vertex v)
        : source(u), dest(v), label(""), weight(-1)
    { /* nothing */
    }

    /**
     * Parameter constructor for unweighted graphs.
     * @param u - one vertex the edge is connected to
     * @param v - the other vertex it is connected to
     * @param lbl - the edge label
     */
    Edge(Vertex u, Vertex v, string lbl)
        : source(u), dest(v), label(lbl), weight(-1)
    { /* nothing */
    }

    /**
     * Parameter constructor for weighted graphs.
     * @param u - one vertex the edge is connected to
     * @param v - the other vertex it is connected to
     * @param w - the weight of the edge
     * @param lbl - the edge label
     */
    Edge(Vertex u, Vertex v, double w, string lbl)
        : source(u), dest(v), label(lbl), weight(w)
    { /* nothing */
    }

    /**
     * Default constructor.
     */
    Edge() : source(""), dest(""), label(""), weight(-1)
    { /* nothing */
    }

    /**
     * Compares two Edges.
     * operator< is defined so Edges can be sorted with std::sort.
     * @param other - the edge to compare with
     * @return whether the current edge is less than the parameter
     */
    bool operator<(const Edge& other) const
    {
        return weight < other.weight;
    }

    /**
     * Gets edge label.
     */
    string getLabel() const
    {
        return this->label;
    }

    /**
     * Gets edge weight.
     */
    double getWeight() const
    {
        return this->weight;
    }

    /**
     * Compares two edges' source and dest.
     * @param other - the edge to compare with
     */
    bool operator==(Edge& other) const
    {
        if (this->source != other.source)
            return false;
        if (this->dest != other.dest)
            return false;
        return true;
    }
private:
    string label; /**< The edge label **/
    double weight; /**< The edge weight (if in a weighed graph) **/

};
