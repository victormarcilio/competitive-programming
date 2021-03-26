//https://www.hackerearth.com/practice/data-structures/hash-tables/basics-of-hash-tables/practice-problems/algorithm/mind-palaces-3/
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, m, v;
    scanf("%d %d", &n, &m);
    unordered_map<int, pair<int, int>> M;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
        {
            scanf("%d", &v);
            M[v] = {i, j};
        }
    scanf("%d", &n);
    while(n--)
    {
        scanf("%d", &v);
        if(M.count(v))
            printf("%d %d\n", M[v].first, M[v].second);
        else
            puts("-1 -1\n");
    }
}
