//https://app.codesignal.com/company-challenges/two-sigma/56dCgYQwe8p7vBFiT
int computerNetwork(int n, vector<vector<int>> network) {
    vector<vector<int>> graph(n + 1, vector<int>(n + 1, 1000000));
   for(int i = 0; i < network.size(); i++)
    {
        int from = network[i][0];
        int to = network[i][1];
        int cost = network[i][2];
        graph[from][to] = graph[to][from] = cost;
    }
     for(int i = 1; i <= n; i++)
        graph[i][i] = 0;
    
    for(int k = 1; k <= n; k++)
        for(int i = 1; i <= n; i++)
            for(int j = 1; j <= n; j++)
                graph[i][j] = min(graph[i][j], graph[i][k] + graph[k][j]);
    return graph[1][n];
}
