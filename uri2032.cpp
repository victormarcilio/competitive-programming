#include <bits/stdc++.h>
using namespace std;

string swapright(string s)
{
    int ind = s.find('0');
    swap(s[ind], s[ind + 1]);
    return s;
}

string swapleft(string s)
{
    int ind = s.find('0');
    swap(s[ind], s[ind - 1]);
    return s;
}

string swapup(string s)
{
    int ind = s.find('0');
    swap(s[ind], s[ind - 4]);
    return s;
}

string swapdown(string s)
{
    int ind = s.find('0');
    swap(s[ind], s[ind + 4]);
    return s;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    vector<int> right{0, 1, 4, 5, 8, 9};
    vector<int> left{1, 2, 5, 6, 9, 10};
    vector<int> up{4, 5, 6, 8, 9, 10};
    vector<int> down{0, 1, 2, 4, 5, 6};
    const string target = "123\n456\n780\n";
    string linha, nova;
    while (cin >> linha)
    {
        linha.push_back('\n');
        for (int i = 0; i < 2; i++)
        {
            cin >> nova;
            linha += nova;
            linha.push_back('\n');
        }
        unordered_map<string, string> m;
        queue<string> q;
        q.push(linha);
        vector<string> ans{"Problema sem solucao\n"s};
        while (!q.empty())
        {
            string current = q.front();
            q.pop();
            if (current == target)
            {
                ans.clear();
                ans.push_back(current);
                while (m[current] != linha)
                {
                    current = m[current];
                    ans.push_back(current);
                }
                printf("Quantidade minima de passos = %d\n", (int)ans.size());
                break;
            }
            if (find(begin(up), end(up), current.find('0')) != end(up))
            {
                string u = swapup(current);
                if (!m.count(u))
                {
                    m[u] = current;
                    q.push(u);
                }
            }
            if (find(begin(down), end(down), current.find('0')) != end(down))
            {
                string d = swapdown(current);
                if (!m.count(d))
                {
                    m[d] = current;
                    q.push(d);
                }
            }
            if (find(begin(right), end(right), current.find('0')) != end(right))
            {
                string r = swapright(current);
                if (!m.count(r))
                {
                    m[r] = current;
                    q.push(r);
                }
            }
            if (find(begin(left), end(left), current.find('0')) != end(left))
            {
                string l = swapleft(current);
                if (!m.count(l))
                {
                    m[l] = current;
                    q.push(l);
                }
            }
        }
        for (int i = ans.size() - 1; i; i--)
            printf("%s\n", ans[i].c_str());
        printf("%s", ans[0].c_str());
        linha.clear();
    }
}
