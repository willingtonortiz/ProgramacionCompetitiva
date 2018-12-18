#include <bits/stdc++.h>

using namespace std;

/*
Pair <destino, peso>
*/

// Se debe definir el INF
vector<int> dijkstra(vector<vector<pair<int, int>>> &graph, int cur)
{
	int n = graph.size();
	vector<int> dist(n, INF);
	priority_queue<pair<int, int>> pq;
	dist[cur] = 0;
	pq.push({0, cur});

	while (!pq.empty())
	{
		pair<int, int> temp = pq.top();
		pq.pop();
		int x = temp.second;

		if (dist[x] != -temp.first)
			continue;

		for (pair<int, int> p : graph[x])
		{
			int y = p.first, c = p.second;

			if (dist[x] + c < dist[y])
			{
				dist[y] = dist[x] + c;
				pq.push({-dist[y], y});
			}
		}
	}
}