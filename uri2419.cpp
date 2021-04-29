#include<bits/stdc++.h>
#pragma warning(disable: 4996)

using namespace std;

char mt[1010][1010];

int main()
{
#ifdef _LOCALs
    freopen("C:\\Users\\victor_peixoto\\Desktop\\in.txt", "r", stdin);
    //freopen("C:\\Users\\victor_peixoto\\Desktop\\out.txt", "w", stdout);
#endif
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    int n, m;

    scanf("%d %d\n", &n, &m);
    for (int i = 1; i <= n; i++)
        scanf("%s", &mt[i][1]);
    int ans = 0;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            if (mt[i][j] == '#' && (mt[i - 1][j] != '#' || mt[i + 1][j] != '#' || mt[i][j - 1] != '#' || mt[i][j + 1] != '#'))
                ans++;
    printf("%d\n", ans);
}
