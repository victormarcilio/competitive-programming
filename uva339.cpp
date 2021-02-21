#include <bits/stdc++.h>
#include <regex>
using namespace std;

/*	No o debug tão imprimindo espaços em brancos referente as colunas apagadas... 
	Aparentemente não tem Presentation error com relação a isso
*/

bool check(vector<vector<int>> &v, int x, int y)
{
	return v[x][y] == v[x - 1][y] || v[x][y] == v[x + 1][y] || v[x][y] == v[x][y + 1] || v[x][y] == v[x][y - 1];
}

void destroy(vector<vector<int>> &v, int x, int y)
{
	int val = v[x][y];
	v[x][y] = 10;
	
	if (val == v[x - 1][y])
		destroy(v, x - 1, y);
	if (val == v[x + 1][y])
		destroy(v, x + 1, y);
	if (val == v[x][y - 1])
		destroy(v, x, y - 1);
	if (val == v[x][y + 1])
		destroy(v, x, y + 1);
	bool mudou = true;
	while (mudou)
	{
		mudou = false;
		for(int j = 1; v[j + 1][y] != 11; j++)
			if (v[j][y] < 10 && v[j + 1][y] == 10)
			{
				mudou = true;
				swap(v[j][y], v[j + 1][y]);
			}
	}
}

int main()
{
	//freopen("C:/Users/slipn/Desktop/in", "r", stdin);
	//freopen("C:/Users/slipn/Desktop/out", "w", stdout);
	int m, n, x, y, cont = 1;
	bool primeira = true;
	while (scanf("%d %d", &m, &n), m)
	{
		if (!primeira)
			printf("\n");
		primeira = false;
		vector<vector<int>> grid(m + 2, vector<int>(n + 2, 11));
		for(int i = m; i ; i--)
			for (int j = 1; j <= n; j++)
			{
				scanf("%d", &x);
				grid[i][j] = x;
			}
		while (scanf("%d %d", &x, &y), x)
		{
			if (x > m || y > n)
				continue;
			x = m - x + 1;
			if (grid[x][y] > 9)
				continue;
			if (check(grid, x, y))
			{
				destroy(grid, x, y);
				for(int k = 1; k < n; k++)
					if (grid[m][k] == 10)
					{
						for (int i = 1; i <= m; i++)
							grid[i].erase(grid[i].begin() + k);
						n--;
						k--;
					}
			}
		}
		printf("Grid %d.\n", cont++);
		if (grid[m][1] == 10)
			printf("    Game Won\n");
		else
		{
			for (int i = 1; i <= m; i++)
			{
				printf("    %c", grid[i][1] == 10 ? ' ' : grid[i][1] + '0');
				for (int j = 2; j <= n; j++)
					printf(" %c", grid[i][j] == 10 ? ' ' : grid[i][j] + '0');
				printf("\n");
			}
		}
	}
}