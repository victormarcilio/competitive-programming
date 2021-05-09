//https://www.urionlinejudge.com.br/judge/pt/problems/view/2790
#include<bits/stdc++.h>
#pragma warning(disable: 4996)

using namespace std;

int main()
{
#ifdef _DEBUGs
    freopen("C:\\Users\\victor_peixoto\\Desktop\\in.txt", "r", stdin);
    //freopen("C:\\Users\\victor_peixoto\\Desktop\\out.txt", "w", stdout);
#endif
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    int n, v;
    int dados[7] = {0};
    scanf("%d", &n);
    int ans = 3 * n;
    while (n--)
    {
        scanf("%d", &v);
        dados[v]++;
    }
    
    for (int i = 1; i < 7; i++)
    {
        int temp = 0;
        for (int j = 1; j < 7; j++)
            if (i + j == 7)
                temp += 2*dados[j];
            else if (i != j)
                temp+= dados[j];
        ans = min(ans, temp);
    }
    printf("%d\n", ans);
}
