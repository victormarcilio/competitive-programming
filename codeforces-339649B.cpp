//https://codeforces.com/group/nituVTsHQX/contest/339649/problem/B
#include<bits/stdc++.h>
 
using namespace std;
 
int main()
{
    int n;
    cin >> n;
    vector<int> v(n);
    for(int i = 0; i < n; i++)
        cin >> v[i];
    sort(begin(v), end(v));
    auto mid = v[n/2];
    long long ans = 0;
    for(auto i : v)
        ans += abs(mid - i);
    cout << ans;
}