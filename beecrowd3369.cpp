//https://www.beecrowd.com.br/judge/pt/problems/view/3369
#include <bits/stdc++.h>
using namespace std;

int main()
{
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    int N;
    string s;
    cin >> N;
    vector<bitset<26>> v(N);
    bitset<26> start;
    for(int i = 0; i < N; i++)
    {
        cin >> s;
        for(auto c : s)
            v[i][c - 'A'] = 1;
        start[s[0] - 'A'] = 1;
    }
    for(auto& b : v)
        if ((b & start) == b)
        {
            cout << "Y\n";
            return 0;
        }
    cout << "N\n";
}
