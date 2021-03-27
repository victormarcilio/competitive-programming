//https://www.hackerearth.com/practice/algorithms/sorting/merge-sort/practice-problems/algorithm/chandu-and-his-girlfriend-returns/
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int m, n;
        cin >> n >> m;
        int tot = n + m;
        vector<int> v(tot);
        for (int i = 0; i < tot; i++)
            cin >> v[i];
        sort(begin(v), end(v), [](int a, int b){return a > b;});
        cout << v[0];
        for(int i = 1; i < tot; i++)
            cout << ' ' << v[i];
        cout << '\n';
    }
}
