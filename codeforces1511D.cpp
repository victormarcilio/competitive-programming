//http://codeforces.com/contest/1511/problem/D
#include <bits/stdc++.h>
using namespace std;
const int MOD = 1'000'000'007;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, t;
    cin >> t >> n;
    string s(t, 'a');
    if (n == 1)
    {
        cout << s << '\n';
        return 0;
    }
    int last_letter = 'a' + n - 1;
    int first_letter = 'a';
    int second_letter = 'a';
    bool position = true;
    int i;
    for (i = 0; i < t; i++, position = !position)
    {
        if (position)
        {
            s[i] = first_letter;
            first_letter++;
            if (first_letter > last_letter)
            {
                second_letter++;
                if (second_letter == last_letter)
                {
                    if (i + 1 < t)
                        s[++i] = last_letter;
                    s.erase(i + 1);
                    break;
                }
                first_letter = second_letter;
                position = !position;
            }
        }
        else
        {
            s[i] = second_letter;
        }
    }
    while (s.size() < t)
        s += s;
    s.resize(t);
    cout << s << '\n';
}