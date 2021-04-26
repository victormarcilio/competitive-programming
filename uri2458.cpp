#include<bits/stdc++.h>
#pragma warning(disable: 4996)

using namespace std;

char grid[505][505];
bool visited[505][505];
bitset<25500000> safes;
bool safe;
void check(int x, int y)
{
    if (!grid[x][y])
    {
        safe = false;
        return;
    }
    if (visited[x][y])
    {
        safe = safes[x * 1000 + y];
        return;
    }
    visited[x][y] = true;
    if (grid[x][y] == 'A')
        check(x - 1, y);
    else if (grid[x][y] == 'V')
        check(x + 1, y);
    else if (grid[x][y] == '<')
        check(x, y - 1);
    else
        check(x, y + 1);
    safes[x * 1000 + y] = safe;
}

int main()
{
#ifdef _LOCAL
    freopen("C:\\Users\\victor_peixoto\\Desktop\\in.txt", "r", stdin);
    //freopen("C:\\Users\\victor_peixoto\\Desktop\\out.txt", "w", stdout);
#endif
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int n;
    safes.set();
    scanf("%d\n", &n);
    for (int i = 1; i <= n; i++)
        scanf("%s", &grid[i][1]);

    int ans = 0;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
        {
            if (!visited[i][j])
            {
                safe = true;
                check(i, j);
            }
            ans += safes[i * 1000 + j];

        }
    printf("%d\n", ans);
}
