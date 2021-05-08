//http://codeforces.com/problemset/problem/1520/C
#include<bits/stdc++.h>
#pragma warning(disable: 4996)
 
using namespace std;
 
 
int main()
{
#ifdef _DEBUG
    freopen("C:\\Users\\victor_peixoto\\Desktop\\in.txt", "r", stdin);
    //freopen("C:\\Users\\victor_peixoto\\Desktop\\out.txt", "w", stdout);
#endif
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
 
    int t, n;
    string s;
    cin >> t;
    while (t--)
    {
        cin >> n;
        if (n == 1)
            cout << "1\n";
        else if (n == 2)
            cout << "-1\n";
        else
        {
            int mtx[100][100] = { 0 };            
            int k = n - 1;
            int counter = 1;            
            for (int i = 0; i < n; i++)
                mtx[i][i] = counter++;
            for (int i = 1; i < n; i++)
            {
                int ini_row = i;
                int ini_col = i;
                for (int j = 0; j < k; j++)
                    mtx[ini_row + j][j] = counter++;
                for (int j = 0; j < k; j++)
                    mtx[j][ini_col + j] = counter++;
                k--;
            }
 
            for (int i = 0; i < n; i++)
            {
                cout << mtx[i][0];
                for (int j = 1; j < n; j++)
                    cout << ' ' << mtx[i][j];
                cout << '\n';
 
            }
 
        }
    }
    
}