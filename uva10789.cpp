#include <bits/stdc++.h>

using namespace std;

int p[2000];

int main()
{
	char linha[2010];
	vector<int> primos;
	primos.push_back(2);
	p[2] = 1;
	for(int i = 3; i < 2000; i+= 2)
	{
		bool eh = true;
		for(int it : primos)
			if(i % it == 0)
			{
				eh = false;
				break;
			}
		if(eh)
		{
			primos.push_back(i);
			p[i] = 1;
		}
	}
	int n, caso = 1;
	scanf("%d\n", &n);
	while(n--)
	{
		gets(linha);
		map<char, int> m;
		
		for(int i = 0; linha[i]; i++)
			m[linha[i]]++;
		int k = 0;
		printf("Case %d: ", caso++);
		for(auto it : m)
			if(p[it.second])
				k += printf("%c", it.first);
		if(!k)
			printf("empty");
		printf("\n");
	}
}
