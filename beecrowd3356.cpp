//https://www.beecrowd.com.br/judge/pt/problems/view/3356
#include <iostream>
#include <algorithm>
#include <vector>
#include <regex>
#include <set>
#include <map>
#include<sstream>
#include <unordered_map>
#include <deque>
#include <bitset>
#include<numeric>
#include<queue>
using namespace std;

int main()
{
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int N, C, T;
    cin >> N >> C >> T;
    string parent1, parent2, child;
    map<string, vector<string>> tree;
    while (C--)
    {
        cin >> parent1 >> parent2 >> child;
        tree[child].push_back(parent1);
        tree[child].push_back(parent2);
    }
    while (T--)
    {
        cin >> parent1 >> parent2;
        set<string> s;
        queue<string> q;
        q.push(parent1);
        
        while (!q.empty())
        {
            string topo = q.front();
            q.pop();
            s.insert(topo);
            for (auto& ancestor : tree[topo])
                q.push(ancestor);
        }
        string ans = "falso";
        q.push(parent2);
        while (!q.empty())
        {
            string topo = q.front();
            q.pop();
            if (s.find(topo) != s.end())
            {
                ans = "verdadeiro";
                break;
            }
            for (auto& ancestor : tree[topo])
                q.push(ancestor);
        }
        cout << ans << '\n';
    }
}
