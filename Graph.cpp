#include <iostream>

#include "Graph.h"

template <typename IDType>
void Graph<IDType>::AddVertex(IDType id)
{
    Vertex<IDType> vert(id);
    vertices.insert(vert);
}


int main()
{
    Graph<> graph;
    graph.AddVertex(3);
    graph.AddVertex(8);
    graph.AddVertex(4);
    graph.AddVertex(2);
    graph.AddVertex(3);
    graph.AddVertex(3);
}