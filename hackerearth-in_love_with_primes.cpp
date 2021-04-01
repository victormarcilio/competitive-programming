//https://www.hackerearth.com/practice/math/number-theory/primality-tests/practice-problems/algorithm/in-love-with-primes/
#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, t;
    bitset<100001> b;
    b.set();
    b[1] = 0;
    vector<int> primos{2};
    for (int i = 4; i <= 100000; i += 2)
        b[i] = 0;
    for (int i = 3; i < 100000; i += 2)
        if (b[i])
        {
            primos.push_back(i);
            for (int j = i * 3, inc = i * 2; j < 100000; j += inc)
                b[j] = 0;
        }
    cin >> t;
    while (t--)
    {
        cin >> n;
        bool deepa = false;
        for (int i = 0; primos[i] < n; i++)
        {
            if (b[n - primos[i]])
            {
                deepa = true;
                break;
            }
        }
        if (deepa)
            cout << "Deepa\n";
        else
            cout << "Arjit\n";
    }
}
