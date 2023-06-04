#include <iostream>
#include <vector>
#include <queue>
using namespace std;

void DFS(int node, vector<vector<int>>& adjList, bool visited[]) {
	visited[node] = true;
	cout << "Node: " << node << endl;
	for (int i = 0; i < adjList[node].size(); i++) {
		if (!visited[adjList[node][i]]) {
			DFS(adjList[node][i], adjList, visited);
		}
	}
}

void BFS(int node, vector<vector<int>>& adjList, bool visited[]) {
	queue<int> BFSQueue;
	visited[node] = true;
	BFSQueue.push(node);

	while (!BFSQueue.empty())  
	{
		int currentNode = BFSQueue.front();
		cout << "Node: " << currentNode << endl;
		BFSQueue.pop();
		for (int i = 0; i < adjList[node].size(); i++)
		{
			if (!visited[adjList[node][i]]) {
				visited[adjList[node][i]] = true;
				BFSQueue.push(adjList[node][i]);
			}
		}
	}

}	


