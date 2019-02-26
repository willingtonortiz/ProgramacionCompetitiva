#include <bits/stdc++.h>

using namespace std;

const int MAXG = 1000000;
vector<int> graph[MAXG + 1];
bool vis[MAXG + 1];

void dfs(int cur){
	if(vis[cur]) return;
	vis[cur] = true;

	int size = graph[cur].size();
	for(int i = 0; i < size; ++i){
		int v = graph[cur][i];
		dfs(v);
	}
}
