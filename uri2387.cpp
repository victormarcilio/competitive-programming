#include<bits/stdc++.h>
#pragma warning(disable: 4996)

using namespace std;


int main()
{

#ifdef _DEBUG
    freopen("C:\\Users\\victor_peixoto\\Desktop\\in.txt", "r", stdin);
    //freopen("C:\\Users\\victor_peixoto\\Desktop\\out.txt", "w", stdout);
#endif
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    int n, op;
    int ans = 1;
    int from, to, old_from, old_to;
    scanf("%d", &n);
    scanf("%d %d", &from, &to);
    while (--n)
    {
        old_from = from;
        old_to = to;
        scanf("%d %d", &from, &to);
        if(from >= old_to)
            ans++;
        else
            to = min(to, old_to);
    }
    printf("%d\n", ans);
}
