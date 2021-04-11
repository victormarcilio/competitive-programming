//http://codeforces.com/contest/1513/problem/C
#include <bits/stdc++.h>
using namespace std;
const int MOD = 1'000'000'007;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    vector<long long> v(10);
    v[0] = 1;
    vector<long long> v2(10);
    map<int, vector<long long>> m;
    for (int i = 1; i <= 200015; i++)
    {
        for (int j = 0; j < 9; j++)
            v2[j + 1] = v[j];
        v2[0] = v[9];
        v2[1] += v[9];
        v = v2;
        for (int k = 0; k < 10; k++)
            if (v[k] >= MOD)
                v[k] %= MOD;
        m[i] = v;
    }
    int t, q;
    cin >> t;
    string s;
    while (t--)
    {
        vector<int> v(10);
        cin >> s >> q;
        for (char c : s)
            v[c - '0']++;
        long long ans = 0;
        for (int i = 0; i < 10; i++)
        {
            for (auto it : m[i + q])
            {
                ans += (long long)v[i] * it;
                if (ans >= MOD)
                    ans %= MOD;
            }
        }
        cout << ans << '\n';
    }
}