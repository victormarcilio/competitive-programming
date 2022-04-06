//https://www.beecrowd.com.br/judge/pt/problems/view/3364
#include <bits/stdc++.h>
using namespace std;

int main()
{
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    int a, b, N, M;
    scanf("%d %d", &N, &M);
    vector<vector<int>> g(N + 1);
    while(M--)
    {
        scanf("%d %d", &a, &b);
        g[a].push_back(b);
        g[b].push_back(a);
    }
    string ans(N, 'A');
    vector<bool> visited(N + 1, false);
    visited[N] = visited[N - 1] = true;
    queue<int> q;
    q.push(N - 1);
    while(!q.empty())
    {
        int topo = q.front();
        q.pop();
        ans[topo - 1] = 'B';
        for(auto x : g[topo])
            if(!visited[x])
            {
                visited[x] = true;
                q.push(x);
            }
    }
    printf("%s\n", ans.c_str());
}
