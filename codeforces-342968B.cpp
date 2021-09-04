//http://codeforces.com/gym/342968/problem/B
#include<bits/stdc++.h>
using namespace std;
 
using vi = vector<int>;
using vvi = vector<vector<int>>;
 
int main()
{
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int n;
    cin >> n;
    deque<int> v(n);
    for (int i = 0; i < n; i++)
        cin >> v[i];
    auto v2 = v;
    sort(begin(v2), end(v2));
    map<int, deque<int>> m;
    for (int i = 0; i < n; i++)
        m[v2[i]].push_back(v2[n - 1 - i]);
    vector<int> result;
    for (auto i : v)
    {
        result.push_back(m[i].front());
        m[i].pop_front();
    }
    for (auto i : result)
        cout << i << ' ';
}