//https://www.urionlinejudge.com.br/judge/pt/challenges/view/604/1
#include <iostream>
#include <algorithm>
#include <vector>
#include <regex>
#include <set>

using namespace std;

int main()
{
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    vector<long long> s;
    for (long long i = 0; i * i <= 1'0000'0000; i++)
        s.push_back(i * i);

    int from, to;
    int tests;
    cin >> tests;
    while (tests--)
    {
        cin >> from >> to;
        int ans = 0;
        for (int i = 0; i < s.size() && s[i] <= to ; i++)
            if (s[i] >= from && s[i] <= to)
                ans++;
        cout << ans << '\n';
    }
}