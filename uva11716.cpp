#include <bits/stdc++.h>

using namespace std;
int main()
{
	int n;
	char linha[10010];
	scanf("%d\n", &n);
	prox: while(n--)
	{
		gets(linha);
		int tam = strlen(linha);
		for(int i = 1; i <= 100; i++)
			if(i*i == tam)
			{
				for(int j = 0; j < i; j++)
					for(int k = 0; k < i; k++)
						printf("%c", linha[j + k*i]);
				printf("\n");
				goto prox;
			}
		
		printf("INVALID\n");
	}
    return 0;
}
