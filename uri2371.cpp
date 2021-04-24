#include<bits/stdc++.h>
#pragma warning(disable: 4996)

using namespace std;

char mtx[105][105];
int boat = 0;
map<int, int> boat_health;
map<pair<int, int>, int> pos_boat;

inline void rec(int x, int y)
{
    pos_boat[{x, y}] = boat;
    boat_health[boat]++;
    mtx[x][y] = 0;
    if(mtx[x - 1][y] == '#')
        rec(x - 1, y);
    if(mtx[x + 1][y] == '#')
        rec(x + 1, y);
    if(mtx[x][y + 1] == '#')
        rec(x, y + 1);
    if (mtx[x][y - 1] == '#')
        rec(x, y - 1);
}

int main()
{
#ifdef _LOCA
    freopen("C:\\Users\\victor_peixoto\\Desktop\\in.txt", "r", stdin);
    //freopen("C:\\Users\\victor_peixoto\\Desktop\\out.txt", "w", stdout);
#endif
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int n, m, x, y;
    scanf("%d %d\n", &n, &m);
    for (int i = 1; i <= n; i++)
        scanf("%s",&mtx[i][1]);
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            if (mtx[i][j] == '#')
            {
                rec(i, j);
                boat++;
            }
    scanf("%d", &n);
    int ans = 0;
    while (n--)
    {
        scanf("%d %d", &x, &y);
        if (pos_boat.count({ x,y }) && !--boat_health[pos_boat[{x, y}]])
			ans++;
    }
    printf("%d\n", ans);
}
