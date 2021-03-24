#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    map<int, string> mapa;
    int n, m, p;
    cin >> n >> m >> p;
    vector<string> words(n);
    for (int i = 0; i < n; i++)
        cin >> words[i];
    string line;
    for (int i = 0; i < m; i++)
    {
        cin >> line;
        for (int j = 0; j < p; j++)
            mapa[i + j].push_back(tolower(line[j]));
    }
    for (int i = 0; i < n; i++)
    {
        bool found = false;
        string reversed = words[i];
        reverse(begin(reversed), end(reversed));
        for (auto &it : mapa)
            if (it.second.find(words[i]) != string::npos || it.second.find(reversed) != string::npos)
            {
                found = true;
                if (it.first == m - 1)
                    cout << "1 Palavra \"" << words[i] << "\" na diagonal secundaria\n";
                else if (it.first >= m)
                    cout << "3 Palavra \"" << words[i] << "\" abaixo da diagonal secundaria\n";
                else
                    cout << "2 Palavra \"" << words[i] << "\" acima da diagonal secundaria\n";
                break;
            }
        if (!found)
            cout << "4 Palavra \"" << words[i] << "\" inexistente\n";
    }
}
