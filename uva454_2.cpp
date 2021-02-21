#include <bits/stdc++.h>
/* 
Problema podre:
	Leitura muito sebosa...
*/
using namespace std;

struct st
{
	string s1, s2;
	
	bool operator == (st outra) const
	{
		return s2 == outra.s2;
	}	
	
	bool operator < (st outra ) const
	{
		return s1 < outra.s1;
	}
};

int main()
{
	int n,i, j, k;
	char palavra[150], temp[150];
	st palavras[110];
	scanf("%d\n", &n);

	while(n--)
	{
		k = 0;
		
		while(gets(palavra), palavra[0] && !feof(stdin))
		{	
			
			palavras[k].s1 = palavra;
			for(i = 0, j = 0; palavra[i]; i++)
				if(isalpha(palavra[i]))
					temp[j++] = palavra[i];
			temp[j] = 0;
			palavras[k].s2 = temp;
			
			sort(palavras[k].s2.begin(), palavras[k].s2.end());
			k++;			
		}
		sort(palavras, palavras + k);
		for(i = 0; i < k; i++)
			for(j = i + 1; j < k; j++)
				if(palavras[i] == palavras[j])
					printf("%s = %s\n", palavras[i].s1.c_str(), palavras[j].s1.c_str());
		if(n)
			printf("\n");
	}
}
