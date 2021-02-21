#include <bits/stdc++.h>
#include <regex>
using namespace std;

int main()
{
	//freopen("C:/Users/slipn/Desktop/in", "r", stdin);
	//freopen("C:/Users/slipn/Desktop/out", "w", stdout);
	int n, days, r, c;
	char grid[2][102][102];
	scanf("%d", &n);
	while (n--)
	{
		int pos = 0;
		memset(grid, 0, sizeof grid);
		scanf("%d %d %d\n", &r, &c, &days);
		for (int i = 1; i <= r; i++)
			scanf("%s", &grid[0][i][1]);
		while (days--)
		{
			for (int i = 1; i <= r; i++)
				for (int j = 1; j <= c; j++)
					if (grid[pos][i][j] == 'R')
						if (grid[pos][i - 1][j] == 'P' || grid[pos][i + 1][j] == 'P' || grid[pos][i][j + 1] == 'P' || grid[pos][i][j - 1] == 'P')
							grid[!pos][i][j] = 'P';
						else
							grid[!pos][i][j] = 'R';
					else if(grid[pos][i][j] == 'P')
						if (grid[pos][i - 1][j] == 'S' || grid[pos][i + 1][j] == 'S' || grid[pos][i][j + 1] == 'S' || grid[pos][i][j - 1] == 'S')
							grid[!pos][i][j] = 'S';
						else
							grid[!pos][i][j] = 'P';
					else if (grid[pos][i - 1][j] == 'R' || grid[pos][i + 1][j] == 'R' || grid[pos][i][j + 1] == 'R' || grid[pos][i][j - 1] == 'R')
						grid[!pos][i][j] = 'R';
					else
						grid[!pos][i][j] = 'S';
			pos = !pos;
		}
		for (int i = 1; i <= r; i++)
			printf("%s\n", &grid[pos][i][1]);
		if (n)
			printf("\n");
	}
}