#include <bits/stdc++.h>
using namespace std;

int t, x, y;

int cost_of_two(char c1, char c2)
{
    if (c1 == c2)
        return 0;
    if (c1 == 'J')
        return y;
    return x;
}

int main()
{
    string s;
    cin >> t;
    for (int c = 1; c <= t; c++)
    {
        cin >> x >> y >> s;
        int sub = s.find_first_not_of('?');
        if (sub != string::npos)
            s = s.substr(sub);
        else
            s = "";
        while (!s.empty() && s.back() == '?')
            s.pop_back();
        s = regex_replace(s, regex(R"(\?+)"), "?");
        int cost = 0;
        int limit = s.size();
        s.push_back('!');
        for (int i = 1; i < limit; i++)
        {
            if (s[i] == '?')
            {
                if (s[i - 1] == s[i + 1])
                    s[i] = s[i - 1];
                else
                {
                    int costJ = cost_of_two(s[i - 1], 'J') + cost_of_two('J', s[i + 1]);
                    int costC = cost_of_two(s[i - 1], 'C') + cost_of_two('C', s[i + 1]);

                    if (costC < costJ)
                        s[i] = 'C';
                    else
                        s[i] = 'J';
                }
            }
            cost += cost_of_two(s[i - 1], s[i]);
        }
        cout << "Case #" << c << ": " << cost << '\n';
    }
}
