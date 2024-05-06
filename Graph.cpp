#include "Graph.h"


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
    auto g2 = graph[2];
    auto g1 = graph[1];
    auto g3 = graph[3];

    std::cout << g2->degree() << std::endl;
    std::cout << (*g1 > *g2) << '\n' << (*g1 < *g2) << '\n' << (*g1 == *g2) <<
    '\n' << (*g1 != *g2) << '\n' << (*g1 >= *g2) << '\n' << (*g1 <= *g2) <<std::endl;
}
