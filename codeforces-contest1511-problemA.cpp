//http://codeforces.com/contest/1511/problem/A
#include <bits/stdc++.h>
using namespace std;
const int MOD = 1'000'000'007;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, t, v;
    cin >> t;
    while (t--)
    {
        int ans = 0;
        int first = 0, second = 0;
        cin >> n;
        for (int i = 0; i < n; i++)
        {
            cin >> v;
            if (v != 2)
                ans++;
        }
        cout << ans << '\n';
    }
}