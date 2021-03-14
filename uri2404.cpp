#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int R, C;
    cin >> R >> C;
    vector<int> group(R + 1);
    iota(begin(group), end(group), 0);
    priority_queue<pair<int, pair<int, int>>> pq;
    int from, to, w;
    while(C--)
    {
        cin >> from >> to >> w;
        pq.push({-w, {from, to}});
    }
    int ans = 0;
    while(!pq.empty())
    {
        auto top = pq.top();
        pq.pop();
        int n1 = top.second.first;
        int n2 = top.second.second;
        int g1 = n1;
        while(group[g1] != g1)
            g1 = group[g1];
        int g2 = n2;
        while(group[g2] != g2)
            g2 = group[g2];
        if(g1 == g2)
            continue;
        ans -= top.first;
        group[g1] = g2;
    }
    cout << ans << '\n';
}
