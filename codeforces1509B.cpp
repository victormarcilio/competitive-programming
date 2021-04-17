//http://codeforces.com/contest/1509/problem/B
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
 
int main()
{
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
 
    int t, n;
    string s;
    cin >> t;
    while (t--)
    {
        cin >> n >> s;
        vector<char> v;
        bool can = true;
        int T = 0, M = 0;
        for (auto i : s)
            if (i == 'M')
            {
                M++;
                if (M > T)
                {
                    can = false;
                    break;
                }
            }
            else
                T++;
        M = T = 0;
 
        for (int i = n - 1; i >= 0; i--)
            if (s[i] == 'M')
            {
                M++;
                if (M > T)
                {
                    can = false;
                    break;
                }
            }
            else
                T++;
        can = can && T == M * 2;
        cout << (can ? "YES\n" : "NO\n");
    }
}
