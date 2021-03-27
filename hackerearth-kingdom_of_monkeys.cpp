//https://www.hackerearth.com/practice/algorithms/graphs/depth-first-search/practice-problems/algorithm/kingdom-of-monkeys/
#include <bits/stdc++.h>
using namespace std;

int get_group(vector<int> &v, int ind)
{
    if(v[ind] == ind)
        return ind;
    return v[ind] = get_group(v, v[ind]);
}

int main()
{
    int t, n, m, de, para;
    cin >> t;
    while (t--)
    {
        cin >> n >> m;
        vector<int> v(n + 1);
        iota(begin(v), end(v), 0);
        while(m--)
        {
            cin >> de >> para;
            int g1 = get_group(v, de);
            int g2 = get_group(v, para);
            if(g1 != g2)
                v[g2] = g1;

        }
        map<int, long long> bananas;
        for(int i = 1; i <= n; i++)
        {
            cin >> de;
            bananas[get_group(v, i)] += de;
        }
        long long ans = 0;
        for(auto it : bananas)
            ans = max(ans, it.second);
        cout << ans << '\n';
    }
}
