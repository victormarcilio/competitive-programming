//https://onlinejudge.org/external/126/12643.pdf
#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n, i, j;
    while(~scanf("%d %d %d", &n, &i, &j))
    {
        int ans = 0;
        while(i != j)
        {
            ans++;
            i = i / 2 + i % 2;
            j = j / 2 + j % 2;
        }
        printf("%d\n", ans);
    }
}
