//https://codeforces.com/problemset/problem/289/B
#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m, jump;
    cin >> n >> m >> jump;
    vector<int> v(n * m);
    for(int i = 0; i < v.size(); i++)
    {
        cin >> v[i];
        int temp = v[i] - v[0];
        if (temp % jump)
        {
            cout << "-1\n";
            return 0;
        }
    }
    sort(begin(v), end(v));
    int total = 0;
    int middle = v[v.size()/2];
    for(int i = 0; i < v.size(); i++)
        total += abs(middle - v[i])/jump;
    cout << total << '\n';
}
