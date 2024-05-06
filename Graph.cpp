#include <iostream>
#include <iterator>
#include <stdexcept>

#include "Graph.h"

template <typename IDType>
void Vertex<IDType>::AddIncidentVertex(Vertex<IDType>* other)
{
    this->IncidentVertices.insert(other);

    //TODO: Create an edge as well
}

template <typename IDType>
Vertex<IDType>* Graph<IDType>::AddVertex(IDType id)
{
    // Throw error if id is nullID
    if (id == NULLVALUE)
    {
        throw std::invalid_argument("Vertex ID cannot be the NullID. NullID is " + std::to_string(NULLVALUE));
    }

    Vertex<IDType> vert(id); // Create new vertex
    typename std::set<Vertex<IDType>>::iterator v = vertices.insert(vert).first; // Get the inserted vertex
    
    return const_cast<Vertex<IDType>*>(&(*v)); // Return pointer to the vertex
}

template <typename IDType>
void Graph<IDType>::AddToGraph(IDType v1, IDType v2)
{
    Vertex<IDType>* V1 = AddVertex(v1);

    // Add v2 and create an edge if v2 is not null
    if (v2 != NULLVALUE)
    {
        Vertex<IDType>* V2 = AddVertex(v2);

        // Add connection between the vertices
        // Undirected/BiDirectional Graph
        V1->AddIncidentVertex(V2);
        V2->AddIncidentVertex(V1);
    }

}

int main()
{
    Graph<> graph(-1);
    graph.AddToGraph(1, -1);
    graph.AddToGraph(7, 1);
    graph.AddToGraph(1,7);
    graph.AddToGraph(1,2);
    graph.AddToGraph(2,4);
    graph.AddToGraph(5,9);
    graph.AddToGraph(3,2);
}