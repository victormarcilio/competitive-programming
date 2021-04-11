//https://www.urionlinejudge.com.br/judge/pt/problems/view/2084
#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++)
        cin >> v[i];
    sort(begin(v), end(v));
    double total = accumulate(begin(v), end(v), 0);
    if (v.back()*100 >= 45*total || v.back() * 10 >= 4 * total && (v.back() - v[v.size() - 2]) * 10 >= total)
        cout << "1\n";
    else
        cout << "2\n";
}
