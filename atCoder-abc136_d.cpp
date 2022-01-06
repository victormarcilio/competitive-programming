//https://vjudge.net/problem/AtCoder-abc136_d/origin
//https://atcoder.jp/contests/abc136/tasks/abc136_d?lang=en
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

string s = "RRL";
vector<int> v(s.size(), 1);
void print()
{
    for (int i = 0; i < v.size(); i++)
        cout << v[i] << ' ';
    cout << "\n\n";
}

void rot()
{
    vector v2 = vector<int>(v.size());
    for (int i = 0; i < v.size(); i++)
        if (s[i] == 'R')
            v2[i + 1] += v[i];
        else
            v2[i - 1] += v[i];
     v = move(v2);
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
 /*  for (int i = 0; i < 10; i++)
   {
       rot();
       cout << "\n\nROUND " << i + 1 << '\n';
       print();
   }*/
    cin >> s;
    for (int i = 0; i < s.size(); i++)
    {
        int r = 0;
        int l = 0;
        while (s[i] == 'R')
        {
            r++;
            i++;
        }
        while (i < s.size() && s[i] == 'L')
        {
            l++;
            i++;
        }
        if (s[i] == 'R')
            i--;
        for (int k = 1; k < r; k++)
            cout << "0 ";

        if ((r + l) % 2 == 0)
            cout << (r + l) / 2 << ' ' << (r + l) / 2 << ' ';
        else
            cout << (r + l) / 2 + r % 2 << ' ' << (r + l) / 2 + l % 2<< ' ';
        for (int k = 1; k < l; k++)
            cout << "0 ";
    }
 
}