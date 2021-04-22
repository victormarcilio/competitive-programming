#include<bits/stdc++.h>
#pragma warning(disable: 4996)
using namespace std;

struct UnionFind
{
    vector<int> group;
    vector<int> sizes;
    int N;
    UnionFind(int n) : N{ n }
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
#ifdef _LOCA
    freopen("C:\\Users\\victor_peixoto\\Desktop\\in.txt", "r", stdin);
    //freopen("C:\\Users\\victor_peixoto\\Desktop\\out.txt", "w", stdout);
#endif
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    
    int n, m;
    cin >> m >> n;

    UnionFind u(m);
    map<string, int> mapa;
    string s1, s, s2;
    int x1, x2;
    while (n--)
    {
        cin >> s1 >> s >> s2;
        if (mapa.find(s1) == mapa.end())
            mapa[s1] = mapa.size();
        x1 = mapa[s1];
        
        if (mapa.find(s2) == mapa.end())
            mapa[s2] = mapa.size();
        x2 = mapa[s2];
        u.merge(x1, x2);
    }
    set<int> difs;
    for (int i = 0; i < u.N; i++)
        difs.insert(u.get_group_number(i));
    cout << difs.size() << '\n';
    
}
