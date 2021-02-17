#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    char token[3] = "";
    string palavra;
    map<string, int> count;
    while (cin >> palavra)
    {
        for (int i = 1; i < palavra.size(); i++)
        {
            token[0] = tolower(palavra[i - 1]);
            token[1] = tolower(palavra[i]);
            ++count[token];
        }
    }
    int highest = 0;
    for (auto &it : count)
        highest = max(highest, it.second);
    for (auto &it : count)
        if (highest == it.second)
        {
            cout << it.first << ':' << highest << '\n';
            break;
        }
}
