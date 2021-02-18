#include <bits/stdc++.h>
using namespace std;

long long geometric_progression(int base, int exponent)
{
    long long  numerator = base;
    for(int i = 1; i < exponent; ++i)
        numerator *= base;
    return (numerator - 1)/(base - 1);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    bitset<10010> is_prime;
    is_prime.set();
    for(int i = 2; i <= 1'000'0; i += 2)
        is_prime[i] = false;
    vector<int> primes {2};
    for(int i = 3; i < 1'000'0; i += 2)
        if(is_prime[i])
        {
            primes.push_back(i);
            for(int j = i * 3, inc = i * 2; j < 1'000'0; j += inc)
                is_prime[j] = false;
        }
  
    int N, mat;
    cin >> N;
    while(N--)
    {
        cin >> mat;
    
        long long ans = 1;
        for(int i = 0; mat != 1 && i < primes.size(); ++i)
            if(mat%primes[i] == 0)
            {
                int repetitions = 1;
                mat = mat/primes[i];
                while(mat%primes[i] == 0)
                {
                    mat = mat/primes[i];
                    ++repetitions;
                }
                ans *= geometric_progression(primes[i], repetitions + 1);
            }
        if(mat != 1)
            ans *= geometric_progression(mat, 2);
        cout << ans << '\n';
    }
}