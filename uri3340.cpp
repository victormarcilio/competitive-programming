//https://www.urionlinejudge.com.br/judge/pt/challenges/view/604/2
#include <iostream>
#include <algorithm>
#include <vector>
#include <regex>
#include <set>
#include <map>
#include <unordered_map>

using namespace std;
int n, m, from, to, a, b;

bool check(vector<int>& mask, vector<vector<int>>& graph)
{
    bool ok = true;
    for (int i = 0; i < graph.size(); i++)
    {
        int equals = 0;
        for (int j = 0; j < graph[i].size(); j++)
            if (mask[i] == mask[graph[i][j]])
                equals++;
        if (equals > b)
        {
            ok = false;
            break;
        }
    }
    return ok;
}

void inc(vector<int>& mask)
{
    int current = mask.size() - 1;
    while (mask[current] == 2)
    {
        mask[current] = 1;
        current--;
    }
    mask[current]++;
}

void print(vector<int>& mask)
{
    for (int i = 0; i < n; i++)
        cout << mask[i];
    cout << '\n';
}

int main()
{
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    cin >> n >> m;
    vector<vector<int>> graph(n);
    vector<int> mask(n, 1), last(n, 2);
    for (int i = 0; i < m; i++)
    {
        cin >> from >> to;
        from--;
        to--;
        graph[from].push_back(to);
        graph[to].push_back(from);
    }
    cin >> a >> b;
    if (a == 1)
    {
        bool ok = true;
        for (int i = 0; i < n; i++)
            if (graph[i].size() > b)
                ok = false;
        if (ok)
        {
            cout << "DEU BOA, ADAM\n";
            for (int i = 0; i < n; i++)
                cout << 1;
            cout << '\n';
            return 0;
        }
    }
    else
    {
        while(1)
        {
            if (check(mask, graph))
            {
                cout << "DEU BOA, ADAM\n";
                print(mask);
                return 0;
            }
            if (mask == last)
                break;
            inc(mask);
        }
    }
    cout << "FOI MAL, ADAM\n";
}