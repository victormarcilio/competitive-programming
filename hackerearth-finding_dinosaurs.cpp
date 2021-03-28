//https://www.hackerearth.com/pt-br/problem/algorithm/finding-dinosaurs-1/
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int q, n, l, k;
    string name;
    cin >> n >> k >> l >> q;
    map<vector<int>, string> m;
    for (int i = 0; i < n; i++)
    {
        vector<int> v(k);
        cin >> name;
        for(int j = 0; j < k; j++)
            cin >> v[j];
        m[v] = name;
    }
    for(int i = 0; i < q; i++)
    {
        vector<int> v(k);
        for(int j = 0; j < k; j++)
            cin >> v[j];
        if(m.count(v))
            cout << m[v] << '\n';
        else
            cout << "You cant fool me :P\n";
    }
}
