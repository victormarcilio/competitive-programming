#include <bits/stdc++.h>

using namespace std;

int gcd(int a, int b) 
{
	while (b) 
	{
		a %= b;
		swap(a, b);
	}
	return a;
}


unsigned int fatnk(int n, map<char, int> &k)
{
	vector<int> cima, baixo;
	for (int i = 2; i <= n; i++)
		cima.push_back(i);
	for (auto it : k)
		if (it.second > 1)
			for (int i = 2; i <= it.second; i++)
				baixo.push_back(i);
	for (int i = 0; i < cima.size(); i++)
		for (int j = 0; j < baixo.size(); j++)
		{
			if (cima[i] == 1)
				break;
			if (baixo[j] == 1)
				continue;
			int d = gcd(cima[i], baixo[j]);
			if (d == 1) 
				continue;
			cima[i] /= d;
			baixo[j] /= d;
		}
	unsigned int res = 1;
	for (auto it : cima)
		res *= it;
	return res;
}
unsigned int counting(string &s, char start)
{
	map<char, int> m;
	m[start] = -1;
	for (auto i : s)
		m[i]++;

	return fatnk(s.size() - 1, m);
}

int main()
{
	//freopen("C:/Users/slipn/Desktop/in", "r", stdin);
	//freopen("C:/Users/slipn/Desktop/out", "w", stdout);
	
	char palavra[101000];
	while (scanf("%s\n", palavra), strcmp(palavra, "#"))
	{
		string sorted(palavra);
		string p(palavra);
		sort(sorted.begin(), sorted.end());
		
		unsigned int res = 1;
		for (auto c : p)
		{
			set<char> s;
			for (int i = 0; ; i++)
				if (sorted[i] == c)
				{
					for (auto ch : s)
						res += counting(sorted, ch);
					sorted.erase(i, 1);
					break;
				}
				else
					s.insert(sorted[i]);

		}
		printf("%10u\n", res);
	}
}