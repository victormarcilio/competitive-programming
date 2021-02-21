#include <bits/stdc++.h>

using namespace std;

struct s
{
	int c;
	int v;
	
	bool operator<(s s2)
	{
		if(v != s2.v)
			return v < s2.v;
		return c > s2.c;
	}
	
	s(int C, int V)
	{
		c = C;
		v = V;
	}
};

int main()
{
	char linha[1010];
	int primeiro = true;
	while(gets(linha))
	{	
		if(!primeiro)
			printf("\n");
		primeiro = false;
		map<char, int> m;
		vector<s> v;
		
		for(int i = 0; linha[i]; i++)
		{
			if(m.find(linha[i]) == m.end())
			{
				m[linha[i]] = m.size();
				v.push_back(s(linha[i], 1));
			}
			else
				v[m[linha[i]]].v++;
		}
		sort(v.begin(), v.end());
		for(auto it : v)
			printf("%d %d\n", it.c, it.v);
	}
	return 0;
}
