//https://www.hackerearth.com/pt-br/problem/algorithm/aniruddha-and-hackerearth/
#include <bits/stdc++.h>
using namespace std;
const int TAM = 1000001;
const long long MOD = 1000000007;
long long E[TAM], H[TAM], ans[TAM];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t, n;
    cin >> t;
    
    E[1] = H[1] = 1;
    ans[1] = 2;
    for(int i = 2; i < TAM; i++)
    {
        E[i] = H[i - 1] % MOD;
        H[i] = (H[i - 1] + E[i - 1]) % MOD;
    }
    for(int i = 2; i < TAM; i++)
        ans[i] = (ans[i - 1] + E[i] + H[i]) % MOD;
    
    while(t--)
    {
        cin >> n;
        cout << ans[n] << '\n';
    }
}
