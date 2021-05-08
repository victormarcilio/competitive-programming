//http://codeforces.com/problemset/problem/1520/A
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
        cin >> n >> s;
        set<int> chars;
        char c;
        c = s[0];
        chars.insert(c);
        string ans = "YES\n";
        for (int i = 0; i < n; i++)
        {
            while (i < n && s[i] == c)
                i++;
            if (i < n)
            {
                c = s[i];
                if (chars.count(c))
                {
                    ans = "NO\n";
                    break;
                }
                chars.insert(c);
            }
        }
        cout << ans;
    }
    
}