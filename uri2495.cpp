//https://www.urionlinejudge.com.br/judge/pt/problems/view/2495
#include <bits/stdc++.h>
using namespace std;

int b[100001];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int c = 1, v, n;
    while (~scanf("%d", &n))
    {
        while (--n)
        {
            scanf("%d", &v);
            b[v] = c;
        }
        for (int i = 1;; i++)
            if (b[i] != c)
            {
                printf("%d\n", i);
                break;
            }
        c++;
    }
}