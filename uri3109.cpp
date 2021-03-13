#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n, q, op, x, y;
    map<int, int> m;
    cin >> n >> q;
    vector<int> v(n + 1);
    iota(begin(v), end(v), 0);
    for(int i = 1; i <= n; i++)
        m[i] = i;
    while(q--)
    {
        cin >> op >> x;
        if(op == 2)
        {
            int ans = 0;
            int pos = x;
            while(v[pos] != x)
            {   
                ans++;
                pos = v[pos];
            }
            cout << ans << '\n';
        }
        else
        {
            cin >> y;
            swap(v[m[x]], v[m[y]]);
            swap(m[x], m[y]);
            
        }
    }
}
