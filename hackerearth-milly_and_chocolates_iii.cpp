//https://www.hackerearth.com/pt-br/problem/algorithm/milly-and-chocolates-iii-2/
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t, n, k, p;
    cin >> t;
    string choco;
    while (t--)
    {
        cin >> n >> k;
        vector<vector<string>> chocolates(n);
        for (int i = 0; i < n; i++)
        {
            cin >> p;
            for (int j = 0; j < p; j++)
            {
                cin >> choco;
                chocolates[i].push_back(choco);
            }
        }
        int limit = 1 << n;
        int rooms = 500;
        for (int i = 1; i < limit; i++)
        {
            set<string> s;
            for(int j = 0; j < n; j++)
                if((1 << j) & i)
                    for(int k = 0; k < chocolates[j].size(); k++)
                        s.insert(chocolates[j][k]);
            if(s.size() >= k)
                rooms = min(rooms, __builtin_popcount(i));
        }
        if(rooms == 500)
            rooms = -1;
        cout << rooms << '\n';
    }
}
