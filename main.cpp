#include <iostream>

#include "utilities_functions.h"



int main() {
    /*
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
    */

    /* In here, we will test few properties of a random graph with 1000 vertexes (V = 1000).
     * We will also declare p, that stands for the probability that two indexes (v,u) belong to E
     * or in other words, there is an edge between v and u.
     *
     * The properties by order are:
     * 1.   Connectivity -  We can say that if p > ln(V)/V,
     *      the graph have high probability to be "full connected"(we can reach every vertex u from every vertex v).
     *
     * 2.   Diameter - We can say that if p > sqrt(2ln(V)/V) than we have high probability
     *      that the graph diameter is equal to 2
     *
     * 3.   Isolated vertex - In most cases, when p > ln(V)/V, we wont have isolated vertexes.
     *
     * We also know that if we have an isolated vertex the graph is for sure unconnected thus, we can say that
     * properties one and three effect each other on a direct level and have same probability.
     *
     * To begin the simulation, we will create three vectors that each will have different values of probabilities.
     * For example, if I want to explore property number one, I'll create a new
     * vector with five probabilities above it's threshold and five under it.
     *
     * ***SIDE NOTE***
     *  When V = 1000:
     *  ln(V)/V ≈ 0.00690
     *  sqrt(2ln(V)/V) ≈ 0.11753
    */

    std::vector<std::vector<int>> temp_graph;
    std::vector<float> threshold1, threshold2, threshold3;
    std::vector<float> match1, match2, match3;
    unsigned V = 1000, match, graph_amount = 100;

    threshold1 = {0.001,0.002,0.003,0.004,0.005,0.007,0.008,0.009,0.015,0.021};
    threshold2 = {0.05,0.08,0.099,0.102,0.113,0.119,0.12,0.125,0.13,0.24};
    threshold3 = {0.0025,0.0035,0.0045,0.055,0.0061,0.02,0.023,0.025,0.030,0.1};

    //Checking threshold number one
    match = 0;
    for (int probability = 5; probability < threshold1.size(); probability++) {
        for (int random_graph = 0; random_graph < graph_amount; random_graph++) {
            temp_graph = build_random_graph(V,threshold1[probability]);
            if (connectivity(temp_graph)){ match++; }
        }

        match1.push_back(float(match/float(graph_amount)));
        std::cout << match1.back() << "\n";
        match = 0;
    }
    print_vector(match1);

}
