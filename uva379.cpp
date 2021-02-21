#include <bits/stdc++.h>
#include <regex>
using namespace std;

// 0 - out of board; 1 - peg; 2 - empty
bool play(int grid[11][11])
{
	for (int i = 8; i > 1; i--)
		for (int j = 8; j > 1; j--)
			if (grid[i][j] == 2)
			{
				if (grid[i + 1][j] == 1 && grid[i + 2][j] == 1)
				{
					swap(grid[i][j], grid[i + 2][j]);
					grid[i + 1][j] = 2;
					return true;
				}
				if (grid[i][j + 1] == 1 && grid[i][j + 2] == 1)
				{
					swap(grid[i][j], grid[i][j + 2]);
					grid[i][j + 1] = 2;
					return true;
				}
				if (grid[i][j - 1] == 1 && grid[i][j - 2] == 1)
				{
					swap(grid[i][j], grid[i][j - 2]);
					grid[i][j - 1] = 2;
					return true;
				}
				if (grid[i - 1][j] == 1 && grid[i - 2][j] == 1)
				{
					swap(grid[i][j], grid[i - 2][j]);
					grid[i - 1][j] = 2;
					return true;
				}
			}
	return false;
}
int main()
{
	int n, k = 1;
	//freopen("C:/Users/slipn/Desktop/in", "r", stdin);
	//freopen("C:/Users/slipn/Desktop/out", "w", stdout);
	printf("HI Q OUTPUT\n");
	char linha[500];
	scanf("%d\n", &n);
	map<int, pair<int, int>> m;
	map<pair<int, int>, int> rm;
	for (int i = 0; i < 2; i++)
		for (int j = 2; j < 5; j++, k++)
		{
			m[k] = { i + 2, j + 2 };
			rm[{i + 2, j + 2}] = k;
		}
	for (int i = 2; i < 5; i++)
		for (int j = 0; j < 7; j++, k++)
		{
			m[k] = { i + 2, j + 2 };
			rm[{i + 2, j + 2}] = k;
		}

	for (int i = 5; i < 7; i++)
		for (int j = 2; j < 5; j++, k++)
		{
			m[k] = { i + 2, j + 2 };
			rm[{i + 2, j + 2}] = k;
		}
	while (n--)
	{
		int grid[11][11] = {{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
							{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
							{0, 0, 0, 0, 2, 2, 2, 0, 0, 0, 0},
							{0, 0, 0, 0, 2, 2, 2, 0, 0, 0, 0},
							{0, 0, 2, 2, 2, 2, 2, 2, 2, 0, 0},
							{0, 0, 2, 2, 2, 2, 2, 2, 2, 0, 0},
							{0, 0, 2, 2, 2, 2, 2, 2, 2, 0, 0},
							{0, 0, 0, 0, 2, 2, 2, 0, 0, 0, 0},
							{0, 0, 0, 0, 2, 2, 2, 0, 0, 0, 0},
							{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
							{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
		};
		int x;
		while (scanf("%d", &x), x)
			grid[m[x].first][m[x].second] = 1;

		while (play(grid));
		int res = 0;
		for (int i = 2; i < 9; i++)
			for (int j = 2; j < 9; j++)
				if (grid[i][j] == 1)
					res += rm[{i, j}];
		printf("%d\n", res);
	}
	printf("END OF OUTPUT\n");
}