#include <bits/stdc++.h>

using namespace std;

int gsearch(vector<int>& v, int n)
{
    if(v[n] != n)
        return v[n] = gsearch(v, v[n]);
    return n;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int N, Q;
    cin >> N >> Q;
    vector<int> groups(N + 1);

    iota(begin(groups), end(groups), 0);
    char op;
    int g1, g2;
    while(Q--)
    {
        cin >> op >> g1 >> g2;
        g1 = gsearch(groups, g1);
        g2 = gsearch(groups, g2);
        
        if(op == '?')
            cout << (g1 == g2 ? "yes\n" : "no\n");
        else if(g1 != g2)
            groups[g1] = g2;
    }
}
