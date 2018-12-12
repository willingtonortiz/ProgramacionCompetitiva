#include <bits/stdc++.h>

using namespace std;

const int MAXIMO = 10;

vector<int> vec[MAXIMO];
bool vis[MAXIMO][MAXIMO];
int yy[] = {-1,-1,-1,0,0,1,1,1};
int xx[] = {-1,0,1,-1,1,-1,0,1};
int m, n, px, py;

int dfs(int y, int x){
    if(vis[y][x]) return 0;
    vis[y][x] = true;
    int suma = 0;
    for(int i = 0; i < 8; ++i){
        py = y + yy[i];
        px = x + xx[i];
        if(px >= 0 && px < m && py >= 0 && py < n && vec[py][px] == 1){
            suma += dfs(py, px);
        }
    }
    return suma + 1;
}


int main(){
    int resp = 0;
    cin >> n >> m;

    for(int i = 0; i < MAXIMO; ++i){
        for (int j = 0; j < MAXIMO; ++j){
            vis[i][j] = false;
            vec[i].push_back(-1);
        }
    }

    for(int i = 0; i < n; ++i){
        for (int j = 0; j < m; ++j){
            cin >> vec[i][j];
        }
    }

    int xd;
    for(int i = 0; i < n; ++i){
        for (int j = 0; j < m; ++j){
            if(!vis[i][j] && vec[i][j] == 1){
                resp = max(resp, dfs(i, j));
            }
        }
    }
    cout << resp << endl;

    return 0;
}
