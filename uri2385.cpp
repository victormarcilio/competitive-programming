#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);  
    cin.tie(NULL); 
    int n, p, q, r, s, x, y, X, Y;
    cin >> n >> p >> q >> r >> s >> x >> y >> X >> Y;
    long long ans = 0;
    for(int i = 1; i <= n; i++)
        ans += ((p * X + q * i) % x) * ((r * i + s * Y) % y);
   
    cout << ans << '\n';
}