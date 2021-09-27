//https://www.urionlinejudge.com.br/judge/pt/challenges/view/605/3
#include <iostream>
#include <algorithm>
#include <vector>
#include <regex>
#include <set>
#include <map>
#include <unordered_map>
#include <deque>
#include <bitset>
using namespace std;


struct Primo {
    //Raiz do valor maximo no problema: Problema diz até 10^8, LIM deve ser 10^4
    static const int LIM = 1'000'001;
    static const int LIM2 = 1'007;
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
                for (long long k = j * j, inc = j + j; k < LIM; k += inc)
                    b[k] = false;
                primos.push_back(j);
            }
    }
};

int main()
{
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int q, l, r, k;
    
   
    Primo p;
    int i;
    cin >> q;
    while (q--)
    {
        int ans = -1;
        cin >> l >> r >> k;
        auto start = lower_bound(p.primos.begin(), p.primos.end(), l);
        if (start + k - 1 < p.primos.end() && *(start + k - 1) <= r)
              ans = *(start + k - 1);
        

        cout << ans << '\n';
    }
}