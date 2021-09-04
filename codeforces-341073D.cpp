//http://codeforces.com/group/btcK4I5D5f/contest/341073/problem/D
#include<bits/stdc++.h>
 
using namespace std;
using vi = vector<int>;
using vvi = vector<vector<int>>;
using ii = pair<int, int>;
 
map<string, char> m;
 
char numero(vector<string>& lines, int start)
{
    return m[lines[0].substr(start, 3) + lines[1].substr(start, 3) + lines[2].substr(start, 3)];
}
 
int main()
{
    m["     |  |"] = '1';
    m[" _  _||_ "] = '2';
    m[" _  _| _|"] = '3';
    m["   |_|  |"] = '4';
    m[" _ |_  _|"] = '5';
    m[" _ |_ |_|"] = '6';
    m[" _   |  |"] = '7';
    m[" _ |_||_|"] = '8';
    m[" _ |_| _|"] = '9';
    m[" _ | ||_|"] = '0';
 
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);    
    vector<string> lines(3);
    string N;
    getline(cin, N);
    int n = stoi(N);
    getline(cin, lines[0]);
    getline(cin, lines[1]);
    getline(cin, lines[2]);
    string ans;
    for(int i = 0; i < n; i += 3)
        ans += numero(lines, i);
    cout << ans;
}