//https://www.hackerearth.com/practice/algorithms/sorting/merge-sort/practice-problems/algorithm/chandu-and-his-girlfriend/
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t, n;
    cin >> t;    
    while(t--)
    {
        cin >> n;
        vector<int> v(n);
        for(int i = 0; i < n; i++)
            cin >> v[i];
        sort(begin(v), end(v), [](int a, int b){return a > b;});
        cout << v[0];
        for(int i = 1; i < n; i++)
            cout << ' ' << v[i];
        cout << '\n';
    }
}
