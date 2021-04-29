#include <bits/stdc++.h>
using namespace std;

bool possible = false;
void dfs(vector<vector<int>> const& g, bitset<10001>& b, int ind)
{
    if(b[ind])
    {
        possible = (ind == 1);
        return;
    }
    b[ind] = true;
    for(auto it : g[ind])
        dfs(g, b, it);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, from, to;
    cin >> n;
    vector<vector<int>> g(n + 1);

    for (int i = 0; i < n; i++)
    {
        cin >> from >> to;
        g[from].push_back(to);
        if(g[from].size() == 2)
        {
            cout << "N\n";
            return 0;
        }
    }
    bitset<10001> b;
    dfs(g, b, 1);
    if(b.count() == n && possible)
        cout << "S\n";
    else
        cout << "N\n";
}
