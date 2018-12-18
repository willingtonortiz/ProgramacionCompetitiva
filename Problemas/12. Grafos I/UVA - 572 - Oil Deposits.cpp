#include <bits/stdc++.h>

using namespace std;

vector<string> arr;
bool vis[101][101];
int m, n, x, y;
int px[] = { -1, 0, 1, -1, 1, -1, 0, 1 };
int py[] = { -1, -1, -1, 0, 0, 1, 1, 1 };

void dfs(int yPos, int xPos){
	if(vis[yPos][xPos]) return;
	vis[yPos][xPos] = true;
	
	for(int i = 0; i < 8; ++i){
		y = yPos + py[i];
		x = xPos + px[i];
		
		if(x >= 0 && y >= 0 && x < n && y < m && arr[y][x] == '@'){
			dfs(y, x);
		}
	}
}

int main() {
	string s;
	
	while(true){
		cin >> m >> n;
		if(m == 0 || n == 0) break;
		
		arr.clear();
		for(int i = 0; i < m; ++i){
			cin >> s;
			arr.push_back(s);
		}
		
		for(int i = 0; i < 100; ++i) for(int j = 0; j < 100; ++j) vis[i][j] = false;
		
		int cont = 0;
		
		for(int i = 0; i < m; ++i){
			for(int j = 0; j < n; ++j){
				if(!vis[i][j]){
					if(arr[i][j] == '@'){
						cont++;
						dfs(i, j);
					}
				}
			}
		}
		cout << cont << endl;
	}
	return 0;
}
