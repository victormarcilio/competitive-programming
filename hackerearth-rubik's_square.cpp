//https://www.hackerearth.com/practice/basic-programming/implementation/basics-of-implementation/practice-problems/algorithm/rubiks-square-2/
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, r, c, v;
    cin >> n >> r >> c;
    vector<vector<int>> mtx(n, vector<int>(n));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> mtx[i][j];
    vector<int> rotate_row(n), rotate_col(n);
    for (int i = 0; i < r; i++)
    {
        cin >> v;
        rotate_row[v - 1]++;
    }
    for (int i = 0; i < c; i++)
    {
        cin >> v;
        rotate_col[v - 1]++;
    }

    for (int i = 0; i < n; i++)
    {
        rotate_row[i] %= n;
        rotate(begin(mtx[i]), begin(mtx[i]) + n - rotate_row[i], end(mtx[i]));
    }

    for (int i = 0; i < n; i++)
    {
        rotate_col[i] %= n;
        if (rotate_col[i])
        {
            vector<int> temp(n);
            int pos = n - rotate_col[i];

            for (int j = 0; j < n; j++)
            {
                temp[j] = mtx[pos][i];
                pos++;
                if (pos == n)
                    pos = 0;
            }
            for (int j = 0; j < n; j++)
                mtx[j][i] = temp[j];
        }
    }
    for (int i = 0; i < n; i++)
    {
        cout << mtx[i][0];
        for(int j = 1; j < n; j++)
            cout << ' ' << mtx[i][j];
        cout << '\n';
    }
}
