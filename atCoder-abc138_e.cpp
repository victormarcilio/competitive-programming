//https://vjudge.net/problem/AtCoder-abc138_e/origin
//https://atcoder.jp/contests/abc138/tasks/abc138_e?lang=en
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
#include<thread>
#include<queue>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
 
    vector<vector<int>> positions(26);
    string s, q;
    cin >> s >> q;
    for (int i = 0; i < s.size(); i++)
        positions[s[i] - 'a'].push_back(i + 1);
    for(auto c : q)
        if(positions[c - 'a'].empty())
        {
            cout << -1;
            return 0;
        }
    long long ans = 0;
    int curr = 0;
    for (auto c : q)
    {
        auto pos = c - 'a';
        auto it = lower_bound(positions[pos].begin(), positions[pos].end(), curr + 1);
        if (it != positions[pos].end())
        {
            curr = *it;
        }
        else
        {
            ans++;
            curr = *lower_bound(positions[pos].begin(), positions[pos].end(), 0);
        }
    }
    cout << s.size() * ans + curr;
}