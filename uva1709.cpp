//https://onlinejudge.org/external/17/1709.pdf
#include<bits/stdc++.h>
using namespace std;

int main()
{
    int p, a, b, c, d, n;
    while(~scanf("%d %d %d %d %d %d", &p, &a, &b, &c, &d, &n))
    {
        double ans = 0, biggest = 0;
        double atual = p * (sin(a + b) + cos(c + d) + 2);
        for(int i = 2; i <= n; i++)
        {
            biggest = max(biggest, atual);
            atual = p * (sin(i*a + b) + cos(i*c + d) + 2);
            if(atual < biggest)
                ans = max(ans, biggest - atual);
        }
        printf("%.9lf\n", ans);
    }
}
