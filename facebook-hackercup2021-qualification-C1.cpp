//https://www.facebook.com/codingcompetitions/hacker-cup/2021/qualification-round/problems/C1
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

long long dive(vector<vector<int>>& graph, const vector<long long>&gold, int current, long long visited)
{
    vector<long long> results{ 0 };
    visited |= (1LL << current);
    for (int i = 0; i < graph[current].size(); i++)
        if (!(visited & 1LL << graph[current][i]))
            results.push_back(dive(graph, gold, graph[current][i], visited ));
    return gold[current] + *max_element( begin(results), end(results));
}

int main()
{
    int t, n, from, to;
    cin >> t;
    for (int i = 1; i <= t; i++)
    {
        cin >> n;
        long long ans = 0;
        vector<vector<int>> graph(n + 1, vector<int>());
        vector<long long> gold(n + 1);
        for (int i = 1; i <= n; i++)
            cin >> gold[i];
        while (--n)
        {
            cin >> from >> to;
            graph[from].push_back(to);
            graph[to].push_back(from);
        }
        ans = gold[1];
        vector<int> paths;
        for (int i = 0; i < graph[1].size(); i++)
            paths.push_back(dive(graph, gold, graph[1][i], 1 << 1));
        sort(begin(paths), end(paths));
        if (paths.size())
        {
            ans += paths.back();
            paths.pop_back();
        }
        if (paths.size())
            ans += paths.back();

        cout << "Case #" << i << ": " << ans << '\n';
    }
}