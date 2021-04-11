//http://codeforces.com/problemset/problem/1513/A
#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t, n, k;
    cin >> t;
    while (t--)
    {
        cin >> n >> k;
        if (k > ((n - 1) >> 1))
            cout << "-1\n";
        else
        {
            int l = 2, r = n;
            cout << 1;
            while (k--)
                cout << ' ' << r-- << ' ' << l++;
            while (l <= r)
                cout << ' ' << l++;
            cout << '\n';
        }
    }
}