#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int N;
    cin >> N;
    while(N--)
    {
        int K, ans, val;
        cin >> K;
        ans = 1 - K;
        while(K--)
        {
            cin >> val;
            ans += val;
        }
        cout << ans << '\n';
    }
}
