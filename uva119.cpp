#include <bits/stdc++.h>

using namespace std;

int main()
{
	int n, money, k, v;
	char nomes[10][15], nome[15];
	bool primeiro = true;
	while(scanf("%d\n", &n) != EOF)
	{
		if(!primeiro)
			printf("\n");
		primeiro = false;
		map <string, int> m;
		for(int i = 0; i < n; i++)
			scanf("%s ", nomes[i]);
		
		for(int i = 0; i < n; i++)
		{
			scanf("%s %d %d", nome, &money, &k);
			if(k)
				m[nome] -= (money - money%k);
		
			v = k ? money/k : 0;
			for(int j = 0; j < k; j++)
			{
				scanf("%s ", nome);
				m[nome] += v;
			}
		}
		for(int i = 0; i < n; i++)
			printf("%s %d\n", nomes[i], m[nomes[i]]);
	}
	
}
