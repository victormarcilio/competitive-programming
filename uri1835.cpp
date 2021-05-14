//https://www.urionlinejudge.com.br/judge/pt/problems/view/1835
#include<bits/stdc++.h>
#pragma warning(disable: 4996)

using namespace std;

struct UnionFind
{
    vector<int> group;
    vector<int> sizes;
    int N;
    UnionFind(int n) : N{ n + 1 }
    {
        group = vector<int>(N);
        sizes = vector<int>(N);
        iota(begin(group), end(group), 0);
        fill(begin(sizes), end(sizes), 1);
    }

    int get_group_number(int ind)
    {
        if (group[ind] == ind)
            return ind;
        return group[ind] = get_group_number(group[ind]);
    }
    //returns true if a merge happened
    bool merge(int ind1, int ind2)
    {
        int group1 = get_group_number(ind1);
        int group2 = get_group_number(ind2);
        if (group1 != group2)
        {
            if (sizes[group1] > sizes[group2])
            {
                sizes[group1] += sizes[group2];
                group[group2] = group[group1];
            }
            else
            {
                sizes[group2] += sizes[group1];
                group[group1] = group[group2];
            }
        }
        return group1 != group2;
    }

    int get_group_size(int ind)
    {
        return sizes[get_group_number(ind)];
    }
    bool is_same_group(int x, int y)
    {
        return get_group_number(x) == get_group_number(y);
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

    int t, n, m, x, y;
    scanf("%d", &t);
    for(int caso = 1; caso <= t; caso++)
    {
        scanf("%d %d", &n, &m);
        UnionFind u(n);
        while (m--)
        {
            scanf("%d %d", &x, &y);
            u.merge(x, y);
        }
        bitset<101> b;
        b.reset();
        for (int i = 1; i <= n; i++)
            b[u.get_group_number(i)] = true;
        int ans = b.count() - 1;
        printf("Caso #%d: ", caso);
        if (!ans)
            printf("a promessa foi cumprida\n");
        else
            printf("ainda falta(m) %d estrada(s)\n", ans);
    }
}
