#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t, n, x[100'000];
    scanf("%d", &t);
    while(t--)
    {
        scanf("%d", &n);
        for(int i = 0; i < n; i++)
            scanf("%d", &x[i]);
        sort(x, x + n);
        unsigned long long acc = accumulate(x, x + n, 0ULL);
        unsigned long long best = acc;
        for(int i = 0; i < n; i++)
        {
            acc -= x[i];
            best = max(best, (i + 2) * acc);
        }
        printf("%llu\n", best);
    }
}
