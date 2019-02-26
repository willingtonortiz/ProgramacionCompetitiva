#include <bits/stdc++.h>

using namespace std;

string cad;
int DP[100005];

void iniciar(){

	DP[0] = 0;
	for(int i = 0; i < cad.size() - 1; ++i){
		int resp = (cad[i] == cad[i + 1]) ? 1 : 0;
		
		DP[i + 1] = DP[i] + resp;
	}
	
	DP[cad.size()] = DP[cad.size() - 1] + 1;

}

int dpFun(int left, int right){
	return DP[right - 1] - DP[left - 1];
}

int main() {
	int queries, left, right;
	cin >> cad;
	cin >> queries;

	iniciar();

	for(int i = 0; i < queries; ++i){
		cin >> left >> right;
		cout << dpFun(left, right) << endl;
	}

	return 0;
}
