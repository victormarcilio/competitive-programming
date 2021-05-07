//https://www.urionlinejudge.com.br/judge/pt/problems/view/3102
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

    int n, op, x[4], y[4];
    
    scanf("%d", &n);
    
    while (n--)
    {
        for(int i = 0; i < 3; i++)
            scanf("%d %d", &x[i], &y[i]);
        x[3] = x[0];
        y[3] = y[0];
        
        double ans = 0;
        for(int i = 0; i < 3; i++)
            ans += x[i] * y[i + 1] - y[i] * x[i + 1];
        printf("%.3lf\n", abs(ans)*.5);
    }
}
