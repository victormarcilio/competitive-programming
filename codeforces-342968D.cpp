//http://codeforces.com/gym/342968/problem/D
#include<bits/stdc++.h>
using namespace std;
 
using vi = vector<int>;
using vvi = vector<vector<int>>;
 
string merge(string atual, string changes)
{
    for (int i = 0; i < atual.size(); i++)
        if (changes[i] == '1')
            if (atual[i] == '1')
                atual[i] = '0';
            else
                atual[i] = '1';
    return atual;
}
 
int main()
{
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int n, m, q;
    cin >> n >> m >> q;
    vector<string> v(m);
    for (int i = 0; i < m; i++)
        cin >> v[i];
    
    unordered_map<string, int> memo;
    queue<tuple<string, int, int>> fila;
    string start(n, '0');
    memo[start] = 0;
    fila.push({ start , 0, 0});
    while (!fila.empty())
    {
        auto [config, depth, visited] = fila.front();
        fila.pop();
        
        for (int i = 0; i < m; i++)
        {
            if (!(visited & (1 << i)))
            {
                auto merged = merge(config, v[i]);
                if (memo.find(merged) == memo.end())
                {
                    memo[merged] = depth + 1;
                    fila.push({ merged, depth + 1, visited | (1 << i) });
                }
            }
        }
    }
    string config;
    for (int i = 0; i < q; i++)
    {
        cin >> config;
        int ans = memo.find(config) != memo.end() ? memo[config] : -1;
        cout << ans << '\n';
    }
}