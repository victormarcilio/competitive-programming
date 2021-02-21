#include <bits/stdc++.h>

using namespace std;

struct s
{
	char ori[30];
	string ordem;
};

int main()
{
	int t, k, n, j;
	char palavra[30];
	scanf("%d", &t);
	s palavras[1000];
	while(t--)
	{
		k = 0;
		scanf("%d\n", &n);
		while(n--)
		{
			gets(palavras[k].ori);
			palavras[k].ordem = palavras[k].ori;
			sort(palavras[k].ordem.begin(), palavras[k].ordem.end());
			k++;
		}
		while(gets(palavra), strcmp("END", palavra))
		{
			j = 0;
			string temp(palavra);
			sort(temp.begin(), temp.end());
			printf("Anagrams for: %s\n", palavra);
			for(int i = 0; i < k; i++)
				if(palavras[i].ordem == temp)
					printf("%3d) %s\n", ++j, palavras[i].ori);
			if(!j)
				printf("No anagrams for: %s\n", palavra);
		}
		gets(palavra);
		if(t)
			printf("\n");
	}
}
