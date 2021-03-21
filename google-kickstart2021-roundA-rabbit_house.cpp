#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t, row, col;
    cin >> t;
    for (int c = 1; c <= t; c++)
    {
        priority_queue<pair<int, pair<int, int>>> to_process;
        cin >> row >> col;
        vector<vector<int>> grid(row, vector<int>(col));
        for (int i = 0; i < row; i++)
            for (int j = 0; j < col; j++)
            {
                cin >> grid[i][j];
                to_process.push({grid[i][j], {i, j}});
            }
        long long ans = 0;
        vector<vector<bool>> visited(row, vector<bool>(col, false));
        while (!to_process.empty())
        {
            auto current = to_process.top();
            to_process.pop();
            int x = current.second.first;
            int y = current.second.second;
            if (visited[x][y])
                continue;
            visited[x][y] = true;
            if (x)
            {
                if (grid[x][y] > grid[x - 1][y] + 1)
                {
                    ans += grid[x][y] - grid[x - 1][y] - 1;
                    grid[x - 1][y] = grid[x][y] - 1;
                    to_process.push({grid[x - 1][y], {x - 1, y}});
                }
            }

            if (x < row - 1)
            {
                if (grid[x][y] > grid[x + 1][y] + 1)
                {
                    ans += grid[x][y] - grid[x + 1][y] - 1;
                    grid[x + 1][y] = grid[x][y] - 1;
                    to_process.push({grid[x + 1][y], {x + 1, y}});
                }    
            }

            if (y)
            {

                if (grid[x][y] > grid[x][y - 1] + 1)
                {
                    ans += grid[x][y] - grid[x][y - 1] - 1;
                    grid[x][y - 1] = grid[x][y] - 1;
                    to_process.push({grid[x][y - 1], {x, y - 1}});
                }
            }

            if (y < col - 1)
            {

                if (grid[x][y] > grid[x][y + 1] + 1)
                {
                    ans += grid[x][y] - grid[x][y + 1] - 1;
                    grid[x][y + 1] = grid[x][y] - 1;
                    to_process.push({grid[x][y + 1], {x, y + 1}});
                }
            }
        }
        cout << "Case #" << c << ": " << ans << '\n';
    }
}
