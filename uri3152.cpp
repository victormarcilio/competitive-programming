#include<bits/stdc++.h>
#pragma warning(disable: 4996)
using namespace std;

int area(vector<pair<int, int>>& v)
{
    int ans = 0;
    v.push_back(v[0]);
    for (int i = 0; i < v.size() - 1; i++)
        ans += v[i].first * v[i + 1].second - v[i].second * v[i + 1].first;
    return abs(ans);
}

int main()
{
#ifdef _LOCAL
    freopen("C:\\Users\\victor_peixoto\\Desktop\\in.txt", "r", stdin);
    //freopen("C:\\Users\\victor_peixoto\\Desktop\\out.txt", "w", stdout);
#endif
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    vector<pair<int, int>> v1(4), v2(4);
    int x, y;
    for (int i = 0; i < 4; i++)
    {
        cin >> x >> y;
        v1[i] = { x, y };
    }
    for (int i = 0; i < 4; i++)
    {
        cin >> x >> y;
        v2[i] = { x, y };
    }
    
    auto a1 = area(v1);
    auto a2 = area(v2);
    if (a1 > a2)
        cout << "terreno A\n";
    else
        cout << "terreno B\n";
}