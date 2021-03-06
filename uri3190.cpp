#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int N, k, val;
    cin >> N;
    int high, low;
    while(N--)
    {
        cin >> k;
        cin >> high;
        low = high;
        while(--k)
        {
            cin >> val;
            low = min(low, val);
            high = max(high, val);
        }
        cout << 2*(high - low) << '\n';
    }
}