#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    string line;
    int wins = 0;
    while (n--)
    {
        cin >> line;
        bool won = true;
        for (int i = 1; i < line.size(); i++)
            if (line[i] == 'D' && line[i - 1] == 'C')
            {
                won = false;
                break;
            }
        wins += won;
    }
    cout << wins << '\n';
}
