#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t, n;
    cin >> t;
    for(int c = 1; c <= t; c++)
    {
        cin >> n;
        vector<int> v(n);
        for(int i = 0; i < n; i++)
            cin >> v[i];
        int cost = 0;
        for(int i = 0; i < n - 1; i++)
        {
            auto j = find(v.begin() + i, v.end(), i + 1) - v.begin();
            cost += j - i + 1;
            reverse(begin(v) + i, begin(v) + j + 1);
        }
        cout << "Case #" << c << ": " << cost << '\n';
    }
}
