#include <bits/stdc++.h>

using namespace std;

int digital_root(int n)
{
	int sum;

	while (n > 9)
	{

		sum = 0;

		while (n > 0)
		{
			sum += n % 10;
			n /= 10;
		}
		n = sum;
	}
	return sum;
}

int main()
{
	int n;
	cin >> n;

	cout << digital_root(n) << endl;

	return 0;
}