#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t, n, k;
    string s;
    cin >> t;
    for (int c = 1; c <= t; c++)
    {
        cin >> n >> k >> s;
        int difs = 0;
        for(int i = 0, j = n - 1; i < n/2; i++, j--)
            if(s[i] != s[j])
                difs++;

        cout << "Case #" << c << ": " << abs(k - difs) << '\n';
    }
}
