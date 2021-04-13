#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m, k;
    while (cin >> n >> m >> k, n)
    {
        int c = 0;
        int person = 1;
        int inc = 1;
        int number = 1;

        while (number < 10000 || c)
        {
            if (person == m && (number % 7 == 0 || to_string(number).find('7') != string::npos))
                c++;
            if (c == k)
            {
                cout << number << '\n';
                break;
            }
                person += inc;
            if (person == 1 || person == n)
                inc = -inc;
            number++;
        }

        if (!c)
            cout << "-1\n";
    }
}