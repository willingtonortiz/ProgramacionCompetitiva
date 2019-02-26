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

int kruskal(vector<Edge> &E, int n)
{
	int ans = 0.f;
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