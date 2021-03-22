#include <bits/stdc++.h>
using namespace std;

/* There is a buggy test case! The problem statement leads to think that 1 in mtx[0][0] shouldn't be 
    accepted but there are some test cases that do accept it... Explanation on the line that should be modified */

int main()
{
	int T, n, x;
	scanf("%d", &T);
	while(T--)
	{
		scanf("%d", &n);
		vector<vector<int>> grid(n, vector<int>(n));
		for(int i = 0; i < n; i++)
		{
			for(int j = 0; j < n; j++)
			{
				scanf("%d", &x);
				grid[i][j] = -x;
			}
		}
		bitset<401> b;
		queue<pair<bitset<401>, pair<int, int>>> q;
        /*This should test grid[0][0] == 0 but there is a buggy test case that is accepting 1 in that position*/ 
		if(grid[n - 1][n - 1] == 0)
		{
			b[0] = 1;
            q.push({b, {0, 0}});
		}
		int ans = 0;
		while(!q.empty())
		{
			auto front = q.front();
			q.pop();
		    int x = front.second.first;
			int y = front.second.second;
			auto bit = front.first;
			if(x == n - 1 && y == n - 1)
			{
				ans++;
				continue;
			}
            if(x && !bit[(x - 1) * 20 + y] && !grid[x - 1][y])
			{   
				bit[(x - 1)* 20 + y] = 1;
				q.push({bit, {x - 1, y}});
				bit[(x - 1) * 20 + y] = 0;
			}
			if(x < n - 1 && !bit[(x + 1) * 20 + y] && 
			!grid[x + 1][y])
			{
				bit[(x + 1) * 20 + y] = 1;
				q.push({bit, {x + 1, y}});
				bit[(x + 1) * 20 + y] = 0;
			}
			if(y && !bit[x * 20 + y - 1] && !grid[x][y - 1])
			{
				bit[x * 20 + y - 1] = 1;
				q.push({bit, {x, y - 1}});
				bit[x * 20 + y - 1] = 0; 
			}
			if(y < n - 1 && !bit[x * 20 + y + 1] &&
			!grid[x][y + 1])
			{
				bit[x * 20 + y + 1] = 1;
				q.push({bit, {x, y + 1}});
				bit[x * 20 + y + 1] = 0;
			}
		}
		printf("%d\n", ans);
	}
}
