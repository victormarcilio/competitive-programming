//https://www.hackerearth.com/practice/math/number-theory/primality-tests/practice-problems/algorithm/primestring/
#include <iostream>
#include <string>
#include <vector>
#include<map>
#include<algorithm>
#include <set>
#include <bitset>
using namespace std;

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	int t;
	string s;
	cin >> t;

	bitset<100001> b;
	b.set();
	b[1] = false;
	for (int i = 4; i < 100001; i += 2)
		b[i] = false;
	for (int i = 3; i < 100001; i += 2)
		if (b[i])
			for (int j = 3 * i, inc = 2 * i; j < 100001; j += inc)
				b[j] = false;
	while (t--)
	{
		cin >> s;
		map<char, int> m;
		for (auto c : s)
			m[c]++;
		bool eh = b[m.size()];
		for (const auto& it : m)
			eh &= b[it.second];
		if (eh)
			cout << "YES\n";
		else
			cout << "NO\n";
	}
}
