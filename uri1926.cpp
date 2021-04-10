//https://www.urionlinejudge.com.br/judge/pt/problems/view/1926
//Hint: X might be greater than Y...

#include <bits/stdc++.h>
using namespace std;

const int LIMIT = 1'000'002;
const int LIMIT2 = 1'000'000;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    bitset<LIMIT> b;
    b.set();
    for (long long i = 3; i < LIMIT; i += 2)
        if (b[i])
            for (long long j = i * i, inc = i + i; j < LIMIT; j += inc)
                b[j] = false;
    vector<int> gemeos;
    gemeos.reserve(50000);
    for (int i = 3; i < LIMIT2; i += 2)
        if (b[i] && (b[i + 2] || b[i - 2]))
            gemeos.push_back(i);

    int Q, from, to;
    cin >> Q;
    while (Q--)
    {
        cin >> from >> to;
        if(from > to)
            swap(from, to);
        cout << upper_bound(begin(gemeos), end(gemeos), to) - lower_bound(begin(gemeos), end(gemeos), from) << '\n';
    }
}
