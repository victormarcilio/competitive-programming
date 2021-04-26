#include<bits/stdc++.h>
#pragma warning(disable: 4996)

using namespace std;

int main()
{
#ifdef _LOCAL
    freopen("C:\\Users\\victor_peixoto\\Desktop\\in.txt", "r", stdin);
    //freopen("C:\\Users\\victor_peixoto\\Desktop\\out.txt", "w", stdout);
#endif
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    
    int n, v, ans = 0, acc = 0;
    scanf("%d", &n);
    while (n--)
    {
        scanf("%d", &v);
        acc = max(0, acc + v);
        ans = max(acc, ans);
    }
    printf("%d\n", ans);
}
