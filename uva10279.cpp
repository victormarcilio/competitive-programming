#include <bits/stdc++.h>

using namespace std;

int main()
{
	int t, n, pos[] = {1, 0, -1};
	vector<int> v(pos, pos + 3);
	char grid[15][15], grid2[15][15];
	
	scanf("%d", &t);
	while(t--)
	{
		memset(grid, '.', sizeof grid);
		memset(grid2, '.', sizeof grid2);
		scanf("%d\n", &n);
		for(int i = 1; i <= n; i++)
			gets(&grid[i][1]);
		for(int i = 1; i <= n; i++)
			gets(&grid2[i][1]);
		
		bool explodiu = false;
		for(int i = 1; i <= n; i++)
			for(int j = 1; j <= n; j++)
				if(grid[i][j] == '*' && grid2[i][j] == 'x')
				{
					explodiu = true;
					goto prox;
				}
		prox:
		for(int i = 1; i <= n; i++)
		{
			for(int j = 1; j <= n; j++)
				if(explodiu && grid[i][j] == '*')
					printf("*");
				else if(grid2[i][j] == 'x')
				{
					int minas = 0;
					for(auto x : v)
						for(auto y : v)
							minas += (grid[i + x][j + y] == '*');
					printf("%d", minas);
				}
				else
					printf(".");
			printf("\n");
		}
		if(t)
			printf("\n");
	}
    return 0;
}
