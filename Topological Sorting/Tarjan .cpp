#include <iostream>
#include <vector>
#include <stack>

using namespace std;
// Implementation of Tarjan's algorithm for generating a topological sort of a directed acyclic graph (DAG)

// Define constants
const int MAX_NODES = 10005;

// Define global variables
vector<int> graph[MAX_NODES];  // adjacencyListacency list representing the graph
int numNodes, numEdges;  // number of nodes and edges in the graph
int dfsTime;  // time stamp for DFS
int dfsNum[MAX_NODES], dfsLow[MAX_NODES];  // arrays to store the DFS numbers and lowest back edge
stack<int> dfsStack;  // stack for DFS traversal
bool inStack[MAX_NODES];  // boolean array to check if a node is currently in the stack
vector<int> topologicalOrder;  // vector to store the topological ordering

// Recursive function to perform DFS and generate the topological ordering
void tarjanTopo(int currentNode) {
    // Set the DFS number and lowest back edge for the current node
    dfsNum[currentNode] = dfsLow[currentNode] = dfsTime++;

    // Push the current node onto the DFS stack and mark it as in the stack
    dfsStack.push(currentNode);
    inStack[currentNode] = true;

    // Traverse all neighbors of the current node
    for (int neighbor : graph[currentNode]) {
        // If the neighbor has not been visited yet, perform DFS on it
        if (dfsNum[neighbor] == -1) {
            tarjanTopo(neighbor);
            dfsLow[currentNode] = min(dfsLow[currentNode], dfsLow[neighbor]);
        }
        // If the neighbor is already in the stack, update the lowest back edge for the current node
        else if (inStack[neighbor]) {
            dfsLow[currentNode] = min(dfsLow[currentNode], dfsNum[neighbor]);
        }
    }

    // If the lowest back edge of the current node is equal to its DFS number,
    // then it is the root of a strongly connected component and we can generate the SCC
    if (dfsLow[currentNode] == dfsNum[currentNode]) {
        int node;
        do {
            // Pop nodes from the DFS stack until we reach the current node
            node = dfsStack.top();
            dfsStack.pop();
            inStack[node] = false;

            // Add the popped node to the topological ordering
            topologicalOrder.push_back(node);
        } while (currentNode != node);
    }
}
