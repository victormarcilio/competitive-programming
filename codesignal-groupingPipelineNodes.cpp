//https://app.codesignal.com/company-challenges/ascend/FEFssLqrL876ShX5T
void dfs(vector<set<int>>& g, vector<int>& visited, bool& ans, int node)
{
    visited[node] = 1;
    for(auto i = g[node].begin(); i != g[node].end(); i++)
        if(visited[*i] == 1)
        {
            ans = false;
            return;
        }
        else if(!visited[*i])
            dfs(g, visited, ans, *i);
    visited[node] = 2;
}

bool groupingPipelineNodes(int n, vector<vector<int>> g, vector<int> v) {
    map<int,int> m;
    for(int i = 1; i <= n; i++)
        m[i] = i;
    for(auto i : v)
        m[i] = v[0];
    vector<set<int>> g2(n + 1);
    for(int i = 0; i < g.size(); i++)
        if(m[g[i][0]] != m[g[i][1]])
            g2[m[g[i][0]]].insert(m[g[i][1]]);
    
    vector<int> visited(n + 1);
    bool ans = true;
    for(int i = 1; i <= n; i++)
    if(!visited[i])
        dfs(g2, visited, ans, i);
    return ans;
}
