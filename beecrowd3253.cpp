//https://www.beecrowd.com.br/judge/en/problems/view/3253
#include <iostream>
#include <algorithm>
#include <vector>
#include <regex>
#include <set>
#include <map>
#include<sstream>
#include <unordered_map>
#include <unordered_set>
#include <deque>
#include <bitset>
#include<numeric>
#include<queue>
using namespace std;

void dfs(vector<set<int>> & g, vector<bool>& visited, int current)
{
    visited[current] = true;
    for (auto i : g[current])
        if (!visited[i])
            dfs(g, visited, i);
}

int main()
{
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    
    int N, K = 1000;
    cin >> N;
    vector<set<int>> graph(K), reversed(K);
    int from, edges, to;
    vector<bool> nodes(K);
    vector<int> order;
    vector<int> repeated(K);
    for (int i = 0; i < N; i++)
    {
        cin >> from >> edges;
        if (!repeated[from])
        {
            repeated[from] = 1;
            order.push_back(from);
        }
        nodes[from] = true;
        while (edges--)
        {
            cin >> to;
            nodes[to] = true;
            graph[from].insert(to);
            reversed[to].insert(from);
        }
    }
    vector<bool> reached_from0(K, false), reaches0(K, false);
    dfs(graph, reached_from0, 0);
    dfs(reversed, reaches0, 0);
    vector<int> trapped(K), unreachable(K);
    for (int i = 0; i < K; i++)
    {
        if (nodes[i] && !reached_from0[i])
            unreachable[i] = 1;
        if (nodes[i] && !reaches0[i])
            trapped[i] = 1;
    }
    bool achou = false;
    
    for (int i : order)
        if (trapped[i])
        {
            cout << "TRAPPED " << i << '\n';
            achou = true;
        }
    for (int i : order)
        if (unreachable[i])
        {
            cout << "UNREACHABLE " << i << '\n';
            achou = true;
        }
    if (!achou)
        cout << "NO PROBLEMS\n";
}
