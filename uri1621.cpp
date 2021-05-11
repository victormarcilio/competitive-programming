#include<bits/stdc++.h>
#pragma warning(disable: 4996)

using namespace std;

int main()
{
#ifdef _DEBUG
    freopen("C:\\Users\\victor_peixoto\\Desktop\\in.txt", "r", stdin);
    freopen("C:\\Users\\victor_peixoto\\Desktop\\out.txt", "w", stdout);
#endif
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    int n, m;
    char gf[503][503];
    while (scanf("%d %d\n", &n, &m), n)
    {
        memset(gf, 0, sizeof gf);
        bitset<251000> b;
        for (int i = 1; i <= n; i++)
            scanf("%s", &gf[i][1]);
        queue<pair<int, int>> q;
        for(int i = 1; i <= n; i++)
            for(int j = 1; j <= m; j++)
                if (gf[i][j] == '.')
                {
                    q.push( {i,j});
                    b[i * n + j] = true;
                    goto prox;
                }
        prox:
        pair<int, int> last;
        while (!q.empty())
        {
            last = q.front();
            auto [x, y] = last;
            q.pop();
            if (gf[x - 1][y] == '.' && !b[(x - 1) * n + y])
            {
                b[(x - 1) * n + y] = true;
                q.push({ x - 1, y });
            }
            if (gf[x + 1][y] == '.' && !b[(x + 1) * n + y])
            {
                b[(x + 1) * n + y] = true;
                q.push({ x + 1, y });
            }
            if (gf[x][y + 1] == '.' && !b[x * n + y + 1])
            {
                b[x * n + y + 1] = true;
                q.push({ x, y + 1});
            }
            if (gf[x][y - 1] == '.' && !b[x * n + y - 1])
            {
                b[x * n + y - 1] = true;
                q.push({ x, y - 1 });
            }
        }
        b.reset();
        queue<pair<pair<int, int>, int>> Q;
        Q.push({{ last }, 0});
        int ans = 0;
        b.set(last.first * 500 + last.second);
        while (!Q.empty())
        {
            auto [par, depth] = Q.front();
            auto [x, y] = par;
            Q.pop();
            if (gf[x - 1][y] == '.' && !b[(x - 1) * 500 + y])
            {
                b[(x - 1) * 500 + y] = true;
                Q.push({ { x - 1, y}, depth + 1 });
            }
            if (gf[x + 1][y] == '.' && !b[(x + 1) * 500 + y])
            {
                b[(x + 1) * 500 + y] = true;
                Q.push({ { x + 1, y }, depth + 1 });
            }
            if (gf[x][y + 1] == '.' && !b[x * 500 + y + 1])
            {
                b[x * 500 + y + 1] = true;
                Q.push({ {x, y + 1 }, depth + 1 });
            }
            if (gf[x][y - 1] == '.' && !b[x * 500 + y - 1])
            {
                b[x * 500 + y - 1] = true;
                Q.push({ { x, y - 1 }, depth + 1 });
            }
            ans = depth;
        }
        printf("%d\n", ans);
    }
    
}
