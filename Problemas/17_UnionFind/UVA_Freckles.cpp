#include <bits/stdc++.h>

using namespace std;

const int MAXGRAPH = 102;

int parent[MAXGRAPH];
int rango[MAXGRAPH];

void makeSet(int u)
{
	parent[u] = u;
	rango[u] = 0;
}

int findSet(int u)
{
	if (u == parent[u])
		return u;
	return parent[u] = findSet(parent[u]);
}

void unionSets(int u, int v)
{
	u = findSet(u);
	v = findSet(v);
	if (u != v)
	{
		if (rango[u] < rango[v])
			swap(u, v);

		parent[v] = u;

		if (rango[u] == rango[v])
			rango[u]++;
	}
}

struct Edge
{
	int u;
	int v;
	float w;

	Edge() {}

	Edge(int a, int b, float c)
	{
		u = a;
		v = b;
		w = c;
	}

	bool operator<(Edge aux)
	{
		return w < aux.w;
	}
};

float kruskal(vector<Edge> &E, int n)
{
	float ans = 0.f;
	sort(E.begin(), E.end());

	// Usando otro arreglo auxiliar
	for (int i = 0; i < n; ++i)
		makeSet(i);

	for (int i = 0; i < E.size(); ++i)
	{
		if (findSet(E[i].u) != findSet(E[i].v))
		{
			ans += E[i].w;
			unionSets(E[i].u, E[i].v);
		}
	}

	return ans;
}

int main()
{
	int cases, quantity;
	cin >> cases;

	for (int i = 0; i < cases; ++i)
	{
		cin >> quantity;
		vector<pair<float, float>> vec(quantity);

		for (int j = 0; j < quantity; ++j)
		{
			cin >> vec[j].first >> vec[j].second;
		}
		
		vector<Edge> graph;

		for (int j = 0; j < quantity - 1; ++j)
		{
			for (int k = j + 1; k < quantity; ++k)
			{
				graph.push_back(
					Edge(j, k,
						 sqrt(pow(vec[j].first - vec[k].first, 2) + pow(vec[j].second - vec[k].second, 2))));
			}
		}
		
		cout << setprecision(2) << fixed;
		cout << kruskal(graph, quantity) << endl;

		if (i + 1 != cases)
			cout << endl;
	}
	return 0;
}
