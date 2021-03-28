//https://www.hackerearth.com/practice/algorithms/graphs/depth-first-search/practice-problems/algorithm/sightseeing-walk-september-clash/
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t, n, m, h;
    cin >> t;
    while (t--)
    {
        cin >> n >> m;
        vector<pair<int, int>> heights(n + 1);
        vector<int> HS(n + 1);
        for (int i = 1; i <= n; i++)
        {
            cin >> h;
            heights[i] = {h, i};
            HS[i] = h;
        }
        sort(begin(heights) + 1, end(heights));
        vector<vector<int>> graph(n + 1);
        int from, to;
        for (int i = 0; i < m; i++)
        {
            cin >> from >> to;
            graph[from].push_back(to);
        }
        vector<bool> visited(n + 1, false);
        int ans = 0;
        for (int i = 1; i <= n; i++)
            if (!visited[heights[i].second])
            {
                queue<int> q;
                q.push(heights[i].second);
                visited[heights[i].second] = true;
                while (!q.empty())
                {
                    int front = q.front();
                    q.pop();
                    for (int j = 0; j < graph[front].size(); j++)
                        if (!visited[graph[front][j]])
                        {
                            visited[graph[front][j]] = true;
                            q.push(graph[front][j]);
                            ans = max(ans, HS[graph[front][j]] - heights[i].first);
                        }
                }
            }
        cout << ans << '\n';
    }
}
