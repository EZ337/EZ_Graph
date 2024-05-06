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
}
