// PASSES ON TEST SET 1, TLE ON TEST SET 2

#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t, n, target, cost;
    bool found;
    cin >> t;
    for (int c = 1; c <= t; c++)
    {
        cin >> n >> target;
        vector<int> v(n);
        vector<int> ans;
        iota(begin(v), end(v), 1);
        found = false;
        do
        {
            ans = v;
            cost = 0;
            for (int i = 0; i < n - 1; i++)
            {
                auto j = find(v.begin() + i, v.end(), i + 1) - v.begin();
                cost += j - i + 1;
                reverse(begin(v) + i, begin(v) + j + 1);
            }
            if (cost == target)
            {
                found = true;
                break;
            }
            v = move(ans);
        } while (next_permutation(begin(v), end(v)));
        if (found)
        {
            cout << "Case #" << c << ":";
            for(auto it : ans)
                cout << ' ' << it;
            cout << '\n';
        }
        else
            cout << "Case #" << c << ": IMPOSSIBLE\n";
    }
}
