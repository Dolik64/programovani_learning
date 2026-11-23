#include <iostream>
#include <vector>
#include <limits.h>
using namespace std;

// A utility function to find the vertex with minimum
// distance value, from the set of vertices not yet included
// in shortest path tree
int minDistance(const vector<int>& dist, const vector<bool>& sptSet)
{
    int min = INT_MAX, min_index;

    for (int v = 0; v < dist.size(); v++) {
        if (!sptSet[v] && dist[v] <= min) {
            min = dist[v];
            min_index = v;
        }
    }

    return min_index;
}

// A utility function to print the constructed distance
// array
void printSolution(const vector<int>& dist)
{
    cout << "Vertex \t Distance from Source" << endl;
    for (int i = 0; i < dist.size(); i++)
        cout << i << " \t\t\t\t" << dist[i] << endl;
}

// Function that implements Dijkstra's single source
// shortest path algorithm for a graph represented using
// adjacency matrix representation
void dijkstra(const vector<vector<int>>& graph, int src)
{
    int V = graph.size();  // Number of vertices in the graph
    vector<int> dist(V, INT_MAX);  // The output array. dist[i] will hold the shortest distance from src to i
    vector<bool> sptSet(V, false);  // sptSet[i] will be true if vertex i is included in shortest path tree

    // Distance of source vertex from itself is always 0
    dist[src] = 0;

    // Find shortest path for all vertices
    for (int count = 0; count < V - 1; count++) {
        // Pick the minimum distance vertex from the set of vertices not yet processed
        int u = minDistance(dist, sptSet);

        // Mark the picked vertex as processed
        sptSet[u] = true;

        // Update dist value of the adjacent vertices of the picked vertex.
        for (int v = 0; v < V; v++) {
            if (!sptSet[v] && graph[u][v] && dist[u] != INT_MAX && dist[u] + graph[u][v] < dist[v]) {
                dist[v] = dist[u] + graph[u][v];
            }
        }
    }

    // Print the constructed distance array
    printSolution(dist);
}

// Driver's code
int main()
{
    // Example graph as an adjacency matrix
    vector<vector<int>> graph = { { 0, 4, 0, 0, 0, 0, 0, 8, 0 },
                                  { 4, 0, 8, 0, 0, 0, 0, 11, 0 },
                                  { 0, 8, 0, 7, 0, 4, 0, 0, 2 },
                                  { 0, 0, 7, 0, 9, 14, 0, 0, 0 },
                                  { 0, 0, 0, 9, 0, 10, 0, 0, 0 },
                                  { 0, 0, 4, 14, 10, 0, 2, 0, 0 },
                                  { 0, 0, 0, 0, 0, 2, 0, 1, 6 },
                                  { 8, 11, 0, 0, 0, 0, 1, 0, 7 },
                                  { 0, 0, 2, 0, 0, 0, 6, 7, 0 } };

    // Function call
    dijkstra(graph, 0);

    return 0;
}
