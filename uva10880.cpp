#include <bits/stdc++.h>

using namespace std;

bitset<1000010> b;
set<long long> s;
void f(long long valor, int ind, int r, vector<int> &fatores)
{
	if(ind == fatores.size())
	{
		if(valor > r)
			s.insert(valor);
		return;
	}
	f(valor, ind + 1, r, fatores);
	f(valor * fatores[ind], ind + 1, r, fatores);
}

int main()
{	
	b.set();
	vector<int> primos;
	primos.push_back(2);
	
	for(int i = 2; i < 1000010; i+= 2)
		b.reset(i);
	
	for(int i = 3; i < 1000010; i+= 2)
		if(b[i])
		{
			primos.push_back(i);			
			for(int inc = i << 1, j = i + inc; j < 1000010; j += inc)
				b.reset(j);
		}
		
	int n, c, r, caso = 1;
	scanf("%d", &n);
	while(n--)
	{
		scanf("%d %d", &c, &r);
		printf("Case #%d:", caso++);
		if(r == c)
			 printf(" 0");
		else
		{
			int d = c - r;
			int i;
			vector<int> fatores;
			for(i = 0; i < primos.size() && d > 1; i++)
				while(d%primos[i] == 0)
				{
					fatores.push_back(primos[i]);
					d = d/primos[i];
				}
			if(d > 1)
				fatores.push_back(d);
			s.clear();
			f(1, 0, r, fatores);
			for(auto it : s)
				printf(" %lld", it);
		}
		printf("\n");
	}
	
    return 0;
}
