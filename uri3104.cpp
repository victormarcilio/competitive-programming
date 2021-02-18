#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string A;
    int B;
    cin >> A >> B;

    int ans = 0;
    for(auto i : A)
    {
        ans = (ans * 10 + (i - '0'));
        if(ans >= B)
            ans %= B;
    }
    cout << ans << '\n';
    
}