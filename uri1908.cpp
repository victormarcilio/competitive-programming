//https://www.urionlinejudge.com.br/judge/pt/problems/view/1908
#include<bits/stdc++.h>
#pragma warning(disable: 4996)

using namespace std;

int main()
{
#ifdef _DEBUG
    freopen("C:\\Users\\victor_peixoto\\Desktop\\in.txt", "r", stdin);
   // freopen("C:\\Users\\victor_peixoto\\Desktop\\out.txt", "w", stdout);
#endif
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    int n, k, x, v;
    scanf("%d %d", &n, &k);
    int temp[1000];
    vector<vector<int>> g(n + 1);
    while (k--)
    {
        scanf("%d", &x);
        for (int i = 0; i < x; i++)
            scanf("%d", temp + i);
        for(int i = 0; i < x; i++)
            for (int j = i + 1; j < x; j++)
            {
                g[temp[i]].push_back(temp[j]);
                g[temp[j]].push_back(temp[i]);
            }
    }
    queue<int> q;
    q.push(1);
    bitset<10010> b;
    b[1] = true;
    int distance = 0;
    while (1)
    {
        queue<int> q2;
        int lim = q.size();
        for(int i = 0; i < lim; i++)
        {
            auto current = q.front();
            if (current == n)
            {
                printf("%d\n", distance);
                return 0;
            }
            q.pop();

            for (int i = 0; i < g[current].size(); i++)
                if (!b[g[current][i]])
                {
                    b[g[current][i]] = true;
                    q2.push(g[current][i]);
                }
        }
        q = move (q2);
        distance++;
    }
}
