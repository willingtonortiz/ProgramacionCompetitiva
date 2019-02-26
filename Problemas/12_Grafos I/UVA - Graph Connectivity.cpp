#include <bits/stdc++.h>

using namespace std;

const int MAX_V = 100000;
vector<int> adj[MAX_V + 1];
bool vis[MAX_V + 1];

void dfs(int u){
	if(vis[u]) return;
	vis[u] = true;
	int sz = adj[u].size();
	for(int i = 0; i < sz; ++i){
		int v = adj[u][i];
		dfs(v);
	}
}

int main() {
	int casos, maximo, x, y, resp;
	string cad;
	string letra;

	cin >> casos;
	getline(cin, cad);
	getline(cin, cad);

	for(int i = 0; i < casos; ++i){

		getline(cin, letra);
		for(int i = 1; i <= (letra[0] - 64); ++i){
			adj[i] = vector<int>();
			vis[i] = false;
		}

		while(true){
			getline(cin, cad);
			if(cad == "") break;
			x = cad[0] - 64;
			y = cad[1] - 64;
			// cout << x << " " << y << endl;

			adj[x].push_back(y);
			adj[y].push_back(x);
		}
		resp = 0;
		
		/*for(int i = 1; i <= (letra[0] - 64); ++i){
			cout << "L-" << i << ": ";
			for(int j = 0; j < adj[i].size(); ++j){
				cout << adj[i][j] << "\t";
			}
			cout << endl;
		}*/
	
		for(int i = 1; i <= (letra[0] - 64); ++i){
			if(!vis[i]){
				// cout << i << endl;
				dfs(i);
				resp++;
			}
		}
		cout << resp << endl;
		if(i + 1 != casos) cout << endl;
	}

	return 0;
}
