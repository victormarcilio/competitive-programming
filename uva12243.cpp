#include <bits/stdc++.h>
#include <regex>
using namespace std;

int main()
{
	//freopen("C:/Users/slipn/Desktop/in", "r", stdin);
	//freopen("C:/Users/slipn/Desktop/out", "w", stdout);
	char frase[5000];
	prox: while (scanf("%[^\n]\n", frase), strcmp(frase, "*"))
	{
		char *p = strtok(frase, " ");
		char c = tolower(*p);
		while (p)
		{
			if (tolower(*p) != c)
			{
				printf("N\n");
				goto prox;
			}
			p = strtok(NULL, " ");
		}
		printf("Y\n");
	}
	
}