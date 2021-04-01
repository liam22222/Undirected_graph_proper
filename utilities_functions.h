#ifndef RANDOM_UNDIRECTED_GRAPH_UTILITIES_FUNCTIONS_H
#define RANDOM_UNDIRECTED_GRAPH_UTILITIES_FUNCTIONS_H

#include <iostream>

//I've used a lot of vectors in here.
#include <vector>

// I use "algorithm" library for std::count method. The method check if a certain value is between two pointers

#include <algorithm>

//Use pow function in probability method

#include <math.h>
/*
 * The function return if a certain probability 'p' occur.
 *
 * True - It occur
 * False - It was not
 */
bool probability(const float &p);

/*
 * Build Random Graph
 * The function generate a random graph with probability 'p' to edge between u,v.
 *
 * We will represent it in a vectors inside of vectors for few reasons:
 * 1.   Memory Cost
 * 2.   Easy to reach out an edge neighbors.
 *
 * The function return the graph
 */
std::vector<std::vector<int>> build_random_graph(const unsigned &V, const float &p);

/*
 * Print vector int
 *
 * A simple function that prints vector.
 */
void print_vector(const std::vector<int> &vec);


/*
 * Print vector float
 *
 * A simple function that prints vector.
 */
void print_vector(const std::vector<float> &vec);

/*
 * Print Graph
 *
 * A function that prints the graph
 */
void print_graph(const std::vector<std::vector<int>> &graph, const unsigned &V);

/*
 * Combine Vector
 *
 * The function takes vec2 and insert it in the end of vec1
 * returns nothing
 */
void combine_vectors(std::vector<int> &vec1, const std::vector<int> &vec2);


/* remove_from - The vector I want to remove common elements from
 * compare - The vector that I use to check for match
 *
 * This function remove common elements from "remove_from" by comparing it to "compare"
*/
void remove_common(std::vector<int> & remove_from, const std::vector<int> & compare);

/*
 * BFS
 *
 * Using the BFS algorithm, what this function does is to return the furhest vertex from a given vertex.
 * We don't need to return the distance of every vertex because we only
 * using this function to find out diameter of a graph.
 */
std::pair<int,int> BFS(const std::vector<std::vector<int>> &graph , const unsigned &V, const unsigned &vertex);

/*
 * Diameter
 *
 * The function using BFS algorithm and return the largest shortest path between two vertexes, also known as diameter.
 * To keep it effective as possible, we will use a technique to find diameter that uses only two iterations of BFS.
 *
 * what it does, is to apply a BFS on a random vertex v, and find the furhest vertex u from it.
 * Once its done, we will run again the BFS function but this time on vertex u and find the furhest vertex from it w.
 * We can now say, that (u,w) are the diameter of the graph.
 *
 * I have got the idea from this article:
 * https://cs.stackexchange.com/questions/194/the-time-complexity-of-finding-the-diameter-of-a-graph
 */
unsigned diameter(const std::vector<std::vector<int>> &graph, const unsigned &V);

/*
 *  Is isolated
 *
 *  Running on every vertex in graph to see if one of them have no neighbors.
 *  If one of them have no neighbors, return True
 *  else return False
 */
bool is_isolated(const std::vector<std::vector<int>> &graph);

/*
 * Connectivity
 *
 * A connected graph is a graph that you can reach from every two vertexes,v and u, to each other.
 * In order to find connectivity, I'll use BFS and check if the diameter is different from -1.
 * If so, we can say that from vertex v we can reach every other vertex in the graph.
 * Else, there is at least one vertex I am unable to reach from u which mean the graph isn't connected.
 */
bool connectivity(std::vector<std::vector<int>> & graph);
#endif //RANDOM_UNDIRECTED_GRAPH_UTILITIES_FUNCTIONS_H