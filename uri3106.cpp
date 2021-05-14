//https://www.urionlinejudge.com.br/judge/pt/problems/view/3106
#include<bits/stdc++.h>
#pragma warning(disable: 4996)

using namespace std;

int main()
{
#ifdef _DEBUG
    freopen("C:\\Users\\victor_peixoto\\Desktop\\in.txt", "r", stdin);
   // freopen("C:\\Users\\victor_peixoto\\Desktop\\out.txt", "w", stdout);
#endif
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    int n, ans = 0, x;
    scanf("%d", &n);
    while (n--)
    {
        scanf("%d", &x);
        ans += x / 3 * 3;
    }
    printf("%d\n", ans);
}
