//https://www.urionlinejudge.com.br/judge/pt/problems/view/2365
#include<bits/stdc++.h>
#pragma warning(disable: 4996)

using namespace std;

struct Apostador
{
    string nome;
    int pontos = 0;
    int guess1[10];
    int guess2[10];

    bool operator<(Apostador const& a) const
    {
        if (pontos != a.pontos)
            return pontos > a.pontos;
        return nome < a.nome;
    }
};

int main()
{
#ifdef _DEBUG
    freopen("C:\\Users\\victor_peixoto\\Desktop\\in.txt", "r", stdin);
   // freopen("C:\\Users\\victor_peixoto\\Desktop\\out.txt", "w", stdout);
#endif
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    int p, n, g1, g2;
    char t1[20], t2[20], nome[20];
    while (scanf("%d %d\n", &p, &n), p)
    {
        vector<Apostador> apostadores(p);
        for (int i = 0; i < p; i++)
        {
            scanf("%s", nome);
            apostadores[i].nome = nome;
            for (int j = 0; j < n; j++)
                scanf("%s %d %s %d\n", t1, &apostadores[i].guess1[j], t2, &apostadores[i].guess2[j]);
            
        }
        for (int j = 0; j < n; j++)
        {
            scanf("%s %d %s %d\n", t1, &g1, t2, &g2);
            int res = g1 - g2;
            for (int i = 0; i < p; i++)
                if (g1 == apostadores[i].guess1[j] && g2 == apostadores[i].guess2[j])
                    apostadores[i].pontos += 10;
                else if ((apostadores[i].guess1[j] - apostadores[i].guess2[j]) * res > 0 && (g1 == apostadores[i].guess1[j] || g2 == apostadores[i].guess2[j]))
                    apostadores[i].pontos += 7;
                else if ((apostadores[i].guess1[j] - apostadores[i].guess2[j]) * res > 0 || (!res && g1 == g2))
                    apostadores[i].pontos += 5;
                else if (g1 == apostadores[i].guess1[j] || g2 == apostadores[i].guess2[j])
                    apostadores[i].pontos += 2;
        }
        sort(begin(apostadores), end(apostadores));
        for (auto& it : apostadores)
            printf("%s %d\n", it.nome.c_str(), it.pontos);
    }
    
}
