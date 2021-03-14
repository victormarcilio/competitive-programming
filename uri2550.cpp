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
    int R, C;
    while(~scanf("%d %d", &R, &C))
    {
        vector<int> group(R + 1);
        iota(begin(group), end(group), 0);
        priority_queue<pair<int, pair<int, int>>> pq;
        int from, to, w;
        while(C--)
        {
            scanf("%d %d %d", &from, &to, &w);
            pq.push({-w, {from, to}});
        }
        int ans = 0;
        int joined = 1;
        while(!pq.empty() && joined < R)
        {
            auto top = pq.top();
            pq.pop();
            int g1 = gsearch(group, top.second.first);
            int g2 = gsearch(group, top.second.second);
            
            if(g1 == g2)
                continue;
            ans -= top.first;
            group[g1] = g2;
            joined++;
        }
        bool possible = true;
        int g1 = gsearch(group, 1);
        
        for(int i = 2; i <= R; i++)
        {
            if(g1 != gsearch(group, i))
            {
                possible = false;
                break;
            }
        }
        if(possible)
            printf("%d\n", ans);
        else
            puts("impossivel");
    }
}