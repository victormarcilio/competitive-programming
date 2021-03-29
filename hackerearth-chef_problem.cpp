//https://www.hackerearth.com/pt-br/problem/algorithm/chef-problem/
#include <bits/stdc++.h>
using namespace std;

int f(string s)
{
    int result = 0;
    for (int i = 0; i < s.size(); i++)
        result += s[i] == 'B';
    if(s.size() > 1)
        result += max(f(s.substr(0, s.size()/2)), f(s.substr(s.size()/2))); 
    
    return result;
}

int main()
{
    int t, e, b, v;
    cin >> t;
    while (t--)
    {
        cin >> b >> e >> v;
        string s(b, 'B');
        for (int i = 0; i < e; i++)
            s.push_back('E');
        int ans = 0;
        do
        {
            if (f(s) == v)
                ans++;
        } while (next_permutation(begin(s), end(s)));
        cout << ans << '\n';
    }
}
