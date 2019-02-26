#include <bits/stdc++.h>

using namespace std;

/*
	Generar todas las configuraciones (posibilidades) de n elementos usando numeros del 1 al m
*/

int m, n;
int conf[10];

void bt(int pos)
{
	if (pos == n)
	{
		for (int i = 0; i < n; ++i)
		{
			cout << conf[i];
		}
		cout << endl;
		return;
	}
	for (int i = 1; i <= m; ++i)
	{
		conf[pos] = i;
		bt(pos + 1);
		conf[pos] = 0;
	}
}

int main()
{

	cin >> m >> n;

	bt(0);

	return 0;
}
