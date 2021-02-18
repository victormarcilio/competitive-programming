#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    vector<int> primes{2, 3, 5};
    for(int i = 7; i <= 1100; i += 2)
    {
        bool is_prime = true;
        for(auto prime : primes)
            if(i % prime ==  0)
            {
                is_prime = false;
                break;
            }
        if(is_prime)
            primes.push_back(i);
    }

    int N;
    cin >> N;
    auto it = lower_bound(begin(primes), end(primes), N + 1) - 1;
    while(*it - *(it - 1) != 2)
        --it;
    cout << *(it - 1) << ' ' << *it << '\n';
}