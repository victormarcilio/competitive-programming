#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, x;
	cin >> n;
	map<int, int> m;
	while(n--)
	{
		cin >> x;
		m[x]++;
	}
	x = 1, n = 0;
	for(auto it : m)
	{
		n += x * it.second;
		x++;
	}
	cout << n << '\n';
}
