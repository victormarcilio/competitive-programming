#include <bits/stdc++.h>
#include <regex>
using namespace std;
bool check(char grid[][4], char c)
{
	int i, j;
	
	for (i = 0; i < 3; i++)
	{
		//linha
		for (j = 0; j < 3 && grid[i][j] == c; j++);
		if (j == 3) return true;

		//coluna
		for (j = 0; j < 3 && grid[j][i] == c; j++);
		if (j == 3) return true;
	}

	//diagonal principal
	for (i = 0; i < 3 && grid[i][i] == c; i++);
	if (i == 3)
		return true;
	//diagonal secundaria
	for (i = 0; i < 3 && grid[2 - i][i] == c; i++);
	if (i == 3)
		return true;

	return false;
}
int main()
{
	//freopen("C:/Users/slipn/Desktop/in", "r", stdin);
	//freopen("C:/Users/slipn/Desktop/out", "w", stdout);
	int n;
	char grid[3][4];
	scanf("%d\n", &n);
	while (n--)
	{
		scanf("%s%s%s", grid[0], grid[1], grid[2]);
		int x = 0, o = 0;
		for (int i = 0; i < 3; i++)
			for (int j = 0; j < 3; j++)
				if (grid[i][j] == 'X')
					x++;
				else if (grid[i][j] == 'O')
					o++;

		bool xwon = check(grid, 'X');
		bool owon = check(grid, 'O');

		if ((xwon && owon) || (xwon && x != o + 1) || (owon && x != o) || (x > o + 1) || (o > x))
			printf("no\n");
		else
			printf("yes\n");
	}
}