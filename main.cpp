#include <iostream>

#include "utilities_functions.h"



int main() {
    //Init graph, vertexes number and probability
    std::vector<std::vector<int>> graph;
    unsigned V;
    float p;
    V = 10;
    p = 0.8;
    graph = build_random_graph(V,p);
    print_graph(graph,V);
    diameter(graph,V);
    if(is_isolated(graph))
        std::cout << "\nThe graph have an isolated vertex";
    if (connectivity(graph))
        std::cout << "\nThe graph is connected";

}