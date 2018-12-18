#include <bits/stdc++.h>

using namespace std;

vector<long long> vec(100001, 0);
long long DP[100001];

long long dpFun(int i){
	if(i == 0) return 0;
	if(i == 1) return vec[1];
	
	if(DP[i] != -1) return DP[i];
	
	return DP[i] = max(dpFun(i - 1), vec[i] * i + dpFun(i - 2));
}

int main() {
	int cant, temp, maximo = 0;
	cin >> cant;
	
	for(int i = 0; i < 100001; ++i) DP[i] = -1;
	
	for(int i = 0; i < cant; ++i){
		cin >> temp;
		maximo = max(maximo, temp);
		vec[temp]++;
	}
	
	cout << dpFun(maximo) << endl;
	
	return 0;
}
