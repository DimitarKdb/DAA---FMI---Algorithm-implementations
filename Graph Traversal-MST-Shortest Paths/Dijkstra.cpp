#include <iostream>
#include <vector>
#include <queue>
#include <limits>

using namespace std;

const int INF = numeric_limits<int>::max();

// Data structure to store a graph edge
struct GraphEdge {
    int destination; // ID of the destination vertex
    int weight; // Weight of the edge
};

// Data structure to store a graph vertex
struct GraphVertex {
    int id; // ID of the vertex
    int distance; // Shortest distance from the source vertex to this vertex
    bool visited; // Flag indicating whether the vertex has been visited or not
    vector<GraphEdge> edges; // Outgoing edges from the vertex
};

// Dijkstra's algorithm to find the shortest path from source to all other vertices

void dijkstra(vector<GraphVertex>& graph, int source) {
    // Priority queue to store the vertices in increasing order of their distance from the source vertex

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> priorityQueue;

    // Initialize the distance of all vertices to infinity except the source vertex, which is set to zero

    graph[source].distance = 0;
    priorityQueue.push(make_pair(0, source));

    while (!priorityQueue.empty()) {
        // Pop the vertex with the smallest distance from the queue

        int smallestDistanceVertex = priorityQueue.top().second;
        priorityQueue.pop();

        // If the vertex has already been visited, skip it

        if (graph[smallestDistanceVertex].visited) {
            continue;
        }

        graph[smallestDistanceVertex].visited = true;

        // Loop through all neighboring vertices of u and update their distances if necessary

        for (const auto& edge : graph[smallestDistanceVertex].edges) {
            int neighbour = edge.destination;
            int weight = edge.weight;
            if (graph[smallestDistanceVertex].distance != INF && graph[smallestDistanceVertex].distance + weight < graph[neighbour].distance) {
                graph[neighbour].distance = graph[smallestDistanceVertex].distance + weight;
                priorityQueue.push(make_pair(graph[neighbour].distance, neighbour));
            }
        }
    }
}

int main() {
    int numVertices, numEdges;
    cin >> numVertices >> numEdges;
    vector<GraphVertex> graph(numVertices);
    // Read in the edges of the graph from standard input and store them in the graph data structure
    for (int i = 0; i < numEdges; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        graph[u].id = u;
        graph[v].id = v;
        graph[u].edges.push_back({ v, w });
        graph[v].edges.push_back({ u, w });
    }
    int source;
    cin >> source;
    // Initialize the distance of all vertices to infinity
    for (auto& vertex : graph) {
        vertex.distance = INF;
    }
    // Run Dijkstra's algorithm from the source vertex
    dijkstra(graph, source);
    // Output the shortest distance from the source vertex to each of the other vertices
    for (const auto& vertex : graph) {
        if (vertex.id != source) {
            cout << "Shortest distance from " << source << " to " << vertex.id << " is " << vertex.distance << endl;
      }
   }
    return 0;
}
