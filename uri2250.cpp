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
    int n, val, test = 1;
    string name;
    int grades[12];
    while (cin >> n, n)
    {
        vector<pair<string, int>> v;
        while (n--)
        {
            cin >> name;
            for (int i = 0; i < 12; i++)
                cin >> grades[i];
            sort(grades, grades + 12);
            v.push_back({ name, accumulate(grades + 1, grades + 11, 0)});
        }
        sort(begin(v), end(v), [](auto& v1, auto& v2) 
            {
                if (v1.second != v2.second)
                    return v1.second > v2.second;
                return v1.first < v2.first;
            });
        cout << "Teste " << test++ << "\n";
        for (int i = 0; i < v.size(); i++)
        {
            int pos = i + 1;
            int k = i - 1;
            while (k >= 0 && v[k].second == v[i].second)
            {
                k--;
                pos--;
            }
            cout << pos << ' ' << v[i].second << ' ' << v[i].first << '\n';
        }
        cout << '\n';
    }
    
}
