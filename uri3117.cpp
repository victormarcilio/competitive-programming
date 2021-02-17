#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int N, K, acc = 0, arrival;
    cin >> N >> K;
    while(N--)
    {
        cin >> arrival;
        acc += arrival < 1;
    }
    cout << (acc >= K ? "YES\n" : "NO\n");
}
