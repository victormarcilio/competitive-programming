#include <bits/stdc++.h>

using namespace std;

int main()
{
	int n, dna[10], codigo[2][42], pos;
	scanf("%d", &n);
	int mapa[200];
	mapa[3] = 'W'; mapa[2] = 'x'; mapa[1] = '.'; mapa[0] = ' ';
	while(n--)
	{
		for(int i = 0; i < 10; i++)
			scanf("%d", dna + i);
		pos = 0;
		memset(codigo, 0, sizeof codigo);
		codigo[pos][20] = 1;
		for(int i = 0; i < 50; i++)
		{
			for(int j = 1; j <= 40; j++)
			{
				printf("%c", mapa[codigo[pos][j]]);
				codigo[!pos][j] = dna[(codigo[pos][j -1] + codigo[pos][j] + codigo[pos][j + 1])%10];
			}
			pos = !pos;
			printf("\n");
		}
		if(n)
			printf("\n");
	}
}
