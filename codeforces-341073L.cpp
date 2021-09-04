//http://codeforces.com/group/btcK4I5D5f/contest/341073/problem/L
#include<bits/stdc++.h>
 
using namespace std;
using vi = vector<int>;
using vvi = vector<vector<int>>;
using ii = pair<int, int>;
 
 
struct Primo {    
    static const int LIM = 10'0007;
    bitset<LIM> b;
    vector<int> primos;
 
    Primo()
    {
        b.set();
        primos = { 2 };
        for (int i = 4; i < LIM; i += 2)
            b[i] = false;
        for (long long j = 3; j < LIM; j += 2)
            if (b[j])
            {
                for (long long i = j * j, inc = j + j; i < LIM; i += inc)
                    b[i] = false;
                primos.push_back(j);
            }
    }
};
 
long long pot(int exp)
{
    long long ans = 1;
    for(int i = 0; i < exp; i++)
        ans *= 2;
    return ans;
}
 
int main()
{
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);        
 
    set<long long> Thabit;
    int k = 0;
    long long res = 3 * pot(k) - 1;
    while(res <= 1000000000)
    {
        Thabit.insert(res);
        k++;
        res = 3 * pot(k) - 1;
    }
 
    Primo p;
    int n; 
    cin >> n;
    bool eh_primo = true;
    for(int i = 0; i < p.primos.size() && p.primos[i] < n; i++)
        if(n % p.primos[i] == 0)
        {
            eh_primo = false;
            break;
        }
    bool eh_thabit = Thabit.find(n) != Thabit.end();
 
    if(eh_thabit && eh_primo)
        printf("TP\n");
    else if(eh_thabit)
        printf("T\n");
    else if(eh_primo)
        printf("P\n");
    else
        printf("C\n");
}