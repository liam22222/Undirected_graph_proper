#include <iostream>

#include "utilities_functions.h"



int main() {
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
    std::ofstream myCSV;
    std::vector<std::vector<int>> temp_graph;
    std::vector<float> threshold_connectivity, threshold_diameter, threshold_isolated;
    std::vector<float> match_connectivity, match_diameter, match_isolated;
    std::string file_name = "graph_data";
    unsigned V = 1000, match=0, graph_amount = 500;

    //Open graph_data.csv
    threshold_connectivity = {0.001, 0.002, 0.003, 0.004, 0.005, 0.007, 0.008, 0.009, 0.015, 0.021};
    threshold_diameter = {0.005, 0.008, 0.0099, 0.0102, 0.113, 0.11760, 0.118, 0.1185, 0.119, 0.120};
    threshold_isolated = {0.0025, 0.0035, 0.0045, 0.0053, 0.0061, 0.0070, 0.0073, 0.00795, 0.009, 0.01};


    //Checking for "Connectivity" property
    std::cout << "Checking for Connectivity property\n";
    for (int probability = 0; probability < threshold_connectivity.size(); probability++) {
        std::cout << "\nWith probability p : " << threshold_connectivity[probability] << "\n";
        for (int graph_number = 0; graph_number < graph_amount; graph_number++) {
            std::cout << "\nGraph number : " << graph_number;
            temp_graph = build_random_graph(V, threshold_connectivity[probability]);
            if (connectivity(temp_graph)){ match++; }
        }
        std::cout << "\nFor probability " << threshold_connectivity[probability] <<
                  " There are " << match << " graphs that are connected";
        match_connectivity.push_back(float(match / float(graph_amount)));
        match = 0;
    }

    //Write connectivity to CSV
    myCSV << "Connectivity :\n";
    vector_to_CSV(myCSV,file_name,threshold_connectivity);
    myCSV << "\n";
    vector_to_CSV(myCSV,file_name,match_connectivity);

    print_vector(match_connectivity);

    //Checking for "Diameter" property
    std::cout << "\nChecking for Diameter property\n";
    for (int probability = 0; probability < threshold_diameter.size(); probability++) {
        std::cout << "\nWith probability p : " << threshold_diameter[probability] << "\n";
        for (int graph_number = 0; graph_number < graph_amount; graph_number++) {
            std::cout << "\nGraph number " << graph_number << "\n";
            temp_graph = build_random_graph(V, threshold_diameter[probability]);
  //          print_graph(temp_graph,V);
            if (diameter(temp_graph,V) == 2){ match++; }
        }
        std::cout << "\nFor probability " << threshold_diameter[probability] <<
                  " There are " << match << " graphs that their diameter is equal 2";
        match_diameter.push_back(float(match / float(graph_amount)));
        match = 0;
    }

    myCSV << "Diameter :\n";
    vector_to_CSV(myCSV,file_name,threshold_diameter);
    myCSV << "\n";
    vector_to_CSV(myCSV,file_name,match_diameter);
    print_vector(match_diameter);

    //Checking for "Isolated" property
    std::cout << "\nChecking for Isolated property\n";
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

    myCSV << "Isolated :\n";
    vector_to_CSV(myCSV,file_name,threshold_isolated);
    myCSV << "\n";
    vector_to_CSV(myCSV,file_name,match_isolated);
    print_vector(match_isolated);

}
