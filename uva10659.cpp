#include<bits/stdc++.h>
using namespace std;

/* Cada linha deve ser mantida separada (não pode tentar trazer uma palavra da linha N + 1 para linha N */

int main() {
    int n, m, x, y;
	scanf("%d", &n);
	char linha[100000];
	prox: while(n--)
	{
		vector <string> input[500];
		scanf("%d%*c", &m);
		for(int i = 0; i < m; i++)
		{
			gets(linha);
			char *p = strtok(linha, " ");
			while(p)
			{
				input[i].push_back(p);
				p = strtok(NULL, " ");
			}
		}
		scanf("%d %d\n", &x, &y);
		for(int fonte = 28; fonte > 7; fonte--)
		{
			int soma = 0;
			bool possivel;
			for(int j = 0; j < m; j++)
			{
				int linha = 1;
				int pos = input[j][0].size()*fonte;
				possivel = input[j][0].size()*fonte <= x;
				if(input[j].size() > 1)
				{
					if(pos + fonte <= x)
						pos += fonte;
					else
					{
						linha++;
						pos = 0;
					}
				}
				
				for(int i = 1; possivel && i < input[j].size(); i++)
				{
					if(input[j][i].size()*fonte > x)
					{
						possivel = false;
						break;
					}				
					else if(pos + input[j][i].size()*fonte <= x)
						pos = pos + input[j][i].size()*fonte;
					else
					{
						linha++;
						pos = input[j][i].size()*fonte;
					}
					if(i + 1 < input[j].size())
					{
						if(pos + fonte <= x)
							pos += fonte;
						else
						{
							linha++;
							pos = 0;
						}
					}
				}
				if(!possivel)
					break;
				soma += linha;
			}
			if(possivel && soma*fonte <= y)
			{
				printf("%d\n", fonte);
				goto prox;
			}
		}
		
		printf("No solution\n");
	}
    return 0;
}
