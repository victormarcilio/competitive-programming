#include <bits/stdc++.h>

using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t, n;
    cin >> t;
    int mtx[100][100];
    for(int c = 1; c <= t; c++)
    {
        cin >> n;
        int row_repeats = 0;
        int diagonal = 0;
        int col_repeats = 0;
        for(int i = 0; i < n; i++)
        {
            vector<int> repeats(n + 1);
            bool repeated = false;
            for(int j = 0; j < n; j++)
            {
                cin >> mtx[i][j];
                if(i == j)
                    diagonal += mtx[i][j];
                if(repeats[mtx[i][j]])
                    repeated = true;
                repeats[mtx[i][j]] = 1;
            }
            row_repeats += repeated;
        }
        for(int i = 0; i < n; i++)
        {
            bool repeated = false;
            vector<int> repeats(n + 1);
            for(int j = 0; j < n; j++)
            {
                if(repeats[mtx[j][i]])
                    repeated = true;
                repeats[mtx[j][i]] = 1;
            }
            col_repeats += repeated;
        }
        cout << "Case #" << c << ':' << ' ' << diagonal << ' ' << row_repeats << ' ' << col_repeats << '\n';    }
}
