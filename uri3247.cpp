#include <bits/stdc++.h>
using namespace std;

long long grid[1001][1001];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    scanf("%d\n", &n);
    char line[1010];
    for (int i = 1; i <= n; i++)
    {
        gets(line);
        for (int j = 0; j < n; j++)
            if (line[j] == '#')
                grid[i][j + 1] = -1;
    }

    const long long LIM = (1LL << 31) - 1;
    grid[1][1] = 1;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            if (grid[i][j] != -1)
            {
                if (grid[i - 1][j] != -1)
                    grid[i][j] += grid[i - 1][j];
                if (grid[i][j - 1] != -1)
                    grid[i][j] += grid[i][j - 1];
                if (grid[i][j] >= LIM)
                    grid[i][j] %= LIM;
            }

    if (grid[n][n])
        cout << grid[n][n] << '\n';
    else
    {
        queue<pair<int, int>> q;
        bitset<1000010> s;
        s.reset();
        q.push({n, n});
        bool all_dir = false;
        while (!q.empty())
        {
            auto topo = q.front();
            int x = topo.first;
            int y = topo.second;
            q.pop();
            if (grid[x][y] > 0)
            {
                all_dir = true;
                break;
            }
            if (x > 1 && grid[x - 1][y] != -1 && !s[(x - 1) * 1000 + y])
            {
                q.push({x - 1, y});
                s[(x - 1) * 1000 + y] = 1;
            }
            if (y > 1 && grid[x][y - 1] != -1 && !s[1000 * x + (y - 1)])
            {
                q.push({x, y - 1});
                s[1000 * x + y - 1] = 1;
            }
            if (x < n && grid[x + 1][y] != -1 && !s[1000 * (x + 1) + y])
            {
                q.push({x + 1, y});
                s[1000 * (x + 1) + y] = 1;
            }
            if (y < n && grid[x][y + 1] != -1 && !s[1000 * x + y + 1])
            {
                q.push({x, y + 1});
                s[1000 * x + y + 1] = 1;
            }
        }
        if (all_dir)
            cout << "THE GAME IS A LIE\n";
        else
            cout << "INCONCEIVABLE\n";
    }
}