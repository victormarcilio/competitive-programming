//https://www.hackerearth.com/pt-br/problem/algorithm/average-sequence-4/
#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n, acc;
    cin >> n;
    vector<int> v(n), ans(n);
    cin >> acc;
    v[0] = ans[0] = acc;
    for(int i = 1; i < n; i++)
    {
        cin >> v[i];
        ans[i] = v[i] *(i + 1) - acc; 
        acc += ans[i];
    }
    cout << ans[0];
    for(int i = 1; i < n; i++)
        cout << ' ' << ans[i];
    cout << '\n';
}
