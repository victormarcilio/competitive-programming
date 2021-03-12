#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;

    while (cin >> n, n)
    {
        vector<int> v(n + 1), seq(n + 1);
        for (int i = 1; i <= n; i++)
        {
            cin >> v[i];
            seq[v[i]] = i;
        }
        if (seq != v)
            cout << "not ";
        cout << "ambiguous\n";
    }
}