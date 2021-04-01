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
    std::vector<float> threshold_connectivity, threshold_diameter, threshold_isolated;
    std::vector<float> match_connectivity, match_diameter, match_isolated;
    unsigned V = 1000, match=0, graph_amount = 500;

    threshold_connectivity = {0.001, 0.002, 0.003, 0.004, 0.005, 0.007, 0.008, 0.009, 0.015, 0.021};
    threshold_diameter = {0.05, 0.08, 0.099, 0.102, 0.113, 0.119, 0.12, 0.125, 0.13, 0.24};
    threshold_isolated = {0.0025, 0.0035, 0.0045, 0.055, 0.0061, 0.02, 0.023, 0.025, 0.030, 0.1};

    //Checking for "Connectivity" property
/*
    std::cout << "Checking for Connectivity property\n";
    for (int probability = 0; probability < threshold_connectivity.size(); probability++) {
        for (int graph_number = 0; graph_number < graph_amount; graph_number++) {
            temp_graph = build_random_graph(V, threshold_connectivity[probability]);
            if (connectivity(temp_graph)){ match++; }
        }
        std::cout << "For probability " << threshold_connectivity[probability] <<
                  " There are " << match << " graphs that are connected";
        match_connectivity.push_back(float(match / float(graph_amount)));
        match = 0;
    }

    //Checking for "Diameter" property
    std::cout << "Checking for Diameter property\n";
    for (int probability = 0; probability < threshold_diameter.size(); probability++) {
        for (int graph_number = 0; graph_number < graph_amount; graph_number++) {
            std::cout << "\nGraph number " << graph_number << "\n";
            temp_graph = build_random_graph(V, threshold_diameter[probability]);
            if (diameter(temp_graph,V) == 2){ match++; }
        }
        std::cout << "\nFor probability " << threshold_diameter[probability] <<
                  " There are " << match << " graphs that their diameter is equal 2";
        match_diameter.push_back(float(match / float(graph_amount)));
        match = 0;
    }
*/
    //Checking for "Isolated" property
    std::cout << "Checking for Isolated property\n";
    for (int probability = 0; probability < threshold_isolated.size(); probability++) {
        for (int graph_number = 0; graph_number < graph_amount; graph_number++) {
            temp_graph = build_random_graph(V, threshold_isolated[probability]);
            if (is_isolated(temp_graph)){ match++; }
        }
        std::cout << "\nFor probability " << threshold_isolated[probability] <<
                  " There are " << match << " graphs that have an isolated vertex";
        match_isolated.push_back(float(match / float(graph_amount)));
        match = 0;
    }

    /*
    print_vector(match_connectivity);
    print_vector(match_diameter);
    print_vector(match_isolated);
    */
}
