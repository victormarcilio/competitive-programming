#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int N, T, K, P;
    cin >> T;
    for (int i = 1; i <= T; i++)
    {
        cin >> N >> K >> P;
        P = P % N;
        cout << "Case " << i << ": " << (K + P <= N ? K + P : (K + P) % N) << '\n';
    }
}
