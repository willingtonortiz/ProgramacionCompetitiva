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