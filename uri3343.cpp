//https://www.urionlinejudge.com.br/judge/pt/challenges/view/605/1
#include <iostream>
#include <algorithm>
#include <vector>
#include <regex>
#include <set>
#include <map>
#include <unordered_map>
#include <deque>

using namespace std;

int main()
{
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int x, n, p, m, g;
    map<char, int> M;

    string s;
    cin >> n >> x >> s >> p >> m >> g;
    M['M'] = m;
    M['P'] = p;
    M['G'] = g;
    deque<int> muralhas(n + 10, x);
    int count = 0;
    for (int i = 0; i < n; i++)
    {
        while (muralhas.front() < M['P'])
        {
            muralhas.pop_front();
            count++;
        }
        for (int j = 0; ; j++)
        {
            if (muralhas[j] >= M[s[i]])
            {
                muralhas[j] -= M[s[i]];
                break;
            }
        }
    }
    for (int i = 0; i < n && muralhas[i] < x; i++)
        count++;
    cout << count << '\n';
}