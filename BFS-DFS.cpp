#include <iostream>
#include <stack>
#include <queue>
#include <vector>

using namespace std;

void BFS(vector<vector<int>>& adjacencyListacentList, int startingNode) {
	int numberOfNodes = adjacencyListacentList.size();

	//Creating a visited array and initializing all nodes as unvisited

	vector<bool> visited(numberOfNodes, false);

	//Creating the BFS queue
	queue<int> queue;

	visited[startingNode] = true;
	queue.push(startingNode);

	int currentNode;

	while (!queue.empty()) {

		currentNode = queue.front();
		cout << currentNode << " ";
		queue.pop();

		// Get all adjacencyListacent vertices of the dequeued vertex currentNode
		// If an adjacencyListacent vertex has not been visited, then mark it as visited and enqueue it
		int adjacencyListacentNode;
		for (size_t i = 0; i < adjacencyListacentList[currentNode].size(); i++)
		{
			adjacencyListacentNode = adjacencyListacentList[currentNode][i]; //traversing the ajacency list of the node currentNode
			if (!visited[adjacencyListacentNode]) {
				visited[adjacencyListacentNode] = true;
				queue.push(adjacencyListacentNode);
			}
		}

	}
}

/*   
  If we want to traverse all the components we have to perform BFS traversal starting from all unvisited nodes:
	for(int i = 0; i < num_nodes; i++) {
        if(!visited[i]) {
            BFS(adjacencyList_list, i);
        }
    }
*/



void DFS(vector<vector<int>>& adjacencyListacentList, int currentNode, vector<bool>& visited) {
	// Mark the current node as visited and print it
	visited[currentNode] = true;
	cout << currentNode << " ";

	// Recur for all the vertices adjacencyListacent to this vertex
	int adjacencyListacentNode;
	for (size_t i = 0; i < adjacencyListacentList[currentNode].size(); i++)
	{
		adjacencyListacentNode = adjacencyListacentList[currentNode][i];
		if (!visited[adjacencyListacentNode]) {
			DFS(adjacencyListacentList, adjacencyListacentNode, visited);
		}
	}

}

/*
  If we want to traverse all the components we have to perform DFS traversal starting from all unvisited nodes:
	for(int i = 0; i < num_nodes; i++) {
		if(!visited[i]) {
			DFS(adjacencyList_list, visited, i);
		}
	}
*/