#include <bits/stdc++.h>
using namespace std;

void f(const vector<vector<int>> &v, int k, set<int> &s)
{
    for (auto i : v[k])
        if (s.find(i) == s.end())
        {
            s.insert(i);
            f(v, i, s);
        }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, l;
    cin >> n >> l;
    if (n - l > 1)
        cout << "INCOMPLETO\n";
    else
    {
        int x, y;
        vector<vector<int>> v(n + 1);
        while (l--)
        {
            cin >> x >> y;
            v[x].push_back(y);
            v[y].push_back(x);
        }
        set<int> s;
        s.insert(1);
        f(v, 1, s);
        cout << (s.size() != n ? "IN" : "") << "COMPLETO\n";
    }
}
