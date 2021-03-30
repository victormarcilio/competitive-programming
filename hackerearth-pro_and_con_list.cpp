//https://www.hackerearth.com/practice/algorithms/sorting/merge-sort/practice-problems/algorithm/pro-and-con-list/
#include <bits/stdc++.h>
using namespace std;

bool f(pair<int, int> p1, pair<int, int> p2)
{
    return p1.first - p2.second > p2.first - p1.second;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t, n, x, y;
    cin >> t;
    while (t--)
    {
        cin >> n;
        vector<pair<int, int>> v(n);
        for (int i = 0; i < n; i++)
        {
            cin >> x >> y;
            v[i] = {x, y};
        }
        sort(begin(v), end(v), f);
        long long ans = v[0].first + v[1].first;
        for (int i = 2; i < n; i++)
            ans -= v[i].second;
        cout << ans << '\n';
    }
}
