#include <bits/stdc++.h>
using namespace std;

struct ponto
{
    int x; 
    int y;
    double dist;
};

int main() 
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, ind;
    ponto pontos[499], p;
    double custo, menor;
    while(~scanf("%d", &n))
    {
        custo = 0;
        scanf("%d %d", &p.x, &p.y);
        for(int i = 0; i < n - 1; i++)
        {
            scanf("%d %d", &pontos[i].x, &pontos[i].y);
            pontos[i].dist = 500000;
        }
        while(--n)
        {
            menor = 5000000;
            for(int i = 0; i < n; i++)
            {
                pontos[i].dist = min(pontos[i].dist, hypot(pontos[i].x - p.x, pontos[i].y - p.y));
                if(menor > pontos[i].dist)
                {
                    ind = i;
                    menor = pontos[i].dist;
                }
            }
            custo += menor;
            p = pontos[ind];
            swap(pontos[ind], pontos[n - 1]);
        }
        printf("%.2f\n", custo);
    }
}