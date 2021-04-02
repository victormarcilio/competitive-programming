//https://www.hackerearth.com/pt-br/problem/algorithm/arrange-if-you-can/
#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, t, x;
    bitset<1001> b;
    b.set();
    b[1] = 0;
    vector<int> primos{2};
    for (int i = 4; i <= 1000; i += 2)
        b[i] = 0;
    for (int i = 3; i < 1000; i += 2)
        if (b[i])
        {
            primos.push_back(i);
            for (int j = i * 3, inc = i * 2; j < 1000; j += inc)
                b[j] = 0;
        }
    cin >> t;
    while (t--)
    {
        cin >> n >> x;
        int N = n;
        set<int> divisors;
        divisors.insert(1);
        for (int i = 0; i < primos.size() && n > 1; i++)
        {
            while (n % primos[i] == 0)
            {
                n = n / primos[i];
                vector<int> insertions;
                insertions.reserve(divisors.size());
                for (auto it : divisors)
                    insertions.push_back(it * primos[i]);
                for (auto it : insertions)
                    divisors.insert(it);
            }
        }
        if (n > 1)
        {
            vector<int> insertions;
            for (auto it : divisors)
                insertions.push_back(it * n);
            for (auto it : insertions)
                divisors.insert(it);
        }
        int ans = 0;
        for (auto it : divisors)
        {
            if (it >= x && N / it >= x)
                ++ans;
        }
        cout << ans << '\n';
    }
}
