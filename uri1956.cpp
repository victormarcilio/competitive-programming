#include <bits/stdc++.h>
using namespace std;

inline int get_group(vector<int>& group, int x)
{
    if(x == group[x])
        return x;
    return group[x] = get_group(group, group[x]);
}

int v[1000001];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int N, K, to, cost;
    scanf("%d", &N);
    priority_queue<pair<int, pair<int, int>>> pq;
    for(int from = 1; from < N; from++)
    {
        scanf("%d", &K);
        for(int j = 0; j < K; j++)
        {
            scanf("%d %d", &to, &cost);
            pq.push({-cost, {from, to}});
        }
    }
    vector<int> group(N + 1);
    iota(begin(group), end(group), 0);
    long long ans = 0;
    while(!pq.empty())
    {
        auto topo = pq.top();
        pq.pop();
        int g1 = get_group(group, topo.second.first);
        int g2 = get_group(group, topo.second.second);
        if(g1 != g2)
        {
            group[g1] = g2;
            ans -= topo.first;
        }
    }
    
    for(int i = 1; i <= N; i++)
        v[get_group(group, i)]++;
    
    int difs = 0;
    for(int i = 1; i<= N; i++)
        if(v[i])
            ++difs;
    printf("%d %lld\n", difs, ans);
}
