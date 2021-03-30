// https://www.hackerearth.com/practice/algorithms/graphs/depth-first-search/practice-problems/algorithm/akshay/
    #include <bits/stdc++.h>
    using namespace std;
     
    void dfs(int node, int level, vector<vector<int>> &graph, vector<vector<int>> &levels, vector<int> &blacks, vector<int> &colors)
    {
        levels[level].push_back(node);
        blacks[node] = colors[node];
        for (int i = 0; i < graph[node].size(); i++)
            dfs(graph[node][i], level + 1, graph, levels, blacks, colors);
        for (int i = 0; i < graph[node].size(); i++)
            blacks[node] += blacks[graph[node][i]];
    }
     
    int main()
    {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        int t, n, q, v1, v2;
        cin >> t;
        while (t--)
        {
            cin >> n;
            vector<int> colors(n + 1);
            for (int i = 1; i <= n; i++)
                cin >> colors[i];
            vector<vector<int>> graph(n + 1);
            for (int i = 1; i < n; i++)
            {
                cin >> v1 >> v2;
                graph[v1].push_back(v2);
            }
     
            vector<vector<int>> levels(n + 1);
            vector<int> blacks(n + 1);
            levels[1].push_back(1);
            int level = 1;
            dfs(1, 1, graph, levels, blacks, colors);
            cin >> q;
            unordered_map<int, pair<int, int>> queries;
            queries.reserve(n);
            while (q--)
            {
                cin >> v1;
                if (v1 >= levels.size() || levels[v1].empty())
                    cout << "-1\n";
                else
                {
                    if (!queries.count(v1))
                    {
                        int best = levels[v1][0];
                        int most = blacks[best];
                        for (int i = 1; i < levels[v1].size(); i++)
                        {
                            if (blacks[levels[v1][i]] > most)
                            {
                                best = levels[v1][i];
                                most = blacks[best];
                            }
                            else if (blacks[levels[v1][i]] == most && best > levels[v1][i])
                                best = levels[v1][i];
                        }
                        queries[v1] = {best, most};
                    }
                    cout << queries[v1].first << ' ' << queries[v1].second << '\n';
                }
            }
        }
    }
