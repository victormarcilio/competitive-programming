#include <bits/stdc++.h>
using namespace std;

struct navio
{
    int lucro;
    int multa;
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int N;
    cin >> N;
    vector<navio> navios(N);
    for (int i = 0; i < N; i++)
        cin >> navios[i].lucro >> navios[i].multa;
    int best = -1000000;
    for (int i = 0; i < N; i++)
        for (int j = i + 1; j < N; j++)
        {
            for (int k = j + 1; k < N; k++)
            {
                int current = 0;
                for (int z = 0; z < N; z++)
                    if (z == i || z == j || z == k)
                        current += navios[z].lucro;
                    else
                        current += navios[z].multa;
                best = max(best, current);
            }
        }
    cout << best << '\n';
}
