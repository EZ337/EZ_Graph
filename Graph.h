#ifndef GRAPH_H
#define GRAPH_H

// Include statememnts
#include <string>
#include <set>
#include <map>
#include <stdexcept>

#include <iostream>

template <typename IDType = int>
class Vertex
{
private:
    IDType id; // ID of the vertex. Integers are cleaner to deal with
    /// Set of pointers to adjacent vertices
    std::set<Vertex<IDType>*> incident_vertices;
    bool visited = false;

public:
    /// @brief Creates a vertex with id v_id
    /// @param v_id ID of the created vertex
    Vertex(IDType v_id) : id(v_id) {}

    void AddIncidentVertex(Vertex<IDType>* other)
    {
        this->incident_vertices.insert(other);
    }

    /// @return The degree of this vertex
    int degree() {return incident_vertices.size();}

    /// @brief Comparison operator. Comment and uncomment t
    /// @param lhs vertex1
    /// @param rhs vertex2
    /// @return strong ordering of the comparison
    friend auto operator<=>(const Vertex<IDType>& lhs, 
        const Vertex<IDType>& rhs) 
    {
        return lhs.id <=> rhs.id;
    }

    /// @brief Compares vertex with other vertex. Note, IDType must
    /// have a valid operator== overload.
    /// @return true if ids match. False otherwise
    friend bool operator==(const Vertex<IDType>& v1, const Vertex<IDType>& v2) 
    {return v1.id == v2.id;}

    friend bool operator<(const Vertex<IDType>& v1, const Vertex<IDType>& v2) 
    {return v1.id < v2.id;}

    friend bool operator>(const Vertex<IDType>& v1, const Vertex<IDType>& v2) 
    {return v1.id > v2.id;}

    friend bool operator!=(const Vertex<IDType>& v1, const Vertex<IDType>& v2)
    { return v1.id != v2.id;}

    friend bool operator>=(const Vertex<IDType>& v1, const Vertex<IDType>& v2)
    { return (v1>v2 || v1 == v2); }

    friend bool operator<=(const Vertex<IDType>& v1, const Vertex<IDType>& v2)
    { return (v1<v2 || v1 == v2); }

};

template <typename IDType = int>
struct Edge
{
    std::pair<Vertex<IDType>, Vertex<IDType>> connection;
    int weight = 0;

    Edge(const Vertex<IDType>& v1, const Vertex<IDType>& v2, int weight = 0); 
};


/// @brief Templated class for the graph. Defaults to int for IDs.
/// @tparam IDType 
template <typename IDType = int>
class Graph
{
private:
    /// Serves as the NULLID of a verrtex
    IDType null_id;

    std::set<Vertex<IDType>> vertices;  

public:

    /// @brief Graph constructor. nullrepr is the value that will serve
    /// as the null representation of a vertex. Used in AddToGraph.
    /// @param nullrepr Vertex with this ID will be ignored
    Graph(IDType nullrepr) : null_id(nullrepr) {}

    Vertex<IDType>* AddVertex(IDType id)
    {
        // Throw error if id is nullID
        if (id == null_id)
        {
            throw std::invalid_argument("Vertex ID cannot be the NullID. NullID is " + std::to_string(null_id));
        }

        Vertex<IDType> vert(id); // Create new vertex
        typename std::set<Vertex<IDType>>::iterator v = 
            vertices.insert(vert).first; // Get the inserted vertex
        
        // Return pointer to the vertex
        return const_cast<Vertex<IDType>*>(&(*v)); 
    }
    //void AddEdge(IDType v1, IDType v2);

    /// @brief Adds vertices v1 and v2 and creates a link betweeen them
    /// @param v1 Vertex 1
    /// @param v2 Vertex 2
    void AddToGraph(IDType v1, IDType v2)
    {
        Vertex<IDType>* V1 = AddVertex(v1);

        // Add v2 and create an edge if v2 is not null
        if (v2 != null_id)
        {
            Vertex<IDType>* V2 = AddVertex(v2);

            // Add connection between the vertices
            // Undirected/BiDirectional Graph
            V1->AddIncidentVertex(V2);
            V2->AddIncidentVertex(V1);
        }
    }

    /// @brief Gets the vertex with id id. Creates the vertex and adds to graph
    /// if it does not exist.
    /// @param id ID to search for
    /// @return Pointer to the vertex in the graph
    Vertex<IDType>* operator[](IDType id)
    {
/*         typename std::set<Vertex<IDType>>::iterator vert = vertices.end();
        if ((vert = vertices.find(id)) != vertices.end())
        {
            std::cout << vert->id <<std::endl;
            return const_cast<Vertex<IDType>*>(&(*vert));
        } */

        // Since we're using a set, we don't have to search. It's already done
        // For us
        return AddVertex(id);
    }
};


#endif  // GRAPH_H
