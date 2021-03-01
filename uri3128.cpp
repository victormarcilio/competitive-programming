#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int v[2];
    cin >> v[0] >> v[1];
    sort(v, v + 2);
    cout << (v[0] > 5 && (v[0] > 13 || v[1] > 17) ? "YES\n" : "NO\n"); 
}
