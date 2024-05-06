#include <iostream>

#include "Graph.h"

template <typename IDType>
Graph<IDType>::Graph(IDType x)
{
    Vertex<IDType> vert(x);
    vertices.insert(vert);
}


int main()
{
    Graph<> graph(3);
}