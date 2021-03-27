//https://www.hackerearth.com/pt-br/challenges/competitive/march-circuits-21/algorithm/fair-competition-0315250e/
//https://www.hackerearth.com/practice/data-structures/disjoint-data-strutures/basics-of-disjoint-data-structures/practice-problems/algorithm/fair-competition-0315250e/

#include <bits/stdc++.h>
using namespace std;

int get_group(vector<int> &groups, int ind)
{
    if (ind == groups[ind])
        return ind;
    return groups[ind] = get_group(groups, groups[ind]);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t, n, m, x, p1, p2;
    cin >> t;
    while (t--)
    {
        cin >> n >> m;
        vector<int> groups(n + 1);
        vector<int> sizes(n + 1, 1);
        iota(begin(groups), end(groups), 0);
        while (m--)
        {
            cin >> p1 >> p2;
            int g1 = get_group(groups, p1);
            int g2 = get_group(groups, p2);
            if (g1 != g2)
            {
                if (sizes[g1] > sizes[g2])
                {
                    sizes[g1] += sizes[g2];
                    groups[g2] = g1;
                }
                else
                {
                    sizes[g2] += sizes[g1];
                    groups[g1] = g2;
                }
            }
        }
        int ways = 0;
        unordered_set<int> different_groups;
        for(int i = 1; i <= n; i++)
            different_groups.insert(get_group(groups, i));
        
        for(auto it = different_groups.begin(); it != different_groups.end(); it++)
        {
            int curr_size = sizes[*it];
            ways += 2 * curr_size * (n - curr_size);
            n -= curr_size;
        }
        cout << ways << '\n';
    }
}
