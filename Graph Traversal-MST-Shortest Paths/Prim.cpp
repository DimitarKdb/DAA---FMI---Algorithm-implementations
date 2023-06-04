#include <iostream>
#include <vector>
#include <stack>
#include<queue>

using namespace std;

const int INF = 1e9;

vector<pair<int, int>> prim(vector<vector<pair<int, int>>> adjacencyList) {
    int size = adjacencyList.size();

    // Initialize distance, visited, and parent vectors
    vector<int> distance(size, INF);
    vector<bool> visited(size, false);
    vector<int> parent(size, -1);

    // Set distance of the first node to 0
    distance[0] = 0;

    // Create a min-priority queue of pairs (distance, node)
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> priorityQueue;

    // Add the first node to the queue
    priorityQueue.push({ 0, 0 });

    // While the queue is not empty
    while (!priorityQueue.empty()) {
        // Remove the node with the smallest distance from the queue
        int smallestDistanceNode = priorityQueue.top().second;
        priorityQueue.pop();

        // If the node has already been visited, skip it
        if (visited[smallestDistanceNode]) continue;

        // Mark the node as visited
        visited[smallestDistanceNode] = true;
        
        // For each neighbor of the node
        for (int i = 0; i < adjacencyList[smallestDistanceNode].size(); i++) {
            int adjacentNode = adjacencyList[smallestDistanceNode][i].first;
            int weight = adjacencyList[smallestDistanceNode][i].second;

            // If the neighbor has not been visited and the edge weight is smaller than the current distance
            if (!visited[adjacentNode] && weight < distance[adjacentNode]) {
                // Update the distance of the neighbor
                distance[adjacentNode] = weight;
                // Set the parent of the neighbor to the current node
                parent[adjacentNode] = smallestDistanceNode;
                // Add the neighbor to the queue
                priorityQueue.push({ distance[adjacentNode], adjacentNode });
            }
        }
    }

    // Construct the minimum spanning tree
    vector<pair<int, int>> minimumSpanningTree;
    for (int i = 1; i < size; i++) {
        minimumSpanningTree.push_back({ parent[i], i });
    }

    // Return the minimum spanning tree
    return minimumSpanningTree;
}

