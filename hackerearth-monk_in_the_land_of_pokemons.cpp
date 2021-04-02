//https://www.hackerearth.com/pt-br/problem/algorithm/monk-in-the-land-of-pokemons/
#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t, n, x, y;
    cin >> t;
    while(t--)
    {
        cin >> n;
        int ans = 0;
        unordered_map<int, int> s;
        while(n--)
        {
            cin >> x >> y;
            s[x]++;
            if(s[y])
                s[y]--;
            else
                ans++;
        }
        cout << ans << '\n';
    }
}
