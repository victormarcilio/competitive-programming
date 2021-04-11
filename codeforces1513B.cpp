//http://codeforces.com/problemset/problem/1513/B
#include <bits/stdc++.h>
using namespace std;
long long v[200'000];
const long long MOD = 1'000'000'007;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t, n;
    cin >> t;
    while (t--)
    {
        cin >> n;
        long long total = -1LL;
        for (int i = 0; i < n; i++)
        {
            cin >> v[i];
            total &= v[i];
        }
        long long pontas = 0;
        for (int i = 0; i < n; i++)
            pontas += (v[i] == total);
        if (pontas > 1)
        {
            long long ans = pontas * (pontas - 1) % MOD;
            for (n -= 2; n > 1; n--)
            {
                ans = ans * n;
                if (ans > MOD)
                    ans = ans % MOD;
            }
            cout << ans << '\n';
        }
        else
            cout << "0\n";
    }
}