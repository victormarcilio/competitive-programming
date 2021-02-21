#include <bits/stdc++.h>

using namespace std;

int main()
{
	int t, n, k;
	int mtx[101][53], deck[53], deck2[53];
	char num[10];
	char naipe[][10] = {"Clubs", "Diamonds", "Hearts", "Spades"};
	scanf("%d", &t);
	bool primeira = true;
	while(t--)
	{
		if(!primeira)
			printf("\n");
		primeira = false;
		scanf("%d", &n);
		for(int i = 1; i <= n; i++)
		{
			for(int j = 1; j < 52; j++)
				scanf("%d", &mtx[i][j]);
			scanf("%d\n", &mtx[i][52]);
		}
		
		for(int i = 1; i < 53; i++)
			deck[i] = i;
		
		// Gambiarra pro espaço em branco entre casos, o else pega o ultimo caso que não tem esse espaço
		if(t)
			while(gets(num), num[0])
			{
				k = atoi(num);
				for(int i = 1; i < 53; i++)
					deck2[i] = deck[i];
				for(int i = 1; i < 53; i++)
					deck[i] = deck2[mtx[k][i]];
			}
		else
			while(gets(num))
			{
				k = atoi(num);
				for(int i = 1; i < 53; i++)
					deck2[i] = deck[i];
				for(int i = 1; i < 53; i++)
					deck[i] = deck2[mtx[k][i]];
			}
		
		for(int i = 1; i < 53; i++)
		{
			int valor = (deck[i] - 1)%13;
			int naip = (deck[i] - 1)/13;
			if(valor == 12)
				printf("Ace");
			else if(valor == 11)
				printf("King");
			else if(valor == 10)
				printf("Queen");
			else if(valor == 9)
				printf("Jack");
			else
				printf("%d", valor + 2);
			printf(" of %s\n", naipe[naip]);
		}
	}
}
