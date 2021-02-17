#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
	cin.tie(NULL);
    int n;
    string s;
    cin >> n;
    cin.ignore();
    map<char, int> m;
    m['a'] = 2;
    m['b'] = 22;
    m['c'] = 222;
    m['d'] = 3;
    m['e'] = 33;
    m['f'] = 333;
    m['g'] = 4;
    m['h'] = 44;
    m['i'] = 444;
    m['j'] = 5;
    m['k'] = 55;
    m['l'] = 555;
    m['m'] = 6;
    m['n'] = 66;
    m['o'] = 666;
    m['p'] = 7;
    m['q'] = 77;
    m['r'] = 777;
    m['s'] = 7777;
    m['t'] = 8;
    m['u'] = 88;
    m['v'] = 888;
    m['w'] = 9;
    m['x'] = 99;
    m['y'] = 999;
    m['z'] = 9999;
    m[' '] = 0;
    while(n--)
    {
        getline(cin, s);
        for(int i = 0; i < s.size(); i++)
        {
            if(isupper(s[i]))
                cout << '#';
            else if(i && m[tolower(s[i - 1])]%10 == m[tolower(s[i])]%10)
                cout << '*';
            cout << m[tolower(s[i])];   
        }
        cout << '\n';
    }
}
