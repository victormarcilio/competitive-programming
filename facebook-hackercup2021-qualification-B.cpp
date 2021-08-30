//https://www.facebook.com/codingcompetitions/hacker-cup/2021/qualification-round/problems/B
#include <string>
#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int t, n;
    cin >> t;
    for (int i = 1; i <= t; i++)
    {
        string ans = "Impossible";
        cin >> n;        
        vector<string> grid(n);
        vector<int> xrow(n), xcol(n), orow(n), ocol(n);
        for (int j = 0; j < n; j++)
        {
            string& row = grid[j];
            cin >> row;
            for (int k = 0; k < n; k++)
                if (row[k] == 'X')
                {
                    xrow[j]++;
                    xcol[k]++;
                }
                else if (row[k] == 'O')
                {
                    orow[j]++;
                    ocol[k]++;
                }
        }
        int ways = 0;
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                if (grid[i][j] == '.' && (xrow[i] == n - 1 || xcol[j] == n - 1))
                    ways++;
        int x;
        for (x = 1; !ways && x <= n; x++)
        {
            for (int i = 0; i < n; i++)
            {
                if (!orow[i] && xrow[i] + x == n)
                    ways++;
                if (!ocol[i] && xcol[i] + x == n)
                    ways++;
            }
            if (ways)
                break;
        }
        if(ways)
            ans = to_string(x) + ' ' + to_string(ways);

        cout << "Case #" << i << ": " << ans << '\n';
    }
}