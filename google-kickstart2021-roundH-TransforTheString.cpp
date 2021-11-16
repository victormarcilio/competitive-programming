//https://codingcompetitions.withgoogle.com/kickstart/round/0000000000435914/00000000008da461
#include <iostream>
#include <algorithm>
#include <vector>
#include <regex>
#include <set>
#include <map>
#include<sstream>
#include <unordered_map>
#include <unordered_set>
#include <deque>
#include <bitset>
#include<numeric>
#include<queue>
using namespace std;


int main()
{
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    map<pair<int, int>, int> distances;
    for (int i = 0; i < 26; i++)
    {
        char current = 'a' + i;
        char left = 'a' + i;
        char right = 'a' + i;
        distances[{current, current}] = 0;
        for (int j = 0; j < 26; j++)
        {
            if (--left < 'a')
                left = 'z';
            if (++right > 'z')
                right = 'a';
            if (distances.find({ current,right }) == distances.end())
                distances[{current, right}] = distances[{right, current}] = j + 1;
            if (distances.find({ current,left }) == distances.end())
                distances[{current, left}] = distances[{left, current}] = j + 1;
        }
    }
    int T;
    string s1, s2;
    cin >> T;
    for (int i = 1; i <= T; i++)
    {
        cin >> s1 >> s2;
        int ans = 0;
        for (auto c : s1)
        {
            if (s2.find(c) == string::npos)
            {
                int best = 30;
                for (auto c2 : s2)
                    best = min(distances[{c, c2}], best);
                ans += best;
            }
        }
        cout << "Case #" << i << ": " << ans << '\n';
    }
}
