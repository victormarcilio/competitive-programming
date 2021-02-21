#include <bits/stdc++.h>

using namespace std;
int mtx[2][22][22];

int soma(int pos, int i, int j)
{
	return mtx[pos][i - 1][j] + mtx[pos][i + 1][j] + mtx[pos][i - 1][j - 1] + 
	mtx[pos][i - 1][j + 1] + mtx[pos][i + 1][j - 1] + mtx[pos][i + 1][j + 1] + 
	mtx[pos][i][j + 1] + mtx[pos][i][j - 1];
}
int main()
{
	int n, a, b, years;
	
	char linha[10];
	scanf("%d", &n);

	while(n--)
	{
		printf("********************\n");
		scanf("%d\n", &years);
		memset(mtx, 0, sizeof mtx);
		int pos = 0;
		while(gets(linha), !feof(stdin) && linha[0])
		{
			sscanf(linha, "%d %d", &a, &b);
			mtx[pos][a][b] = 1;
		}
		for(int i = 0; i < years; i++)
		{
			for(int j = 1; j <= 20; j++)
			{
				for(int k = 1; k <= 20; k++)
				{
					printf("%c", mtx[pos][j][k] ? 'O' : ' ');
					int x = soma(pos, j, k);
					if(!mtx[pos][j][k])
						mtx[!pos][j][k] = (x == 3);
					else
						mtx[!pos][j][k] = (x == 2 || x == 3);
					
				}
				printf("\n");
			}
			pos = !pos;
			printf("********************\n");
		}
		if(n)
			printf("\n");
	}
}
