#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int N, M;
    int current, top;
    cin >> N >> M >> top;
    for(int i = 1; i < 30; i++)
    {
        cin >> current;
        top = max(top, current);
    }
    cout << (M - N) / top + ((M - N)% top != 0) << '\n';
}
