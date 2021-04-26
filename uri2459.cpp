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
#ifdef _LOCAL
    freopen("C:\\Users\\victor_peixoto\\Desktop\\in.txt", "r", stdin);
    //freopen("C:\\Users\\victor_peixoto\\Desktop\\out.txt", "w", stdout);
#endif
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int n, f, r, from, to, cost;
    cin >> n >> f >> r;
    UnionFind u(n);
    priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;
    while (f--)
    {
        cin >> from >> to >> cost;
        pq.push({ cost, {from, to} });
    }
    int ans = 0;
    while (!pq.empty())
    {
        auto [c, b] = pq.top();
        pq.pop();
        auto [from, to] = b;
        if (u.merge(from, to))
            ans += c;
    }
    while (r--)
    {
        cin >> from >> to >> cost;
        pq.push({ cost, {from, to} });
    }
    while (!pq.empty())
    {
        auto [c, b] = pq.top();
        pq.pop();
        auto [from, to] = b;
        if (u.merge(from, to))
            ans += c;
    }
    cout << ans << '\n';
}
