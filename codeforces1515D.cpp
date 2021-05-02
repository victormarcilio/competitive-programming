#include<bits/stdc++.h>
#pragma warning(disable: 4996)
 
using namespace std;
 
int main()
{
#ifdef _DEBUG
    freopen("C:\\Users\\victor_peixoto\\Desktop\\in.txt", "r", stdin);
    //freopen("C:\\Users\\victor_peixoto\\Desktop\\out.txt", "w", stdout);
#endif
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
 
    int l, r, v, t, n;
    cin >> t;
    while (t--)
    {
        cin >> n >> l >> r;
        map<int, int> m;
        for (int i = 0; i < l; i++)
        {
            cin >> v;
            m[v]++;
        }
        for (int i = 0; i < r; i++)
        {
            cin >> v;
            m[v]--;
        }
        int ans = 0;
        int difs = 0;
        for (auto&[tamanho, quantidade] : m)
        {
            while (quantidade > 1 && l > r)
            {
                quantidade -= 2;
                ans++;
                l--;
                r++;
            }
            while (quantidade < -1 && l < r)
            {
                quantidade += 2;
                ans++;
                l++;
                r--;
            }
        }
        for (auto& [tamanho, quantidade] : m)
			difs += abs(quantidade);
        ans += difs/2 + abs(l - r)/2;
        cout << ans << '\n';
    }
 
}