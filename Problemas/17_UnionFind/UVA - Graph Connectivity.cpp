// https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&category=&problem=400&mosmsg=Submission+received+with+ID+22485175

#include <bits/stdc++.h>

using namespace std;

const int MAXGRAPH = 1000;

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
	int u, v, w;
	/*
	* u: vértice inicial
	* v: vértice final
	* w: peso entre vértices
	*/

	Edge() {}

	Edge(int a, int b, int c)
	{
		u = a, v = b, w = c;
	}

	// Ordenamiento de menor a mayor arista
	bool operator<(Edge aux) const
	{
		return w < aux.w;
	}
};

int kruskal(vector<Edge> &E, int n)
{
	int ans = 0;
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

int main() {
	int cases, cantVert;
	string s;
	cin >> cases;
	
	// El espacio en blanco
	getline(cin, s);
	getline(cin, s);
	
	for(int i = 0; i < cases; ++i){
		
		getline(cin, s);
		cantVert = s[0] - 64;
		// cout << s << endl;
		
		for(int j = 0; j < cantVert; ++j){
			makeSet(j);
		}
		
		while(true){
			getline(cin, s);
			if(s == "") break;
			
			unionSets(s[0] - 65, s[1] - 65);
		}
		
		int resp = 0;
		
		for(int j = 0; j < cantVert; ++j){
			// cout << j << " " << parent[j] << endl;
			if(j == parent[j]){
				resp++;
			}
		}
		
		cout << resp << endl;
		
		if(i + 1 != cases){
			cout << endl;
		}
		
	}
	
	return 0;
}