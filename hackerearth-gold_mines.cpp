//https://www.hackerearth.com/practice/algorithms/dynamic-programming/2-dimensional/practice-problems/algorithm/gold-mines-10/
#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int r, c, q, x1, x2, y1, y2;
    cin >> r >> c;
    vector<vector<int>> grid(r + 1, vector<int>(c + 1));
    for (int i = 1; i <= r; i++)
        for (int j = 1; j <= c; j++)
        {
            cin >> grid[i][j];
            grid[i][j] += grid[i][j - 1];
        }
    cin >> q;
    while(q--)
    {
        long long ans = 0;
        cin >> x1 >> y1 >> x2 >> y2;
        for(int i = x1; i <= x2; i++)
            ans += grid[i][y2] - grid[i][y1 - 1];
        cout << ans << '\n';
    }
}
