#include <bits/stdc++.h>

using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t, n;
    cin >> t;
    string S;
    for (int c = 1; c <= t; c++)
    {
        string ans = "";
        cin >> S;
        int current_depth = 0;
        for (int i = 0; i < S.size(); i++)
        {
            int new_depth = S[i] - '0';

            while (current_depth < new_depth)
            {
                current_depth++;
                ans += '(';
            }
            while (current_depth > new_depth)
            {
                ans += ')';
                current_depth--;
            }
            ans += S[i];
        }
        while (current_depth--)
            ans += ')';
        cout << "Case #" << c << ':' << ' ' << ans << '\n';
    }
}
