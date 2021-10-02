//https://onlinejudge.org/external/126/12658.pdf
#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    vector<string> lines(5);
    cin >> n;
    for(int i = 0; i < 5; i++)
        cin >> lines[i];
    for(int i = 0; i < n; i++)
        if(lines[0][i * 4] == '.')
            cout << 1;
        else if(lines[3][i * 4] == '*')
            cout << 2;
        else
            cout << 3;
    cout << '\n';
}
