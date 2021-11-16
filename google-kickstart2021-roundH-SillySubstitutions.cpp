//https://codingcompetitions.withgoogle.com/kickstart/round/0000000000435914/00000000008d94f5
//passes on Test Set 1, TLE on Test Set 2

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
    
    int T, N;
    string s;
    cin >> T;
    vector<pair<string, string>> replacements{ {"01", "2"},  {"12", "3"},  {"23", "4"},  {"34", "5"},  {"45", "6"},  {"56", "7"},  {"67", "8"},  {"78", "9"},  {"89", "0"},  {"90", "1"}};
    for (int i = 1; i <= T; i++)
    {
            cin >> N >> s;
        string ans;
        bool changed = true;
        while (changed)
        {
            changed = false;
            for (auto [from, to] : replacements)
            {
                char ultimo = from[1];
                char penultimo = from[0];

                for (auto c : s)
                {
                    ans.push_back(c);
                    while (ans.size() > 1 && ans.back() == ultimo && ans[ans.size() - 2] == penultimo)
                    {   
                        changed = true;
                        ans.pop_back();
                        ans.pop_back();
                        ans.push_back(to[0]);
                    }
                }
                s = move(ans);
            }
        }
        cout << "Case #" << i << ": " << s << '\n';
    }
}
