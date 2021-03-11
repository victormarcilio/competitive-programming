#include <bits/stdc++.h>
using namespace std;


int used[1000001];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int f, s, g, u, d;
    
    cin >> f >> s >> g >> u >> d;
    
    queue<pair<int, int>> q;
    
    q.push({s, 0});
    while(!q.empty())
    {
        auto front = q.front();
        if(front.first == g)
        {
            cout << front.second << '\n';
            return 0;
        }
        q.pop();
        int novo = front.first - d;
        if(novo > 0 && !used[novo])
        {
            used[novo] = true;
            q.push({novo, front.second + 1});
        }
        novo = front.first + u;
        if(novo <= f && !used[novo])
        {
            used[novo] = true;
            q.push({novo, front.second + 1});
        }
    }
    cout << "use the stairs\n";
}
