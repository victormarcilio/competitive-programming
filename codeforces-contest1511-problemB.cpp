//http://codeforces.com/contest/1511/problem/B
#include <bits/stdc++.h>
using namespace std;
const int MOD = 1'000'000'007;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t, a, b, c;
    cin >> t;
    while (t--)
    {
        cin >> a >> b >> c;
        long long n1 = 2;
        while (to_string(n1).size() < c)
            n1 *= 2;
        long long n2 = n1;
        while (to_string(n1).size() < a)
            n1 *= 2;
        while (to_string(n2).size() < b)
            n2 *= 3;

        cout << n1 << ' ' << n2 << '\n';
    }
}