//https://www.hackerearth.com/practice/algorithms/string-algorithm/basics-of-string-manipulation/practice-problems/algorithm/password-1/
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    string pass;
    set<string> s;
    while (t--)
    {
        cin >> pass;
        s.insert(pass);
        reverse(begin(pass), end(pass));
        if(s.count(pass))
        {
            cout << pass.size() << ' ' << pass[pass.size()/2] << '\n';
            break;
        }
    }
}
