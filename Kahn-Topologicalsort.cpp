#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<int> kahnToposort(vector<vector<int>>& graph, int n)
{
	vector<int> indegree(n, 0);

	for (int i = 0; i < n; i++)
		for (int neighbour : graph[i])
			indegree[neighbour]++;
		
	queue<int> que;
	for (int i = 0; i < n; i++)
		if (indegree[i] == 0)
			que.push(i);

	vector<int> ans;
	while (que.size() != 0)
	{
		int current = que.front();
		que.pop();
		ans.push_back(current);
		for (int v : graph[current])
			if (--indegree[v] == 0)
				que.push(v);
	}

	return ans;
}