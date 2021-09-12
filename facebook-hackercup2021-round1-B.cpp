#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
    int t, n, m, a, b, grid[50][50];
    cin >> t;
    for (int caso = 1; caso <= t; caso++)
    {
        string ans = "Possible";
        cin >> n >> m >> a >> b;
        int min_path_size = n + m - 1;
        
        if (a < min_path_size || b < min_path_size)
            ans = "Impossible";
        else 
        {
            int menor = min(a, b);
            int common = menor / min_path_size;
            for (int i = 0; i < n; i++)
                for (int j = 0; j < m; j++)
                    grid[i][j] = common;
            grid[0][0] = grid[0][m - 1] = common + menor % min_path_size;
            if (b == menor)
                grid[0][0] += abs(a - b);
            if (a == menor)
                grid[0][m - 1] += abs(a - b);
        }
        
        cout << "Case #" << caso << ": " << ans << '\n';
        if (ans[0] == 'P')
        {
            for (int i = 0; i < n; i++)
            {
                cout << grid[i][0];
                for (int j = 1; j < m; j++)
                    cout << ' ' << grid[i][j];
                cout << '\n';
            }
        }
    }
}