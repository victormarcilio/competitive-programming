
#include <bits/stdc++.h>
using namespace std;

char dir;
int grid[100][100];
int c[5], steps[100][100], n, m, x, y;
char turn[300];

void next()
{
	while (1)
	{
		switch (dir)
		{
		case 'e':
			if (!grid[x + 1][y])
			{
				x++;
				dir = 's';
				return;
			}
			if (!grid[x][y + 1])
			{
				y++;
				return;
			}
			break;
		case 'w':
			if (!grid[x - 1][y])
			{
				x--;
				dir = 'n';
				return;
			}
			if (!grid[x][y - 1])
			{
				y--;
				return;
			}
			break;
		case 'n':
			if (!grid[x][y + 1])
			{
				y++;
				dir = 'e';
				return;
			}
			if (!grid[x - 1][y])
			{
				x--;
				return;
			}
			break;
		case 's':
			if (!grid[x][y - 1])
			{
				y--;
				dir = 'w';
				return;
			}
			if (!grid[x + 1][y])
			{
				x++;
				return;
			}
			break;
		}
		dir = turn[dir];
	}

}

int main()
{
	//freopen("C:/Users/slipn/Desktop/in", "r", stdin);
	//freopen("C:/Users/slipn/Desktop/out", "w", stdout);
	turn['w'] = 's'; turn['s'] = 'e'; turn['e'] = 'n'; turn['n'] = 'w';
	while (scanf("%d %d", &n, &m), n)
	{
		memset(grid, 1, sizeof grid);
		memset(c, 0, sizeof c);
		memset(steps, 0, sizeof steps);
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= m; j++)
				scanf("%1d", &grid[i][j]);

		dir = 'e';
		x = n;
		y = 1;

		while (1)
		{
			steps[x][y]++;
			next();
			if (x == n && y == 1)
				break;
		}

		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= m; j++)
				if(!grid[i][j])
					c[steps[i][j]]++;
		for (int i = 0; i < 5; i++)
			printf("%3d", c[i]);
		printf("\n");
	}
}

