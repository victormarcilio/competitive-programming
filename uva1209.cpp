#include <bits/stdc++.h>

using namespace std;

int main()
{	
	char nome[100], nome2[100];
	while(gets(nome))
	{
		strcpy(nome2, nome);
		int ans = -1;
		int tam = strlen(nome);
		string res;
		
		int minimo = 5000;
		for(int j = 1; nome2[j]; j++)
			minimo = min(abs(nome2[j] - nome2[j - 1]), minimo);
		if(minimo > ans)
		{
			ans = minimo;
			res = nome2;
		}
		
		for(int i = 0; i < 10; i++)
		{
			prev_permutation(nome2, nome2 + tam);
			int minimo = 5000;
			for(int j = 1; nome2[j]; j++)
				minimo = min(abs(nome2[j] - nome2[j - 1]), minimo);
			if(minimo > ans)
			{
				ans = minimo;
				res = nome2;
			}
			if(minimo == ans && res > nome2)
				res = nome2;
		}
		
		for(int i = 0; i < 10; i++)
		{
			next_permutation(nome, nome + tam);
			int minimo = 5000;
			for(int j = 1; nome[j]; j++)
				minimo = min(abs(nome[j] - nome[j - 1]), minimo);
			if(minimo > ans)
			{
				ans = minimo;
				res = nome;
			}
			if(minimo == ans && res > nome)
				res = nome;
		}
		printf("%s%d\n", res.c_str(), ans);
		
	}
    return 0;
}
