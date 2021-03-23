// https://www.hackerearth.com/pt-br/problem/algorithm/flood-fill-algorithm/

#include<bits/stdc++.h>
using namespace std;
int grid[12][12];
int main()
{
	int t, n, m, x1, y1, x2, y2;
	cin >> t;
	while(t--)
	{
		memset(grid, 0, sizeof grid);
		cin >> n >> m >> x1 >> y1 >> x2 >> y2;

		for(int i = 1; i <= n; i++)
			for(int j = 1; j <= m; j++)
				cin >> grid[i][j];
		
		queue<pair<int, int>> q;
		q.push({x1, y1});
		set<pair<int, int>> visited;
		visited.insert({x1, y1});
		while(!q.empty())
		{
			auto front = q.front();
			q.pop();
			int x = front.first;
			int y = front.second;
			if(grid[x - 1][y] > grid[x][y])
			{
				q.push({x - 1, y});
				visited.insert({x - 1, y});
			}
			if(grid[x + 1][y] > grid[x][y])
			{
				q.push({x + 1, y});
				visited.insert({x + 1, y});
			}
			if(grid[x][y - 1] > grid[x][y])
			{
				q.push({x, y - 1});
				visited.insert({x, y - 1});
			}
			if(grid[x][y + 1] > grid[x][y])
			{
				q.push({x, y + 1});
				visited.insert({x, y + 1});
			}
		}
		printf("%s\n", visited.count({x2, y2}) ? "YES" : "NO");
	}
}
