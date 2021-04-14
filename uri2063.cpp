/https://www.urionlinejudge.com.br/judge/pt/problems/view/2063
#include <bits/stdc++.h>
using namespace std;

int foi[101];

int main()
{
    int n, v[101];
    vector<int> primos{2};
    for(int i = 3; i < 100; i += 2)
    {
        bool eh = true;
        for(auto it : primos)
            if(i % it == 0)
                eh = false;
        if(eh)
            primos.push_back(i);
    }
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
        scanf("%d", &v[i]);
    vector<int> ciclos;
    for (int i = 1; i <= n; i++)
    {
        int c = 0;
        int pos = v[i];
        while (!foi[pos])
        {
            foi[pos]++;
            pos = v[pos];
            c++;
        }
        if (c)
            ciclos.push_back(c);
    }
    map<int, int> m;
    for(auto it : ciclos)
    {
        for(int i = 0; it > 1; i++)
            if(it % primos[i] == 0)
            {
                int expo = 1;
                it /= primos[i]; 
                while(it % primos[i] == 0)
                {
                    expo++;
                    it /= primos[i];
                }
                m[primos[i]] = max(expo, m[primos[i]]);
            }
    }
    int ans = 1;
    for (auto it : m)
        for(int i = 0; i < it.second; i++)
            ans *= it.first;
    printf("%d\n", ans);

}