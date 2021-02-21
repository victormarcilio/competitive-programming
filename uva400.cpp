#include <bits/stdc++.h>

using namespace std;

int main()
{	
	printf("------------------------------------------------------------\n");
	int n;
	char nome[100];
	
	while(~scanf("%d\n", &n))
	{
		//declarando essa string aqui dentro garante inicializacao com elas vazias
		//nos casos seguintes. (Se o N diminuisse no caso seguinte, a linha 39 acabaria
		//imprimindo strings de casos anteriores quando i + j*rows ultrapassar N)
		string arquivos[100];
		int L = 0;
		for(int i = 0 ; i < n; i++)
		{
			scanf("%s", nome);
			arquivos[i] = nome;
			L = max(L, (int)strlen(nome));
		}
		int columns = 1 + (60 - L)/(L + 2);
		
		sort(arquivos, arquivos + n);
		
		int rows = n/columns + (n%columns != 0);
		
		for(int i = 0; i < rows; i++)
		{
			int j = 0;
			for(; j < columns - 1; j++)
				printf("%-*s  ", L, arquivos[i + j*rows].c_str());
			printf("%-*s\n", L, arquivos[i + j*rows].c_str());
		}
		printf("------------------------------------------------------------\n");
	}
	
    return 0;
}
