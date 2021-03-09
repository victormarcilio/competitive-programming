#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t, n;
    cin >> t;
    while(t--)
    {
        cin >> n;
        map<char, int> m;
        deque<char> d;
        for(int i = 0; i < n; i++)
            d.push_back('a' + i);
        for(int i = 1; i <= n; i++)
        {
            for(int j = 0; j < i; j++)
            {
                d.push_back(d.front());
                d.pop_front();
            }
            m[d.front()] = i;
            d.pop_front();
        }
        cout << m['a'];
        for(int i = 1; i < n; i++)
            cout << ' ' << m['a' + i];
        cout << '\n';
    }
}