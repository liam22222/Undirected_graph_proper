#include "utilities_functions.h"

bool probability(const float &p) {
    if (!p) return false;

    float r = static_cast <float> (rand()) / static_cast <float> (RAND_MAX);
    return p > r;
}

void print_vector(const std::vector<int> &vec){
    for (int iterator = 0; iterator < vec.size(); iterator++) {
        if(iterator != vec.size()-1){
            std::cout << vec[iterator] << ",";
        } else{
            std::cout << vec[iterator] << "\n";
        }
    }
    if(vec.empty()){std::cout << "\n";}
}

void print_vector(const std::vector<float> &vec){
    for (int iterator = 0; iterator < vec.size(); iterator++) {
        if(iterator != vec.size()-1){
            std::cout << vec[iterator] << ",";
        } else{
            std::cout << vec[iterator] << "\n";
        }
    }
    if(vec.empty()){std::cout << "\n";}
}

std::vector<std::vector<int>> build_random_graph(const unsigned &V, const float &p){
    //First we create our variables
    std::vector<std::vector<int>> graph;
    std::vector<int> vec_temp = {};

    //initializing the graph
    for (int vertex = 0; vertex < V; vertex++) {
        graph.push_back(vec_temp);
    }

    //In here we run on each vertex and check if (vertex, vertex_edge) has edge.
    for (int vertex = 0; vertex < V; vertex++) {
        for (int vertex_sec = vertex + 1; vertex_sec < V; vertex_sec++) {
            //Check probability for edge
            if(probability(p)){
                //Adding the vertexes to each other
                graph[vertex].push_back(vertex_sec);
                graph[vertex_sec].push_back(vertex);
            }
        }
    }

    return graph;
}

void print_graph(const std::vector<std::vector<int>> &graph, const unsigned int &V) {
    std::cout << "Graph: \n";

    for (int vertex = 0; vertex < V; vertex++) {
        std::cout << vertex << "(" << graph[vertex].size() <<"): ";
        print_vector(graph[vertex]);
    }
}

void combine_vectors(std::vector<int> &vec1, const std::vector<int> &vec2) {
    vec1.insert(std::end(vec1), std::begin(vec2),std::end(vec2));
}

void remove_common(std::vector<int> &remove_from, const std::vector<int> &compare) {
    //"equal" is a flag that check for equal values
    bool equal;

    //Entering a double-for loop to check each value inside "remove_from"
    for (int i = remove_from.size() - 1; i >= 0; i--) {
        equal = false;

        //Counting if there is any value match between the vectors
        if (std::count(compare.begin(), compare.end(), remove_from[i]))
            equal = true;

        //if I have found a value in index 'i', I'll remove it using std::vector.erase
        if (equal) {
            remove_from.erase(remove_from.begin() + i);
        }
    }
}

std::pair<int,int> BFS(const std::vector<std::vector<int>> &graph , const unsigned &V, const unsigned &vertex) {
    //Init Q and PI that stand for vertexes and distance from father. Neighbors are a vertex neighbors.
    std::vector<int> Q, PI, neighbors;

    //The vertex distance from itself is zero so we will add him.
    Q.push_back(vertex);
    PI.push_back(0);

    //Running on every vertex inside Q
    for (int ver = 0; ver < Q.size(); ver++) {
        //Finding the ver neighbors that has not been visited yet.
        neighbors = graph[Q[ver]];
        remove_common(neighbors,Q);

        //Adding them into Q and PI
        combine_vectors(Q,neighbors);
        for (int neighbor = 0; neighbor < neighbors.size(); neighbor++) {
            PI.push_back(PI[ver] + 1);
        }
        if (Q.size() == V){
            return std::make_pair(Q.back(),PI.back());
        }
    }

    //Return the furhest vertex from "vertex" if every vertex has been visited.
    //If there is vertex that has not been visited, we can say the graph is not connected and return -1
    if (Q.size() != V) return std::make_pair(-1,-1);
    else return std::make_pair(Q.back(),PI.back());
}

unsigned diameter(const std::vector<std::vector<int>> &graph, const unsigned int &V) {
    //Generate a random vertex
    int max_distance = 0,random_vertex = rand() % V, count = 0;
    std::pair<int , int > vertex_distance;

    //Calling BFS on this vertex
    vertex_distance = BFS(graph,V,random_vertex);

    //If vertex distance is -1 then the graph is not connected and diameter equal -1
    if (vertex_distance.first == -1) {
        std::cout << "The Graph is unconnected, which mean is diameter is -1 (infinity)";
        return -1;
    }

    //We also need to find only those which the diameter is equal to two. so for each graph that is diameter bigger from 2 we will return -1.
    if (vertex_distance.second > 2){
        std::cout << "The graph diameter is bigger than 2 which mean he is not fit.";
        return -2;
    }

    //Now that we know we have a connected graph it is time to find v such that v and u are the furhest.
    //If for 10 BFS on diff vertexes we got result of diameter 2 we return 2
    max_distance = vertex_distance.second;
    for (int vertex = 0; vertex < V; vertex++) {
        vertex_distance = BFS(graph,V,vertex);
        if (vertex_distance.second > max_distance) {
            max_distance = vertex_distance.second;
            std::cout<<"\nVertex : " << vertex <<"\nLongest-Shortest : " << max_distance << "\n";
        }
        if (max_distance > 2){
            std::cout << "The graph diameter is bigger than 2 which mean he is not fit. Vertex number - " << vertex;
            return max_distance;
        }
    }
    /*
    std::cout << std::endl << "The most far vertexes are : " << vertex_distance.first;
    vertex_distance = BFS(graph,V,vertex_distance.first);
    std::cout << "-->" << vertex_distance.first << " with diameter of : " << vertex_distance.second;
    */
    //Return diameter
    std::cout<<"Graph diameter is : " << max_distance;
    return max_distance;

}

bool is_isolated(const std::vector<std::vector<int>> &graph) {
    for (int vertex = 0; vertex < graph.size(); vertex++) {
        if (graph[vertex].empty()) return true;
    }
    return false;
}

bool connectivity(std::vector<std::vector<int>> &graph) {
    //Doing BFS on a random vertex
    unsigned random_vertex = rand() % graph.size();
    std::pair<int,int> BFS_for_vertex = BFS(graph,graph.size(),random_vertex);

    if (BFS_for_vertex.first == -1) return false;
    else return true;

}


