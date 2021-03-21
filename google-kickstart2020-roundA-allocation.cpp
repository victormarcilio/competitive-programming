#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t, n, b;
    cin >> t;
    for (int c = 1; c <= t; c++)
    {
        cin >> n >> b;
        vector<int> v(n);
        for(int i = 0; i < n; i++)
            cin >> v[i];
        int ans = 0;
        sort(begin(v), end(v));
        for(int i = 0; i < n && v[i] <= b; i++, ans++)
            b -= v[i];
        cout << "Case #" << c << ": " << ans << '\n';
    }
}
