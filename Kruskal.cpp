#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Define the data structure for an edge, which consists of its two endpoints and its weight
struct Edge {
    int u, v, weight;
};

// Define a comparison function for sorting edges by weight in non-decreasing order
bool compareEdges(const Edge& e1, const Edge& e2) {
    return e1.weight < e2.weight;
}

// Define a function to find the parent of a node in a disjoint-set data structure
int findParent(int node, vector<int>& parent) {
    // If the node is the parent of itself, return the node
    if (parent[node] == node) {
        return node;
    }
    // Otherwise, recursively find the parent of the parent of the node
    return findParent(parent[node], parent);
}

// Define a function to merge two sets in a disjoint-set data structure
void mergeSets(int u, int v, vector<int>& parent, vector<int>& rank) {
    // Find the parent of each set
    int parentU = findParent(u, parent);
    int parentV = findParent(v, parent);

    // If the sets have the same parent, they are already merged, so return
    if (parentU == parentV) {
        return;
    }

    // Otherwise, merge the sets based on their rank (the depth of their subtrees)
    if (rank[parentU] < rank[parentV]) {
        parent[parentU] = parentV;
    }
    else if (rank[parentU] > rank[parentV]) {
        parent[parentV] = parentU;
    }
    else {
        parent[parentU] = parentV;
        rank[parentV]++;
    }
}

// Define the Kruskal's algorithm function
vector<Edge> kruskalminimumSpanningTree(vector<Edge>& edges, int n) {
    // Sort the edges by weight in non-decreasing order
    sort(edges.begin(), edges.end(), compareEdges);

    // Initialize the parent and rank vectors for the disjoint-set data structure
    vector<int> parent(n);
    vector<int> rank(n);

    // Initialize each node to be the parent of itself
    for (int i = 0; i < n; i++) {
        parent[i] = i;
        rank[i] = 0;
    }

    // Initialize the minimum spanning tree and the number of edges added to it
    vector<Edge> minimumSpanningTree;
    int numEdges = 0;

    // Loop over each edge
    for (int i = 0; i < edges.size(); i++) {
        // Get the endpoints and weight of the edge
        int u = edges[i].u;
        int v = edges[i].v;
        int weight = edges[i].weight;

        // If the endpoints are in different sets, add the edge to the minimum spanning tree
        if (findParent(u, parent) != findParent(v, parent)) {
            minimumSpanningTree.push_back({ u, v, weight });
            // Merge the sets containing the endpoints
            mergeSets(u, v, parent, rank);
            numEdges++;
            // If we have added n-1 edges to the minimum spanning tree, we are done
            if (numEdges == n - 1) {
                break;
            }
        }
    }

    // Return the minimum spanning tree
    return minimumSpanningTree;
}
