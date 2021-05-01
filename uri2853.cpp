#include<bits/stdc++.h>
#pragma warning(disable: 4996)

using namespace std;
char mtx[1010][1010];
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
    for (int i = 0; i < n; i++)
        scanf("%s", mtx[i]);
    int ans = 0;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            if (mtx[i][j] == '#')
            {
                int top = 100000, bot = 100000, left = 100000, right = 100000;
                for(int k = i - 1; k >= 0; k--)
                    if (mtx[k][j] == '@')
                    {
                        top = i - k;
                        break;
                    }
                for (int k = i + 1; k < n; k++)
                    if (mtx[k][j] == '@')
                    {
                        bot = k - i;
                        break;
                    }
                for (int k = j - 1; k >= 0; k--)
                    if (mtx[i][k] == '@')
                    {
                        left = j - k;
                        break;
                    }
                for (int k = j + 1; k < m; k++)
                    if (mtx[i][k] == '@')
                    {
                        right = k - j;
                        break;
                    }

                int current = min({ top, right, left, bot });
                if (current == 100000)
                {
                    puts("-1");
                    return 0;
                }
                ans = max(ans, current);
            }
    printf("%d\n", ans);
}
