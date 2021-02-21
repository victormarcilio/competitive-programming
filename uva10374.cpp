#include <bits/stdc++.h>

using namespace std;
int main()
{
	int n, t;
	char nome[300], partido[300];
	scanf("%d", &t);
	while(t--)
	{
		scanf("%d\n", &n);
		map<string, string> m;
		map<string, int> votos;
		for(int i = 0; i < n; i++)
		{
			gets(nome);
			gets(partido);
			m[nome] = partido;
		}
		scanf("%d\n", &n);
		for(int i = 0; i < n; i++)
		{
			gets(nome);
			votos[nome]++;
		}
		int maior = 0;
		int cont = 0;
		string venc;
		for(auto it : votos)
		{
			if(it.second > maior)
			{
				cont = 1;
				maior = it.second;
				venc = it.first;
			}
			else if(it.second == maior)
				cont++;
		}
		if(cont != 1)
			printf("tie\n");
		else
			printf("%s\n", m[venc].c_str());
		if(t)
			printf("\n");
	}
	return 0;
}
