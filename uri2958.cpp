#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, m;
    cin >> n >> m;
    int total = n * m;
    vector<string> problems(n * m);
    for (int i = 0; i < total; i++)
        cin >> problems[i];
    sort(begin(problems), end(problems), [](string s1, string s2) { if(s1[1] == s2[1]) return s1 > s2; else return s1[1] == 'V'; });
    for (auto it : problems)
        cout << it << '\n';
}
