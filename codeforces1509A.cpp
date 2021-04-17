//http://codeforces.com/contest/1509/problem/A
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
 
bool f(int x, int y)
{
    if (x % 2 == y % 2)
        return x < y;
    return x % 2;
}
int main()
{
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
 
    int t, n;
    cin >> t;
    while (t--)
    {
        cin >> n;
        vector<int> v(n);
        for (int i = 0; i < n; i++)
            cin >> v[i];
        sort(begin(v), end(v), f);
        cout << v[0];
        for (int i = 1; i < n; i++)
            cout << ' ' << v[i];
        cout << '\n';
    }
}
