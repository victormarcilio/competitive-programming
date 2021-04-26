#include<bits/stdc++.h>
#pragma warning(disable: 4996)

using namespace std;

int mtx[100][100];

int main()
{
#ifdef _LOCAL
    freopen("C:\\Users\\victor_peixoto\\Desktop\\in.txt", "r", stdin);
    //freopen("C:\\Users\\victor_peixoto\\Desktop\\out.txt", "w", stdout);
#endif
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    
    int n, m, from, to, w;
    scanf("%d %d", &n, &m);
    memset(mtx, 10000, sizeof mtx);
    while (m--)
    {
        scanf("%d %d %d", &from, &to, &w);
        mtx[from][to] = mtx[to][from] = min(w, mtx[from][to]);
    }
    for (int i = 0; i < n; i++)
        mtx[i][i] = 0;
    for (int k = 0; k < n; k++)
        for (int i = 0; i < n; i++)
           for (int j = 0; j < n; j++)
                mtx[i][j] = min(mtx[i][j], mtx[i][k] + mtx[k][j]);
    int ans = *max_element(mtx[0], mtx[0] + n);
    for (int i = 1; i < n; i++)
        ans = min(ans, *max_element(mtx[i], mtx[i] + n));
    printf("%d\n", ans);
}
