//https://www.hackerearth.com/practice/basic-programming/implementation/basics-of-implementation/practice-problems/algorithm/car-names-4/
#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    string s;
    cin >> n;
    while (n--)
    {
        cin >> s;
        int tam = s.size();
        bool ok = tam % 3 == 0 && s[0] != s.back() && s[0] != s[tam / 3] && s.back() != s[tam / 3];
        for (int i = 1; i < tam / 3; i++)
            if (s[i] != s[0])
                ok = false;
        for (int i = tam / 3 + 1; i < tam / 3 * 2; i++)
            if (s[i] != s[tam / 3])
                ok = false;
        for (int i = 1 + tam / 3 * 2; i < tam; i++)
            if (s[i] != s.back())
                ok = false;
        if (!ok)
            cout << "Not ";
        cout << "OK\n";
    }
}
