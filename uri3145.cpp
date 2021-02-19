#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int N, X;

    cin >> N >> X;
    cout << setprecision(2) << fixed << static_cast<double>(X)/(N + 2) << '\n';
}
