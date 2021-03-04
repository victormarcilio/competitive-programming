#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int R, N;
    int count = 1;
    while (cin >> R >> N, R)
    {
        cout << "Case " << count++ << ": ";
        if (N * 27 < R)
            cout << "impossible\n";
        else
            cout << R / N + (R % N != 0) - 1 << '\n';
    }
}
