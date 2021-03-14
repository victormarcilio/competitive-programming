#include <bits/stdc++.h>
using namespace std;

char grid[1027][1027];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int N, M;
    scanf("%d %d\n", &N, &M);
    for(int i = 1; i <= N; i++)
        gets(&grid[i][1]);
    int ans = 0;
    for(int i = 1; i <= N; i++)
        for(int j = 1; j <= M; j++)
            if(grid[i][j] == '.')
            {
                queue<pair<int, int>> q;
                q.push({i, j});
                ans++;
                grid[i][j] = 0;
                while(!q.empty())
                {
                    auto front = q.front();
                    q.pop();
                    int x = front.first, y = front.second;
                    if(grid[x - 1][y] == '.')
                    {
                        grid[x - 1][y] = 0;
                        q.push({x - 1, y});
                    }
                    if(grid[x + 1][y] == '.')
                    {
                        grid[x + 1][y] = 0;
                        q.push({x + 1, y});
                    }
                    if(grid[x][y - 1] == '.')
                    {
                        grid[x][y - 1] = 0;
                        q.push({x, y - 1});
                    }
                    if(grid[x][y + 1] == '.')
                    {
                        grid[x][y + 1] = 0;
                        q.push({x, y + 1});
                    }
                }
            }
    printf("%d\n", ans);
        
}
