#include<bits/stdc++.h>
#pragma warning(disable: 4996)

using namespace std;

int main()
{
#ifdef _LOCA
    freopen("C:\\Users\\victor_peixoto\\Desktop\\in.txt", "r", stdin);
    //freopen("C:\\Users\\victor_peixoto\\Desktop\\out.txt", "w", stdout);
#endif
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int mtx[50][50] = { 0 }, n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            scanf("%d", &mtx[i][j]);

    int l1 = accumulate(begin(mtx[0]), end(mtx[0]), 0);
    int l2 = accumulate(begin(mtx[0]), end(mtx[0]), 0);
    int l3 = accumulate(begin(mtx[0]), end(mtx[0]), 0);
    int original;
    if (l1 == l2 || l1 == l3)
        original = l1;
    else original = l2;
    int ind_dif;
    for (int i = 0; i < n; i++)
    {
        int atual = accumulate(begin(mtx[i]), end(mtx[i]), 0);
        if (atual != original)
        {
            ind_dif = i;
            break;
        }
    }

    for (int i = 0; i < n; i++)
    {
        int atual = 0;
        for (int j = 0; j < n; j++)
            atual += mtx[j][i];
        if (atual != original)
        {
            printf("%d %d\n", mtx[ind_dif][i] + original - atual, mtx[ind_dif][i]);
            break;
        }
    }
}
