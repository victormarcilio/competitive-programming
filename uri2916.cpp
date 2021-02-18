#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    const int MOD = 1'000'000'007;
    int N, K;
    while(cin >> N >> K)
    {
        vector<int> grades(N);
        for(int i = 0; i < N; i++)
            cin >> grades[i];
        sort(begin(grades), end(grades));
        long long ans = 0;
        for(int i = N - 1; K--; --i)
            ans = (ans + grades[i])%MOD;
        cout << ans << '\n';
    }    
}