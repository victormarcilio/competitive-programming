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
    
    int m, x, t, n, temp;
    cin >> t;
    while (t--)
    {
        cin >> n >> m >> x;
        vector<pair<int, int>> v(n);
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        for (int i = 1; i <= m; i++)
            pq.push({ 0, i });
 
        for (int i = 0; i < n; i++)
        {
            cin >> temp;
            v[i] = { temp, i };
        }
        sort(begin(v), end(v));
        vector<int> assignments(n);
        int pos = n - 1;
        while (pos >= 0)
        {
            auto [tamanho, torre] = pq.top();
            pq.pop();
            pq.push({ tamanho + v[pos].first, torre });
            assignments[v[pos].second] = torre;
            pos--;
        }
        auto [menor, _] = pq.top();
        pq.pop();
        int maior = menor;
        while (!pq.empty())
        {
            auto [x, y] = pq.top();
            pq.pop();
            maior = x;
        }
        if (maior - menor > x)
            cout << "NO\n";
        else
        {
            cout << "YES\n";
            cout << assignments[0];
            for (int i = 1; i < n; i++)
                cout << ' ' << assignments[i];
            cout << '\n';
        }
    }
    
}